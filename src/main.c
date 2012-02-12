/**
 * @file main.c
 *
 * Copyright (c) 2011 Pedro Aguilar
 *
 * @brief Entry functions that processes the command line and call 
 *		  the main parser funtion yyparse()
 *
 * This file is subject to the terms and conditions of the GNU General Public
 * License. See the file COPYING in the main directory of this archive for
 * more details.
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

#include <glib.h>

#include "parser.tab.h"
#include "xml.h"
#include "misc.h"
#include "config.h"

#ifdef __GNUC__
# ifdef YYPARSE_PARAM
extern int yyparse (void *); 
# else
extern int yyparse (void);
# endif
#endif

extern FILE      *yyin;

extern SC2XMLPtr xml_ptr;

GList  *my_list = NULL;

static gboolean stub_exists(gchar *filename)
{
	gchar 		*stubfile;
	struct stat stats;

	stubfile = g_new0(gchar, strlen(filename) + 6);
	sprintf(stubfile, "%s", filename);
	sprintf(stubfile + strlen(filename) - 2, ".stub.h");
	/*printf("%s(): stubfile: %s\n", __func__, stubfile);*/
	
	if (stat(stubfile, &stats) == -1) {
		return FALSE;
	}

	if (S_ISREG(stats.st_mode)) {
		/*printf("%s(): Skipping file %s because it has an stub file\n", __func__, filename);*/
		return TRUE;
	}

	printf("%s(): Me la pelo\n", __func__);
	return FALSE;
}

/**
 * @brief Renames a file with a name  *.gen.h.xml  to  *.h.xml
 * The former file was the output of parse_file() that received as input
 * a file *.gen.h
 * @param gen_name The file example.gen.h.xml
 */
static void rename_files(gchar *gen_name)
{
	gint	offset;
	gchar	*gen_xml_name,
			*xml_name;
	struct stat stats;

	/* Rename the file example.gen.h.xml to example.h.xml */
	gen_xml_name = g_new0(gchar, strlen(gen_name) + 10);
	sprintf(gen_xml_name, "%s.xml", gen_name);

	xml_name = g_new0(gchar, strlen(gen_name) + 10);
	sprintf(xml_name, "%s", gen_name);
	offset = strlen(gen_name) - 6;
	sprintf(xml_name + offset, ".h.xml");
	/*printf("%s(): final filename: '%s'\n", __func__, xml_name);*/
	rename(gen_xml_name, xml_name);

	/* Remove file *.gen.h.xml */
	if (stat(gen_xml_name, &stats) != -1) {
	unlink(gen_xml_name);
	g_free(gen_xml_name);
	}
}

/**
 * @brief Parse a file by calling yyparse()
 * @param filename File to parse
 * @return SC_OK if everything is ok, SC_FAIL otherwise
 */
SCResult parse_file(char *filename)
{
	SCResult rc;
	FILE *fd;

	rc = xml_file_create(filename);
	if (rc != SC_OK)
		return SC_FAIL; 

	fd = fopen(filename, "r");
	if (fd == NULL) {
		perror("fopen()");
		xml_file_close();
		return SC_FAIL;
	}

	log_error(LOG_INFO, "*** Parsing file %s ***\n", filename);

	yyin = fd;
	yyparse();

	fclose(fd);

	if (xml_ptr->struct_cnt) {
		log_error(LOG_ERR, "%s(): The parser could not recognize the token!",
			__func__);
		xml_file_close();
		return SC_FAIL;
	}

	rc = xml_file_close();
	if (rc != SC_OK)
		return SC_FAIL; 

	g_list_free(my_list);

	return SC_OK;
}

/**
 * @brief Call the C pre-processor for exanding the macros. The resulting file
 * with the expanded macro can then be parsed with the C grammar
 * @param stub_file The filename to be pre-processed
 * @param needle Used for naming the new pre-processed file
 * @return Then pre-processed filename
 */
