#pragma once
#include "Command.hpp"


class LogoutException : runtime_error
{
public:
	LogoutException();
	virtual ~LogoutException() = default;
};



class LogoutCommand : public Command
{
public:
	LogoutCommand() = default;
	virtual ~LogoutCommand() = default;

	virtual bool load(void *data, size_t size) override;
	virtual void execute(long time) override;
	virtual string name() const override;
};