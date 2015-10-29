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

void *MThread_helper( void *arg )
{
  MThread *me;

  me=(MThread *)arg;
  return( me->Run() );
}

MThread::MThread()
{
  stopping=0;
  global_result=-1;
  installed=0;
  status=MTHREAD_UNDEFINED;
  installed=1;
}

MThread::~MThread()
{
  Stop();
}

int MThread::Start()
{
  int result;
  if (status!=MTHREAD_UNDEFINED) return( -1 );
  result=pthread_create( &thread, NULL, MThread_helper, this );
  if (!result) status=MTHREAD_RUNNING;
  return( result );
}

void *MThread::Stop()
{
  if (!isOk()) return( NULL );
  if (status!=MTHREAD_RUNNING && status!=MTHREAD_STOPPING) return( NULL );
  status=MTHREAD_STOPPING;
  stopping+=1;
 
  int result;
  void *value;
  result=pthread_join( thread, &value );
  if (result) return( NULL );
  status=MTHREAD_STOPPED;
  return( value );  
}
