#pragma once
#include "Log.hpp"
#include "Stream.hpp"
#include "Command.hpp"
#include "CommandHeader.hpp"



class CommandReader
{
private:
	unsigned char *buffer;
	unsigned bufferSize;
	Command *commands[256];
	Stream *const stream;
	unsigned index;
	Log *_log;
	
protected:
	void log(const string &message);


public:
	CommandReader(Stream *stream, unsigned bufferSize = 256);
	CommandReader(Stream *stream, Log &log, unsigned bufferSize = 256);
	~CommandReader();


	bool has(unsigned char code) const;
	void add(unsigned char code, Command *command);
	Command *get(unsigned char code);
	

	bool next();
};