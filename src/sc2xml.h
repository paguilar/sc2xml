/*
 * @file sc2xml.h
 *
 * @brief
 *
 *
 * Copyright (c) 2011 Pedro Aguilar
 *
 * This file is subject to the terms and conditions of the GNU General Public
 * License. See the file COPYING in the main directory of this archive for
 * more details.
 */

#ifndef _SC2XML_H
#define _SC2XML_H

#define ENABLE_LOGS

#ifdef ENABLE_LOGS
	#define SC2XML_LOG_FILE "sc2xml.log"	/**< Log's filename */
	#define LOG_BUFF		1024			/**< Log's buffer size */
	#define FD_OUT			stdout			/**< Output stream */
#endif

#define NAME_SIZE		256					/**< Default buffer size */

/* Operations result status */
typedef enum {
	SC_OK = 0,		/**< Operation successful */
	SC_FAIL = 1		/**< Operation failed */
} SCResult;

#endif /* _SC2XML_H */
