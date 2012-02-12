/**
 * @file misc.h
 *
 * @brief Defines for misc.c
 *
 * Copyright (c) 2011 Pedro Aguilar
 *
 * This file is subject to the terms and conditions of the GNU General Public
 * License. See the file COPYING in the main directory of this archive for
 * more details.
 */

#ifndef _MISC_H
#define _MISC_H

typedef enum {
    LOG_FATAL,
    LOG_ERR,
    LOG_WARN,
    LOG_INFO
} SCLogs;

void	log_error(SCLogs, char *, ...);
void	reset_buff(char *, int);
void	debug_info(const char *, ...);

#endif	/* _MISC_H */
