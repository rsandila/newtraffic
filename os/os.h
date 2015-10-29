/*
 * Copyright (C) 2003 Robert Sandilands (Pty) Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307,
USA.
 */
#ifndef __OS_H__
#define __OS_H__

/*
  This is all the OS dependant functionality... As far as possible...
 */

/*
  All the stuff needed for loading DLL's or .so's from different spots
 */
#if defined(__WIN32__)
#define DLL_EXT ".dll"
#else
#define DLL_EXT ".so"
#endif

/* This will set the path to search for .dll or .so */
char *set_library_path( int argc, char **argv, int pos, int lib_pos, char *prefix, char *err_msg, int err_len );

/*
 This will import a .so/.dll file dynamically with the path libname.
 */
void *import_dynamic_library( char *libname );

/*
  This will import a function in the .so/.dll file dynamically with the symbol name
 */
void *import_dynamic_symbol( void *handle, char *symbol_name );

/*
  This will stop the dynamic library and free it from memory
 */
int close_dynamic_library( void *handle );

/* 
  Thread class
 */

#include "threads.h"

/*
 Network initialization
 */
void InitNetwork();

void ShutdownNetwork();

int TranslateInetString( char *str, void *dest, int dest_len );

#endif
