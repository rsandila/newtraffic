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

MThread::MThread(): TThread( true )
{
  ReturnValue=-1;
  installed=0;
  installed=1;
}

_fastcall MThread::~MThread()
{
}

int MThread::Start()
{
  if (Suspended) Resume();
  return( 0 );
}

void *MThread::Stop()
{
  Terminate();
  return( NULL );
}

int MThread::getStatus()
{
 if (Terminated) return( MTHREAD_STOPPED );
 if (Suspended) return( MTHREAD_UNDEFINED );
 return( MTHREAD_RUNNING );
}

void __fastcall MThread::Terminate(void)
{
 stopping=1;
 TThread::Terminate();
}

void __fastcall MThread::Execute(void)
{
 Run();
}

