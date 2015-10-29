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
#ifndef __PAYLOAD_H__
#define __PAYLOAD_H__

/*
  Payload structure. The minimum size for a payload is 8 bytes. The rest of the payload is undefined.

  struct payload_header
  {
    char head[4]="TRAF";
    unsigned int size;
  };

  size is in network byte order and is an 32-bit unsigned integer. This provides the total payload size including the header.
 */

/*
  This initializes the payload. Returns void * to be used as handle.

  min - Minimum size
  max - Maximum size
  increment - If there is an increment base it on this
  time - Time factor for calculations
  other - Implementation specific pointer - please do not use
 */
extern "C" void *InitializePayload( unsigned min, unsigned max, unsigned increment, unsigned time, void *other );

/*
  This destroys the payload
 */
extern "C" void DestroyPayload( void *handle );

/*
  Get payload to be sent

  Returns a "char *" buffer as payload, already filled with junk.
  Returns total size in the "size" pointer.

  Must be freed by calling ReleasePayload.
 */
extern "C" char *GetPayload( void *handle, unsigned *size );

/*
  This releases the payload as created by GetPayload.
 */
extern "C" void ReleasePayload( void *handle, char *payload );

/*
  This resets the payload sequence so that it starts from scratch
 */
extern "C" void ResetPayloadSequence( void *handle );

#endif
