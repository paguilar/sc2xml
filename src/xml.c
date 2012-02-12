/**
 * @file xml.c
 *
 * @brief The functions defined here are called in the actions part
 *        of the parser (parser.y).
 *
 * Copyright (c) 2011 Pedro Aguilar
 *
 * This file is subject to the terms and conditions of the GNU General Public
 * License. See the file COPYING in the main directory of this archive for
 * more details.
 */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include <glib.h>

#include <libxml/encoding.h>
#include <libxml/xmlwriter.h>

#include "config.h"
#include "misc.h"
#include "xml.h"

#define MY_ENCODING "ISO-8859-1"		/**< Encoded XML text */

SC2XMLPtr   xml_ptr;

extern GList *my_list;

/** 
 * @brief Sets a flag that indicates if we have a struct or an union
 * @param id 0 if we have a struct, 1 if we have a union
 */
SCResult xml_struct_union_set(int id)
{
	if (id == 1) 	/* We have a union */
		xml_ptr->struct_union = 1;
	else 			/* Defaults to struct */
		xml_ptr->struct_union = 0;

	return SC_OK;
}

/**
 * @brief Set the start of the args of a function ptr
 */
SCResult xml_func_ptr_args_start()
{
	if (!xml_ptr->struct_cnt)
		return SC_OK;

	xml_ptr->func_ptr_args_start = g_list_last(my_list);
	debug_info("%s(): first arg: '%s'\n", __func__, 
		(char *)xml_ptr->func_ptr_args_start->data);

	return SC_OK;
}

/**
 * @brief Set the end of the args of a function ptr
 */
SCResult xml_func_ptr_args_end()
{
	if (!xml_ptr->struct_cnt)
		return SC_OK;

	xml_ptr->func_ptr_args_end = g_list_last(my_list);
	debug_info("%s(): last arg: '%s'\n", __func__, 
		(char *)xml_ptr->func_ptr_args_end->data);

	return SC_OK;
}

/**
 * @brief Indicate a function ptr
 * @return SC_OK
 */
SCResult xml_func_ptr_add()
{
	if (!xml_ptr->struct_cnt)
		return SC_OK;

	xml_ptr->func_ptr++;
	/* Substract the '*' that defined the func ptr */
	xml_ptr->pointer--;

	return SC_OK;
}

/**
 * @brief Indicate a function ptr
 * @return SC_OK
 */
SCResult xml_nested_st_attr_name()
{
	if (!xml_ptr->struct_cnt)
		return SC_OK;

	xml_ptr->nested_name++;

	return SC_OK;
}

/**
 * @brief Indicate a typedef
 * @return SC_OK
 */
SCResult xml_typedef_set()
{
	xml_ptr->type_def++;

	return SC_OK;
}

/**
 * @brief Get the size of an array (whatever it finds between 
 *        the square brackets).
 */
SCResult xml_array_size_add(int size_flag)
{
	GList 	*ptr, *ptr_start, *ptr_end;
	int		inside_array = 0, 
			size = 0;

	if (!xml_ptr->struct_cnt)
		return SC_OK;

	debug_info("%s(): list len: %d\n", __func__, g_list_length(my_list));

	/* If size_flag is zero, the array size was not specified */
	if (!size_flag) {
		debug_info("%s(): Array size: undefined\n", __func__);
		xml_ptr->size = g_new(char, 1);
		*(xml_ptr->size) = '\0';
		xml_ptr->size = xml_ptr->size;
		return SC_OK;
	}

	ptr = my_list;
	while (ptr) {
		if ((inside_array == 0) && (strcmp((char *)ptr->data, "["))) {
			ptr = ptr->next;
			continue;
		}
		else if ((inside_array == 0) && (!strcmp((char *)ptr->data, "["))) {
			inside_array = 1;
			ptr = ptr->next;
			ptr_start = ptr;
			continue;
		}

		if (!strcmp((char *)ptr->data, "]")) {
			ptr_end = ptr;
			break;
		}
		size += strlen((char *)ptr->data) + 1;
		ptr = ptr->next;
	}
	size++;

	debug_info("Size to allocate: %d\n", size);
	debug_info("start: %s, end: %s\n", (char *)ptr_start->data, (char *)ptr_end->data);

	xml_ptr->size = g_new(char, size);
	reset_buff(xml_ptr->size, size);

	for (ptr = ptr_start; ptr != ptr_end; ptr = ptr->next) {
		sprintf(xml_ptr->size, "%s%s ", xml_ptr->size, (char *)ptr->data);
		debug_info("%s(): SIZE: '%s'\n", __func__, xml_ptr->size);
	}

	*(xml_ptr->size + size - 2) = '\0';
	xml_ptr->size = xml_ptr->size;

	return SC_OK;
}

