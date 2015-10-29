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
#include "../../config.h"
#include <windows.h>

/*
 This will import a .so/.dll file dynamically with the path libname.
 */
void *import_dynamic_library( char *libname )
{
  return( LoadLibrary( libname ) );
}

/*
  This will import a function in the .so/.dll file dynamically with the symbol name
 */
void *import_dynamic_symbol( void *handle, char *symbol_name )
{
  return( GetProcAddress( (HMODULE)handle, symbol_name ) );
}

/*
  This will stop the dynamic library and free it from memory
 */
int close_dynamic_library( void *handle )
{
  return( FreeLibrary( (HMODULE)handle ) );
}


