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
#include "os.h"

#if defined(LINUX) || defined(__LINUX__) || defined(__linux__)
#include "linux/dlfunc.cpp"
#include "linux/threads.cpp"
#include "linux/network.cpp"
#include "linux/libpath.cpp"
#else
#if defined(__FreeBSD__)
#include "linux/dlfunc.cpp"
#include "freebsd/threads.cpp"
#include "linux/network.cpp"
#include "linux/libpath.cpp"
#else
#if defined(__WIN32__) || defined(_MSC_VER)
#include "windows/dlfunc.cpp"
#if ! defined _MSC_VER
#include "windows/threads.cpp"
#endif
#include "windows/network.cpp"
#include "windows/libpath.cpp"
#else
#error This operating system is not defined
#endif
#endif
#endif
