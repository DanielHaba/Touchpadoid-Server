#include "stdafx.h"
#include "LogoutCommand.hpp"



LogoutException::LogoutException()
	:runtime_error("LOGOUT")
{

}

string LogoutCommand::name() const
{
	return "Logout";
}


bool LogoutCommand::load(void *data, size_t size)
{
	return size == 0;
}

void LogoutCommand::execute(long time)
{
	throw LogoutException();
}