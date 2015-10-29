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
#ifndef __CONFIG_H__
#define __CONFIG_H__

/* Define if you have <sys/wait.h> that is POSIX.1 compatible.  */
#undef HAVE_SYS_WAIT_H

/* Define if you need to in order for stat and other things to work.  */
#define _POSIX_SOURCE 1

/* Define if you have the ANSI C header files.  */
#define STDC_HEADERS 1

/* The number of bytes in a char.  */
#define SIZEOF_CHAR 1

/* The number of bytes in a long unsigned.  */
#define SIZEOF_LONG_UNSIGNED 4

/* The number of bytes in a short unsigned.  */
#define SIZEOF_SHORT_UNSIGNED 2

/* The number of bytes in a unsigned.  */
#define SIZEOF_UNSIGNED 2

/* Define if you have the <arpa/inet.h> header file.  */
#undef HAVE_ARPA_INET_H

/* Define if you have the <memory.h> header file.  */
#define HAVE_MEMORY_H 1

/* Define if you have the <netdb.h> header file.  */
#undef HAVE_NETDB_H

/* Define if you have the <netinet/in.h> header file.  */
#undef HAVE_NETINET_IN_H

/* Define if you have the <sys/poll.h> header file.  */
#undef HAVE_SYS_POLL_H

/* Define if you have the <sys/socket.h> header file.  */
#undef HAVE_SYS_SOCKET_H

/* Define if you have the <sys/types.h> header file.  */
#undef HAVE_SYS_TYPES_H

/* Define if you have the <unistd.h> header file.  */
#undef HAVE_UNISTD_H

#if STDC_HEADERS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#else
#error You require the standard headers
#endif

#if HAVE_UNISTD_H
#include <unistd.h>
#endif

#include "mytypes.h"

#if defined(__WIN32__) || defined(_MSC_VER)
#include <winsock2.h>
#include <windows.h>
#include <io.h>
#endif

#endif
