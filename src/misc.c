/**
 * @file misc.c
 *
 * Copyright (c) 2011 Pedro Aguilar
 *
 * @brief Contains all the utility functions used around the
 *     project like error logging and debugging.
 *
 * This file is subject to the terms and conditions of the GNU General Public
 * License. See the file COPYING in the main directory of this archive for
 * more details.
 */

#include <stdio.h>
#include <stdarg.h>

#include <glib.h>

#include "config.h"
#include "sc2xml.h"
#include "misc.h"

#ifdef ENABLE_LOGS
#include <sys/stat.h>
#include <dirent.h>
#endif

/**
 * @brief Fill a char buffer with '\0'
 * @param buff The buffer to be cleared
 * @param size The size of the buffer
 */
void reset_buff(char *buff, int size) 
{
    int i;

    for (i = 0; i < size; i++)
        buff[i] = '\0';
}

/**
 * @brief Prints the log msgs to a log file and stdout using a specific format.
 */
#ifdef ENABLE_LOGS
void log_error(SCLogs level, char *fmt, ...) 
{
	/*FILE     *fd;*/
    char     msg_buff[LOG_BUFF + 128],
             va_buff[LOG_BUFF];
    va_list  ap;
	/*char     filename[NAME_SIZE];*/

	/*sprintf(filename, "%.200s/%.200s/%.50s", SYSCONFDIR, PACKAGE, SC2XML_LOG_FILE);*/
	/*if ((fd = fopen(filename, "a")) == NULL) {*/
	/*fprintf(stderr, "%s: Couldn't open file '%s' for logging\n", */
	/*msg_buff, filename);*/
	/*return;*/
	/*}*/

	switch (level) {
		case LOG_ERR:
    		sprintf(msg_buff, "ERROR: ");
			break;
		case LOG_WARN:
    		sprintf(msg_buff, "WARNING: ");
			break;
		case LOG_FATAL:
    		sprintf(msg_buff, "FATAL: ");
			break;
		case LOG_INFO:
		default:
    		sprintf(msg_buff, "INFO: ");
			break;
	}

    /* Insert msg to buffer */
    if (fmt) {
        va_start(ap, fmt);
        vsnprintf(va_buff, sizeof(va_buff), fmt, ap);
        va_end(ap);
        sprintf(msg_buff, "%s%s\n", msg_buff, va_buff);
    }
    else
        sprintf(msg_buff, "%s: Unespecified error ocurred\n", msg_buff);

	/*fprintf(fd, "%s", msg_buff);*/
	/*fclose(fd);*/
	fprintf(FD_OUT, "%s\n", msg_buff);
}
#else
void log_error(SCLogs level, char *fmt, ...) 
{
}
#endif /* ENABLE_LOGS */

#ifdef DEBUG_INFO
void debug_info(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	vfprintf(stderr, format, args);
	va_end(args);
}
#else
void debug_info(const char *format, ...) { }
#endif    /* DEBUG_INFO */

