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
#ifndef __SERVER_CONFIG_H__
#define __SERVER_CONFIG_H__

class server_config
{
 public:
  server_config( int argc, char **argv );
  virtual ~server_config();
  int isOk() { return( installed ); };
  int isVersion() { return( is_version ); };
  const char *help();
  char *getErrorString() { return( error_string ); };
  char *getReplyLibraryPath() { return( reply_library_path ); };
  char *getServerLibraryPath() { return( server_library_path ); };
  int getNumProtocols() { return( num_proto ); };
  char *getProtocolLibraryPath( unsigned index );
  unsigned getProtocolLocalPort( unsigned index );
  char *getProtocolLocalAddress( unsigned index ) { return( "0.0.0.0" ); };
  char *getProtocolRemoteAddress( unsigned index ) { return( "0.0.0.0" ); };
  unsigned getProtocolRemotePort( unsigned index ) { return( 0 ); };
 protected:
  char *reply_library_path;
  char *server_library_path;
  int num_proto;
  char **protocol_name;
  unsigned *protocol_port;
  char *error_string;
  int is_version;

  void set_error( char *str );
 private:
  int installed;
};
#endif
