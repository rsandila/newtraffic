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
#include <stdlib.h>
#include <stdio.h>
#include "os.h"

class MyThread: public MThread
{
public:
  MyThread( int val );
protected:
  int val;

  void *Run();
};

MyThread::MyThread( int v ) : MThread()
{
  val=v;
}

void *MyThread::Run()
{
  while (!stopping)
    {
      printf( "Thread %d running.\n", val );
    };
  return( NULL );
}

int main()
{
  MyThread M( 1 );
  MyThread N( 2 );
  M.Start();
  N.Start();
  getchar();
  M.Stop();
  N.Stop();
  return( 0 );
}
