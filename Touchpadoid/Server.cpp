#include "stdafx.h"
#include "Server.hpp"


Server::Server(const string &name)
	: _log(nullptr), _name(name)
{

}

Server::Server(Log &log, const string &name)
	: _log(&log), _name(name)
{

}

void Server::log(const string &message)
{
	if (_log)
		_log->write(_name, message);
}
