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
#include <windows.h>
#include <winsock.h>

void InitNetwork()
{
 WORD wVersionRequested;
 WSADATA wsaData;

 wVersionRequested = MAKEWORD( 1, 1 );
 WSAStartup( wVersionRequested, &wsaData );
}

void ShutdownNetwork()
{
 WSACleanup();
}

int TranslateInetString( char *str, void *dest, int dest_len )
{
 if (!str || !dest || dest_len<=0) return( -1 );
 memset( dest, 0, dest_len );
 if (!strcmp( str, "0.0.0.0" )) return( 0 );

 struct hostent *tmphe;
 tmphe=gethostbyaddr( str, strlen( str ), AF_INET  );
 if (!tmphe)
  { // It was not a x.y.z.a address...
   tmphe=gethostbyname( str );
   if (!tmphe) return( -1 ); // We can not do anything about this name
  }
 memcpy( dest, tmphe->h_addr_list[0], dest_len );
 return( 0 );
}


