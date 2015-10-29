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
#ifndef __CLIENT_CONFIG_H__
#define __CLIENT_CONFIG_H__

class config_info
{
 public:
  config_info( int argc, char **argv );
  virtual ~config_info();
  int isOk() { return( installed ); };
  int isVersion() { return( is_version ); };
  const char *help();
  int getNumClients() { return( num_clients ); };
  char *getProtocolLibraryPath() { return( protocol_lib_path ); };
  char *getClientLibraryPath() { return( client_lib_path ); };
  char *getPayloadLibraryPath() { return( payload_lib_path ); };
  int getClientMinimum() { return( client_min ); };
  int getClientMaximum() { return( client_max ); };
  int getClientIncrement() { return( client_inc ); };
  int getClientTime() { return( client_time ); };
  int getPayloadMinimum() { return( payload_min ); };
  int getPayloadMaximum() { return( payload_max ); };
  int getPayloadIncrement() { return( payload_inc ); };
  int getPayloadTime() { return( payload_time ); };
  int getProtocolDestinationPort() { return( protocol_dest_port ); };
  char *getProtocolDestinationAddress() { return( protocol_dest_address ); };
  int getProtocolSourcePort() { return( 0 ); };
  char *getProtocolSourceAddress() { return( "0.0.0.0" ); };
  char *getErrorString() { return( error_string ); };
 protected:
  int num_clients;
  char *protocol_lib_path;
  char *client_lib_path;
  char *payload_lib_path;
  int client_min, client_max, client_inc, client_time;
  int payload_min, payload_max, payload_inc, payload_time;
  int protocol_dest_port;
  char *protocol_dest_address;
  char *error_string;
  int is_version;

  void set_error( char *str );
  int parse_client_data( int cnt, int argc, char **argv, int *cn );
  int parse_protocol_data( int cnt, int argc, char **argv, int *dn );
  int parse_payload_data( int cnt, int argc, char **argv, int *pn );
 private:
  int installed;
};

#endif
