/*
 * @file xml.h
 *
 * @brief Declare the funcions used in the parser (parser.y).
 *        The main struct xml_ptr_st takes account of the elements of a
 *        line of code.
 *
 * Copyright (c) 2011 Pedro Aguilar
 *
 * This file is subject to the terms and conditions of the GNU General Public
 * License. See the file COPYING in the main directory of this archive for
 * more details.
 */

#include <stdio.h>
#include <unistd.h>

#include <glib.h>

#include <libxml/xmlwriter.h>

#include "sc2xml.h"

typedef struct xml_ptr_st * SC2XMLPtr;

struct xml_ptr_st {
	xmlTextWriterPtr writer;	/**< A ptr to an XML writer struct */
	int struct_cnt;				/**< Add/Substract each time we enter/exit an struct */
	int set_close;				/**< Flag to indicate the end of the struct/union */
	int struct_union;			/**< Indicates struct or union */
	int struct_has_name;		/**< struct name is at the end */
	char *id;					/**< Variable name */
	char *type_specifier;		/**< void, char, int, ... */
	int pointer;				/**< char *, int *, ...  */
	char *size;					/**< Array size */
	int bits;					/**< Bit size */
	int type_def;				/**< typedef'ed struct */
	int func_ptr;				/**< Function ptr */
	int nested_name;			/**< Name of nested struct with possible attributes */
	GList *func_ptr_args_start;	/**< Ptr where the func ptr args start */
	GList *func_ptr_args_end;	/**< Ptr where the func ptr args end */
};

SCResult xml_storage_class_specifier_add(void);
SCResult xml_struct_union_set(int);
SCResult xml_func_ptr_args_start();
SCResult xml_func_ptr_args_end();
SCResult xml_func_ptr_add();
SCResult xml_nested_st_attr_name(void);
SCResult xml_typedef_set(void);
SCResult xml_array_size_add(int);
SCResult xml_user_datatype_add(void);
SCResult xml_datatype_add(void);
SCResult xml_single_datatype_add(void);
SCResult xml_ptr_add(void);
SCResult xml_id_add(void);
SCResult xml_field_add(void);
SCResult xml_struct_prepare_close(void);
SCResult xml_struct_close(void);
SCResult xml_struct_open(void);
SCResult xml_file_close(void);
SCResult xml_file_create(char *);

