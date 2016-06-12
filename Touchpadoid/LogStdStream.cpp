#include "stdafx.h"
#include "LogStdStream.hpp"

#include <ctime>
#include <iomanip>


using namespace boost::posix_time;



LogStdStream::LogStdStream(ostream &stream)
	:stream(stream)
{

}


LogStdStream::~LogStdStream()
{

}




void LogStdStream::open()
{

}


void LogStdStream::write(const string &provider, const string &text)
{
	ptime now = second_clock::local_time();
	time_duration time = now.time_of_day();

	stream << "[" << time.hours() << ":" << time.minutes() << ":" << time.seconds() << "][" << provider << "]:" << text << endl;
}


void LogStdStream::close()
{

}