/**
 * @brief This function is called when a field has a user defined data type.
 *        Then, it will call xml_single_datatype_add() and xml_id_add()
 *        for getting the field's data type and the name, respectively.
 */
SCResult xml_user_datatype_add()
{
	GList 	*ptr = my_list;

	if (!xml_ptr->struct_cnt)
		return SC_OK;

	debug_info("%s(): list len: %d\n", __func__, g_list_length(ptr));

	if (g_list_length(ptr) == 1) {
		xml_ptr->type_specifier = g_new0(char, strlen((char *)ptr->data) + 1);
		sprintf(xml_ptr->type_specifier, "%s", (char *)ptr->data);
	}
	else {
		/* Hack for func ptrs that return a user-defined data type */
		while (ptr) {
			if (!strcmp((char *)ptr->data, "(")) {
				xml_single_datatype_add();
				return SC_OK;
			}
			ptr = ptr->next;
		}
		xml_single_datatype_add();
		xml_id_add();
	}

	return SC_OK;
}

/**
 * @brief Get the data type of the field when the GList does NOT have
 *        the field name as its last element.
 */
SCResult xml_datatype_add()
{
	GList 	*ptr = my_list;
	int 	size = 0;

	if (!xml_ptr->struct_cnt)
		return SC_OK;

	debug_info("%s(): data type: ", __func__);

	while (ptr) {
		debug_info("%s ", (char *)ptr->data);
		size += strlen((char *)ptr->data) + 1;
		ptr = ptr->next;
	}
	size++;
	/*putchar('\n');*/
	debug_info("");

	debug_info("Size to allocate: %d\n", size);

	xml_ptr->type_specifier = g_new0(char, size);

	ptr = my_list;
	while (ptr) {
		sprintf(xml_ptr->type_specifier, "%s%s ", xml_ptr->type_specifier, (char *)ptr->data);
		ptr = ptr->next;
	}

	*(xml_ptr->type_specifier + size - 2) = '\0';
	debug_info("%s(): TYPE: '%s'\n", __func__, xml_ptr->type_specifier);

	return SC_OK;
}

/**
 * @brief Get the data type of the field when the GList has 
 *        field name as its last element.
 */
SCResult xml_single_datatype_add()
{
	GList 	*ptr = my_list,
			*tmp;
	int 	size = 0;

	if (!xml_ptr->struct_cnt)
		return SC_OK;

	debug_info("%s(): data type: ", __func__);
	tmp = g_list_last(my_list);

	while (ptr) {
		debug_info("%s ", (char *)ptr->data);
		size += strlen((char *)ptr->data) + 1;
		ptr = ptr->next;
		if (tmp == ptr)
			break;
	}
	size++;
	/*putchar('\n');*/
	debug_info("");

	debug_info("Size to allocate: %d\n", size);

	xml_ptr->type_specifier = g_new0(char, size);

	ptr = my_list;
	while (ptr) {
		sprintf(xml_ptr->type_specifier, "%s%s ", xml_ptr->type_specifier, (char *)ptr->data);
		ptr = ptr->next;
		if (tmp == ptr)
			break;
	}

	*(xml_ptr->type_specifier + size - 2) = '\0';
	debug_info("%s(): TYPE: '%s'\n", __func__, xml_ptr->type_specifier);

	return SC_OK;
}

