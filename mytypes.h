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
#ifndef __MYTYPES_H__
#define __MYTYPES_H__

/* We want to have a 32-bit unsigned integer type */
//#define UINT32 unsigned long

/* 64 bit int  - already defined in Windows */
//#define LONGLONG __int64

/* Windows does not know of socklen_t */
#define socklen_t int

/* Product Name */
#define PRODUCT_NAME "traffic"

/* Product Version */
#define PRODUCT_VERSION "0.1.2"

#if defined (_MSC_VER)
#define EXPORT
#else
#define EXPORT  WINAPI __export
#endif

/* Shutdown flag Windows does not understand */
#define SHUT_RDWR SD_BOTH

#endif
