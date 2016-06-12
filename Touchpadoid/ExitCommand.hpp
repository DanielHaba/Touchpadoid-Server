#pragma once
#include "Command.hpp"


class ExitException : runtime_error
{
public:
	ExitException();
	virtual ~ExitException() = default;
};



class ExitCommand : public Command
{
public:
	ExitCommand() = default;
	virtual ~ExitCommand() = default;
	
	virtual bool load(void *data, size_t size) override;
	virtual void execute(long time) override;
	virtual string name() const override;
};