/**
 * @brief Indicate a ptr as a return parameter. 
 * 		  Discard ptrs as arguments of function ptrs
 * @return SC_OK
 */
SCResult xml_ptr_add()
{
	if (!xml_ptr->struct_cnt)
		return SC_OK;

	debug_info("%s(): Inside\n", __func__);
	if (!xml_ptr->func_ptr)
		xml_ptr->pointer++;

	return SC_OK;
}

/**
 * @brief Get the variable name (struct field) in struct xml_ptr_st.id
 * @return SC_OK
 */
SCResult xml_id_add()
{
	GList *ptr;

	if (!xml_ptr->struct_cnt)
		return SC_OK;

	if (xml_ptr->id)
		return SC_OK;

	ptr = g_list_last(my_list);
	debug_info("%s(): ID: '%s'\n", __func__, (char *)ptr->data);

	xml_ptr->id = (char *)ptr->data;

	return SC_OK;
}

/**
 * @brief Free the tokens allocated with strdup in the scanner
 * @param data Content of a GList element
 * @param user_data NULL
 */
static void free_tokens(gpointer data, gpointer user_data)
{
	g_free(data);
}

/**
 *
 */
SCResult xml_field_add()
{
	int rc = SC_FAIL;
	GList *ptr;
	int bits_field = 0;

	/*debug_info("%s(): Inside: xml_ptr->struct_cnt: %d\n", __func__, xml_ptr->struct_cnt);*/
	if (!xml_ptr->struct_cnt)
		return SC_OK;

	/*printf("%s(): %s\n", __func__, xml_ptr->type_specifier);*/
	if (xml_ptr->set_close) {
		xml_struct_close();
		goto clean;
	}

	/* Write 'field' element */
	rc = xmlTextWriterStartElement(xml_ptr->writer, (xmlChar *)"field");
    if (rc < 0) {
        log_error(LOG_ERR, "%s(): Could not add element 'field' to XML tree",
			__func__);
        goto clean;
    }

	/* Write 'type' attribute. 
	 * It could be a pointer (but not a function pointer) */
	/*if (xml_ptr->pointer && !xml_ptr->func_ptr) {*/
	if (xml_ptr->pointer) {
		int i;
		char *type_specifier = g_new(char, strlen(xml_ptr->type_specifier) + xml_ptr->pointer + 2);

		sprintf(type_specifier, "%s ", xml_ptr->type_specifier);
		for (i = 0; i < xml_ptr->pointer; i++)
			sprintf(type_specifier, "%s*", type_specifier);
		rc = xmlTextWriterWriteAttribute(xml_ptr->writer, 
			(xmlChar *)"type", (xmlChar *)type_specifier);
		g_free(type_specifier);
		g_free(xml_ptr->type_specifier); 
	}
	/* or a standard data type like 'int', 'char', ... */
	else {
		rc = xmlTextWriterWriteAttribute(xml_ptr->writer, 
			(xmlChar *)"type", (xmlChar *)xml_ptr->type_specifier);
		g_free(xml_ptr->type_specifier);
	}
	if (rc != SC_OK) {
		log_error(LOG_ERR, "%s(): Could not add attribute 'type'", __func__);
		goto clean;
	}

	/* Write 'bits' attribute if any */
	ptr = my_list;
	/*debug_info("%s(): list len: %d\n", __func__, g_list_length(ptr));*/
	while (ptr) {
		/*debug_info("%s -> ", (char *)ptr->data);*/
		if (!strcmp((char *)ptr->data, ":")) {
			bits_field = 1;
			break;
		}
		ptr = ptr->next;
	}
	/*putchar('\n');*/

	if (bits_field) {
		ptr = ptr->next;

		if (ptr) {
			rc = xmlTextWriterWriteAttribute(xml_ptr->writer, 
					(xmlChar *)"bits", (xmlChar *)ptr->data);
			if (rc != SC_OK) {
				log_error(LOG_ERR, "%s(): Could not add attribute 'bits': '%s'", 
					__func__, xml_ptr->bits);
				goto clean;
			}
		}
	}

	/* Write array size if any */
	if ((xml_ptr->size != NULL) && (!xml_ptr->func_ptr)) {
		/* The size was not specified */
		if (strlen(xml_ptr->size) == 0) {
			rc = xmlTextWriterWriteFormatAttribute(xml_ptr->writer, 
				(xmlChar *)"size", "N/A");
		}
		else {
			rc = xmlTextWriterWriteFormatAttribute(xml_ptr->writer, 
				(xmlChar *)"size", "%s", xml_ptr->size);
		}
		if (rc != SC_OK) {
			log_error(LOG_ERR, "%s(): Could not add attribute 'size': '%s'", 
				__func__, xml_ptr->bits);
			goto clean;
		}
	}

	/* Write function pointer if any */
	if (xml_ptr->func_ptr) {
		int size = 0;
		char *str;

		if (xml_ptr->func_ptr_args_start == NULL || xml_ptr->func_ptr_args_start == NULL) {
			log_error(LOG_ERR, "%s(): Could not add func ptr element", __func__);
			goto clean;
		}

		rc = xmlTextWriterWriteFormatAttribute(xml_ptr->writer, 
			(xmlChar *)"function_pointer", "1");
		if (rc != SC_OK) {
			log_error(LOG_ERR, "%s(): Could not add element 'function_pointer'", 
				__func__);
			goto clean;
		}

		if (xml_ptr->func_ptr_args_start == xml_ptr->func_ptr_args_end) {
			rc = xmlTextWriterWriteElement(xml_ptr->writer, 
					(xmlChar *)"input_args", (xmlChar *)"void");
			if (rc != SC_OK) {
				log_error(LOG_ERR, "%s(): Could not add element 'input_args': 'void'", 
					__func__);
				goto clean;
			}
		}	
		else {
			for (ptr = xml_ptr->func_ptr_args_start; 
				ptr != xml_ptr->func_ptr_args_end; 
				ptr = ptr->next) {
				size += strlen((char *)ptr->data) + 1;
			}
			size++;

			str = g_new(char, size);
			reset_buff(str, size);

			for (ptr = xml_ptr->func_ptr_args_start; 
				ptr != xml_ptr->func_ptr_args_end; 
				ptr = ptr->next) {
				sprintf(str, "%s%s ", str, (char *)ptr->data);
			}
			
			*(str + size - 2) = '\0';

			rc = xmlTextWriterWriteElement(xml_ptr->writer, 
					(xmlChar *)"input_args", (xmlChar *)str);
			if (rc != SC_OK) {
				log_error(LOG_ERR, "%s(): Could not add element 'input_args': '%s'", 
						__func__, str);
				goto clean;
			}
			g_free(str);
		}
	}

	rc = xmlTextWriterWriteElement(xml_ptr->writer, 
			(xmlChar *)"name", (xmlChar *)xml_ptr->id);
	if (rc != SC_OK) {
		log_error(LOG_ERR, "%s(): Could not add element 'name': '%s'", 
				__func__, xml_ptr->id);
		goto clean;
	}

	/* Close element 'field' */
    rc = xmlTextWriterEndElement(xml_ptr->writer);
    if (rc < 0) {
        log_error(LOG_ERR, "%s(): Could not close 'field' element", __func__);
        goto clean;
    }

	rc = SC_OK;

clean:
	debug_info("Line parsing finished...\n\n");
	g_list_foreach(my_list, free_tokens, NULL);
	/*g_list_free(my_list);*/

	xml_ptr->id = NULL;
	xml_ptr->type_specifier = NULL;
	xml_ptr->pointer = 0;
	g_free(xml_ptr->size);
	xml_ptr->size = NULL;
	xml_ptr->bits = 0;
	xml_ptr->func_ptr = 0;
	xml_ptr->func_ptr_args_start = NULL;
	xml_ptr->func_ptr_args_end = NULL;

	return rc;
}


