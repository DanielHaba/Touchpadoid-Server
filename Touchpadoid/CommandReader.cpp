#include "stdafx.h"
#include "CommandReader.hpp"



CommandReader::CommandReader(Stream *stream, unsigned bufferSize)
	:stream(stream), buffer(new unsigned char[bufferSize]), bufferSize(bufferSize), _log(nullptr)
{
	log("Create");

	memset(commands, 0, bufferSize);
	memset(buffer, 0, bufferSize);
}


CommandReader::CommandReader(Stream *stream, Log &l, unsigned bufferSize)
	:stream(stream), buffer(new unsigned char[bufferSize]), bufferSize(bufferSize), _log(&l)
{
	log("Create");

	memset(commands, 0, bufferSize);
	memset(buffer, 0, bufferSize);
}


CommandReader::~CommandReader()
{
	log("Destroy");

	for (int i = 0; i < 256; ++i)
	{
		if (commands[i] != nullptr)
			delete commands[i];
	}
	delete[] buffer;
}

void CommandReader::log(const string &message)
{
	if (_log != nullptr)
		_log->write("CommandReader", message);
}

bool CommandReader::has(unsigned char code) const
{
	return commands[code] != nullptr;
}

void CommandReader::add(unsigned char code, Command *command)
{
	if (!has(code))
	{
		stringstream stream;

		commands[code] = command;
		
		stream << "Registered Command [" << static_cast<unsigned int>(code) << "](" << command->name() << ")";
		log(stream.str());
	}
}

bool CommandReader::next()
{
	stringstream sstream;
	CommandHeader &header = *reinterpret_cast<CommandHeader*>(buffer);
	Command *command;

	log("Read");

	stream->read(reinterpret_cast<void*>(buffer), bufferSize);



	if (has(header.code) && header.index >= index)
	{

		command = commands[header.code];

		sstream << "Executing [" << static_cast<unsigned int>(header.code) << "](" << command->name() << ")";
		log(sstream.str());
		sstream.clear();




		if (command->load(buffer + sizeof(CommandHeader), header.size))
		{
			command->execute(0);
			index = header.index;
			log("Command executed");
		}
		else
		{
			log("Command error");
		}
	}
	else
	{
		sstream << "Command not found " << static_cast<unsigned int>(header.code);
		log(sstream.str());
		sstream.clear();
	}

	return true;
}

Command *CommandReader::get(unsigned char code)
{
	if (has(code))
	{
		return commands[code];
	}
	else
	{
		return nullptr;
	}
}