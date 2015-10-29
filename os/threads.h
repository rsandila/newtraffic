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
#ifndef __THREADS_H__
#define __THREADS_H__

#if defined(LINUX) || defined(__LINUX__) || defined(__linux__) || defined( __FreeBSD__ )
#include <pthread.h>
#else
#if defined(__WIN32__)
#include <vcl.h>
#else
#if defined _MSC_VER
// Do we need threads?
#else
#error Operating system not supported for threads
#endif
#endif
#endif

#define MTHREAD_UNDEFINED -1
#define MTHREAD_RUNNING 0
#define MTHREAD_STOPPING 1
#define MTHREAD_STOPPED 2

#if defined(__WIN32__)
class MThread: public TThread
{
 public:
  MThread();
  _fastcall virtual ~MThread();
  int isOk() { return( installed ); };
  int Start();
  void *Stop();
  int getResult() { return( ReturnValue ); };
  int getStatus();
  void __fastcall Terminate(void);
 protected:
  void __fastcall Execute(void);
  virtual void *Run()=0;

  int stopping;
 private:
  int installed;
};
#else
class MThread
{
 public:
  MThread();
  virtual ~MThread();
  int isOk() { return( installed ); };
  int Start();
  void *Stop();
  int getResult() { return( global_result ); };  
  int getStatus() { return( status ); };
 protected:
  int stopping;
  int global_result;
  int status;
#if defined(LINUX) || defined(__LINUX__) || defined(__linux__) || defined( __FreeBSD__ )
  pthread_t thread;

  friend void *MThread_helper( void *arg );
#endif
  virtual void *Run()=0;
 private:
  int installed;
};
#endif

#endif