SCResult xml_struct_close()
{
	int 		rc;
	GList 		*ptr;

	if (!xml_ptr->struct_cnt)
		return SC_OK;

	if (xml_ptr->set_close == 0)
		return SC_OK;

	/*debug_info("%s(): set_close = %d\n", __func__, xml_ptr->set_close);*/
	xml_ptr->set_close--;

	/* When closing a struct, the default case is '};'
	 * But we can have '} name_st;' due to typedefs or attributes */
	if (g_list_length(my_list) > 2) {
		gint size = 0;
		gint nested_name_size = 0;
		gint attr_end = 0;
		gchar *specifier;
		gchar *nested_name;
		GList *ptr_start, *ptr_end;

		ptr_start = g_list_nth(my_list, 1);
		ptr_end = g_list_last(my_list);

		for (ptr = ptr_start; ptr != ptr_end; ptr = ptr->next) {
			size += strlen((char *)ptr->data) + 1;
			/*debug_info("%s(): SIZE: '%d'\n", __func__, size);*/
		}
		size++;

		specifier = g_new(char, size);
		reset_buff(specifier, size);

		for (ptr = ptr_start; ptr != ptr_end; ptr = ptr->next) {
			if (xml_ptr->nested_name) {
				nested_name_size++;
				/*printf("%s(): data: %s\n", __func__, (char *)ptr->data);*/
				if (*(char *)ptr->data == ')') {
					/*if (*(char *)ptr->data == ')' && *(char *)(ptr->data + 1) == ')') {*/
					sprintf(specifier, "%s%s ", specifier, (char *)ptr->data);
					debug_info("%s(): ATTRIBUTE: '%s'\n", __func__, specifier);

					nested_name = g_new(char, size - nested_name_size + 1);
					reset_buff(nested_name, size - nested_name_size + 1);

					attr_end = 1;
					continue;
				}
				if (!attr_end) {
					sprintf(specifier, "%s%s ", specifier, (char *)ptr->data);
					debug_info("%s(): ATTRIBUTE: '%s'\n", __func__, specifier);
				}
				else {
					sprintf(nested_name, "%s%s ", nested_name, (char *)ptr->data);
					debug_info("%s(): NESTED NAME: '%s'\n", __func__, nested_name);
				}
			}
			else {
				sprintf(specifier, "%s%s ", specifier, (char *)ptr->data);
				debug_info("%s(): VALUE: '%s'\n", __func__, specifier);
			}
		}

		/* Remove the trailing ' ' */
		*(specifier + size - 2) = '\0';

		/* <typedef_name>  */
		if (xml_ptr->type_def > 0) {
			rc = xmlTextWriterWriteElement(xml_ptr->writer, 
					(xmlChar *)"typedef_name", (xmlChar *)specifier);
			xml_ptr->type_def--;
		}
		/* struct name is at the end: struct {}my_name; */
		else if (xml_ptr->struct_has_name) {
			rc = xmlTextWriterWriteElement(xml_ptr->writer, 
					(xmlChar *)"struct_name", (xmlChar *)specifier);
			xml_ptr->struct_has_name--;
		}
		/* or <struct_attributes> like '__attribute__' */
		else {
			if (xml_ptr->nested_name) {
				rc = xmlTextWriterWriteElement(xml_ptr->writer, 
					(xmlChar *)"struct_attributes", (xmlChar *)specifier);

				rc = xmlTextWriterWriteElement(xml_ptr->writer, 
					(xmlChar *)"struct_nested_name", (xmlChar *)nested_name);
				xml_ptr->nested_name--;
			}
			else {
				rc = xmlTextWriterWriteElement(xml_ptr->writer, 
					(xmlChar *)"struct_attributes", (xmlChar *)specifier);
			}
		}
		if (rc != SC_OK) {
			log_error(LOG_ERR, "%s(): Could not write struct name", __func__);
			return SC_FAIL;
		}
	}

	/* </struct> */
	rc = xmlTextWriterEndElement(xml_ptr->writer);
    if (rc < 0) {
        log_error(LOG_ERR, "%s(): Could not close <struct> XML node",
			__func__);
        return SC_FAIL;
    }

	xml_ptr->struct_cnt--;

	return SC_OK;
}

