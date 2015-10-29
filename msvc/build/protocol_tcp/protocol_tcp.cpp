// protocol_tcp.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include "protocol_tcp.h"
BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
    return TRUE;
}

// This is an example of an exported variable
PROTOCOL_TCP_API int nprotocol_tcp=0;

// This is an example of an exported function.
PROTOCOL_TCP_API int fnprotocol_tcp(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see protocol_tcp.h for the class definition
Cprotocol_tcp::Cprotocol_tcp()
{ 
	return; 
}
