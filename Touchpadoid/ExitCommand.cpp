#include "stdafx.h"
#include "ExitCommand.hpp"



ExitException::ExitException()
	:runtime_error("EXIT")
{

}

string ExitCommand::name() const
{
	return "Exit";
}


bool ExitCommand::load(void *data, size_t size)
{
	return size == 0;
}

void ExitCommand::execute(long time)
{
	throw ExitException();
}