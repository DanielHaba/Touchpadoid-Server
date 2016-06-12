#pragma once
#include "Stream.hpp"
#include "Log.hpp"


struct Server : public Stream
{
private:
	Log *const _log;
	const string _name;

protected:
	void log(const string &message);

public:
	Server(const string &name = "Server");
	Server(Log &log, const string &name = "Server");

	virtual ~Server() = default;

	virtual void open(unsigned short port) = 0;
	virtual void close() = 0;
};