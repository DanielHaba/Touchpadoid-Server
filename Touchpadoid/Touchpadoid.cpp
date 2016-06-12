// Touchpadoid.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Touchpadoid.hpp"


#include "Log.hpp"
#include "LogStdStream.hpp"
#include "Server.hpp"
#include "TCPServer.hpp"
#include "UDPServer.hpp"
#include "CommandReader.hpp"


#include "ExitCommand.hpp"
#include "LogoutCommand.hpp"
#include "MouseMove.hpp"
#include "MouseClick.hpp"
#include "MouseWheel.hpp"



const int port = 13623;




void alert(const char *text)
{
	MessageBoxA(NULL, text, "Touchpadoid", MB_OK);
}

bool choice(const char *text)
{
	return MessageBoxA(NULL, text, "Touchpadoid", MB_YESNO) == IDYES;
}



int WINAPI WinMain(HINSTANCE instance, HINSTANCE prevInstance, LPSTR cmdLine, int show)
{
	ofstream file("log.txt");
	Log &log = LogStdStream(file);

	boost::asio::io_service service;
	Server &server = UDPServer(service, log);


	CommandReader reader(&server, log);
	
	reader.add(0, new ExitCommand());
	reader.add(1, new LogoutCommand());
	reader.add(2, new MouseMove());
	reader.add(3, new MouseClick());
	reader.add(4, new MouseWheel());



	try
	{
		while (true)
		{
			server.open(port);
			try
			{
				while (server.ready())
				{
					reader.next();
				}
			}
			catch (LogoutException e)
			{
				alert("Logout");
			}
			server.close();
		}
	}
	catch (ExitException e)
	{
		alert("Exit");
	}

	file.close();
	return 0;
}