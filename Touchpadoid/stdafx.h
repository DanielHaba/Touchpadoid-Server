// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>


#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <list>
#include <map>

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <boost/system/config.hpp>
#include <boost/asio.hpp>
#include <boost/date_time.hpp>

using namespace std;



void hex_dump(ostream &output, const void *data, size_t size);




// TODO: reference additional headers your program requires here