/**
 * @brief We just set a flag to ack that the parser already told us that the 
 *		struct is finished, but we actually close the tags in 
 *		xml_struct_close() that is called from xml_field_add()
 */
SCResult xml_struct_prepare_close()
{
	debug_info("%s(): Inside\n", __func__);
	if (xml_ptr->struct_cnt > 0) {
		xml_ptr->set_close++;
	}

	return SC_OK;
}

SCResult xml_struct_open()
{
	int rc, pos;
	GList *ptr;

	debug_info("%s(): Inside\n", __func__);
	xml_ptr->struct_cnt++;

	if (xml_ptr->struct_union == 0)
		rc = xmlTextWriterStartElement(xml_ptr->writer, (xmlChar *)"struct");
	else
		rc = xmlTextWriterStartElement(xml_ptr->writer, (xmlChar *)"union");
    if (rc < 0) {
        log_error(LOG_ERR, "%s(): Error at xmlTextWriterStartElement",
			__func__);
        return SC_FAIL;
    }

	pos = g_list_length(my_list) - 2;
	ptr = g_list_nth(my_list, pos);

	/* Write 'struct_name' element if data is not 'struct'/'union' itself. 
     * It can happen with typedefs */
	if (strcmp((char *)ptr->data, "struct") && strcmp((char *)ptr->data, "union")) {
		rc = xmlTextWriterWriteElement(xml_ptr->writer, 
				(xmlChar *)"struct_name", (xmlChar *)ptr->data);
		if (rc != SC_OK) {
			log_error(LOG_ERR, "%s(): Could not write struct name", __func__);
			return SC_FAIL;
		}
	}
	else {
		xml_ptr->struct_has_name++;
	}

	g_list_free(my_list);
	my_list = NULL;

	return SC_OK;
}

