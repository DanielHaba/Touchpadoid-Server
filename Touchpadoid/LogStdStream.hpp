#pragma once
#include "Log.hpp"


class LogStdStream : public Log
{
private:
	ostream &stream;

public:
	LogStdStream(ostream &stream);
	virtual ~LogStdStream();


	virtual void open() override;
	virtual void write(const string &provider, const string &text) override;
	virtual void close() override;
};