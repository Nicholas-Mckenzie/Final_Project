#pragma once

#include <wx/log.h>


#ifdef _DEBUG
	#define LOG(x) wxLogDebug(x)
#else
	#define LOG(x)
#endif