SCResult xml_file_close(void)
{
	int rc;

	rc = xmlTextWriterEndDocument(xml_ptr->writer);
    if (rc < 0) {
        log_error(LOG_ERR, "%s(): Error at xmlTextWriterEndDocument", __func__);
        return SC_FAIL;
    }

    xmlFreeTextWriter(xml_ptr->writer);

	g_free(xml_ptr);

	return SC_OK;
}

/**
 * @brief Create the XML file with the XML document header and encoding
 * @param filename File being parsed.
 * @return SC_OK if everything is ok, SC_FAIL otherwise
 */
SCResult xml_file_create(char *filename)
{
	int rc;
	char xml_filename[NAME_SIZE + 4];

	xml_ptr = g_new0(struct xml_ptr_st, 1);

	sprintf(xml_filename, "%s.xml", filename);

	/* Create a new XmlWriter with no compression. */
	xml_ptr->writer = xmlNewTextWriterFilename((const char *)xml_filename, 0);
	if (xml_ptr->writer == NULL) {
		log_error(LOG_ERR, "%s(): Error creating the xml file '%s' ",
			__func__, xml_filename);
		return SC_FAIL;
	}

	/* Start the document with the XML default version ("1.0") */
    rc = xmlTextWriterStartDocument(xml_ptr->writer, NULL, MY_ENCODING, NULL);
    if (rc < 0) {
        log_error(LOG_ERR, "%s(): Error at xmlTextWriterStartDocument",
			__func__);
        return SC_FAIL;
    }

	/* This is the root element */
    rc = xmlTextWriterStartElement(xml_ptr->writer, (xmlChar *)"sc2xml");
    if (rc < 0) {
        log_error(LOG_ERR, "%s(): Error at xmlTextWriterStartElement\n",
			__func__);
        return SC_FAIL;
    }

	return SC_OK;
}

