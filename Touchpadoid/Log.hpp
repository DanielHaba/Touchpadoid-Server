#pragma once


struct Log
{
	virtual ~Log() = default;

	virtual void open() = 0;
	virtual void write(const string &provider, const string &text) = 0;
	virtual void close() = 0;
};