gchar * preprocess_stub(gchar *stub_file, gchar *needle)
{
	pid_t	pid;
	gint	rc,
			status,
			offset;
	gchar	*gen_name,
			*commands[8];
	
	if (stub_file == NULL)
		return NULL;

	gen_name = g_new0(gchar, strlen(stub_file) + 1);
	sprintf(gen_name, "%s", stub_file);
	offset = strlen(stub_file) - 7;
	sprintf(gen_name + offset, ".gen.h");
	/*printf("%s(): gen filename: '%s'\n", __func__, gen_name);*/

	pid = vfork();
	if (pid == -1) {
		log_error(LOG_ERR, "Could not fork for pre-processing");
		g_free(gen_name);
		return NULL;
	}
	else if (pid == 0) {
		/* The child */
		commands[0] = "/usr/bin/gcc";
		commands[1] = "-I.";
		commands[2] = "-E";
		commands[3] = "-P";
		commands[4] = stub_file;
		commands[5] = "-o";
		commands[6] = gen_name;
		commands[7] = (char *)0;

		rc = execv("/usr/bin/gcc", commands);	
		if (rc == -1) {
			log_error(LOG_ERR, "Could not pre-process");
		}
		_exit(0);
	}
	else {
		/* The parent, wait for the children */
		wait(&status);
	}

	return gen_name;
}

/**
 * @brief If we have a list of files, parse them one at a time.
 *        If we have a directory, open it, read its contents and
 *        if we find a header file (*.h) call recursevely this function.
 * @param file_count The number of files to read
 * @param The files or directories names
 * @return SC_OK if everything is ok, SC_FAIL otherwise
 */
SCResult get_files(int file_count, char **files)
{
	int 		i;
	gchar		*gen_name = NULL,
				*needle;
	SCResult 	rc;
	struct stat stats;

	/*for (i = 0; i < file_count; i++)*/
	/*printf("file %d: %s\n", i, files[i]);*/

	for (i = 0; i < file_count; i++) {
		if (stat(files[i], &stats) == -1) {
			perror("stat()");
			log_error(LOG_ERR, "Skipping file '%s'", files[i]);
			continue;
		}

		if (S_ISREG(stats.st_mode)) {
			/* Process only files with extension '.h' */
			if (strstr(files[i], ".h") == NULL) {
				log_error(LOG_ERR, "Skipping file '%s'", files[i]);
				continue;
			}

			if ((needle = strstr(files[i], ".stub.h")) != NULL) {
				/* Pre-process file example.stub.h */
				if ((gen_name = preprocess_stub(files[i], needle)) == NULL) {
					log_error(LOG_ERR, "Could not pre-process file '%s'. Skipping...",
						files[i]);
					continue;
				}

				/* Parse the pre-processed file example.gen.h */
				rc = parse_file(gen_name);
				if (rc != SC_OK) {
					log_error(LOG_ERR, "%s(): Could not parse file '%s'. Skipping...", 
						__func__, files[i]);
					g_free(gen_name);
					continue;
				}

				rename_files(gen_name);

				/* Remove file *.gen.h */
				unlink(gen_name);
				g_free(gen_name);
			}
			else {
				if (stub_exists(files[i]) == TRUE)
					continue;

				/* Process normal files '.h' */
				rc = parse_file(files[i]);
				if (rc != SC_OK) {
					log_error(LOG_ERR, "%s(): Could not parse file '%s'. Skipping...", 
						__func__, files[i]);
				}
			}
		}
		else if (S_ISDIR(stats.st_mode)) {
			DIR	*dir;
			struct dirent *dp;
			char *entry;

			dir = opendir(files[i]);
			while ((dp = readdir(dir)) != NULL) {
				/* Process only files with extension '.h' */
				if ((strstr(dp->d_name, ".h") == NULL) || (strstr(dp->d_name, ".h.") != NULL))
					continue;
				entry = g_new0(char, strlen(files[i]) + strlen(dp->d_name) + 2);
				sprintf(entry, "%s/%s", files[i], dp->d_name);
				get_files(1, &entry);
				g_free(entry);
			}
			closedir(dir);
		}
	}

	return SC_OK;
}

void usage(char *prog_name)
{
	printf("Usage: %s <file0>|<dir0> [file1] ...\n", prog_name);
}

int main(int argc, char **argv) 
{
	if (argc < 2) {
		usage(argv[0]);
		return -1;
	}

	g_printf("\n%s\n\n", PACKAGE_STRING);

	if (get_files(argc - 1, &argv[1]) != SC_FAIL)
		return -1;

	return SC_OK;
}
