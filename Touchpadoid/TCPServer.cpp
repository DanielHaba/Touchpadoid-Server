#include "stdafx.h"
#include "TCPServer.hpp"

using boost::asio::ip::tcp;


TCPServer::TCPServer(boost::asio::io_service &service)
	: Server("TCPServer"), service(service), socket(service)
{
	log("Create");
}

TCPServer::TCPServer(boost::asio::io_service &service, Log &logger)
	: Server(logger, "TCPServer"), service(service), socket(service)
{
	log("Create");
}


TCPServer::~TCPServer()
{
	log("Destroy");
}




void TCPServer::open(unsigned short port)
{
	if (!ready())
	{
		tcp::acceptor acceptor(service, tcp::endpoint(tcp::v4(), port));


		log("Accept");
		acceptor.accept(socket);
		log("Open");
	}
}

void TCPServer::close()
{
	if (ready())
	{
		log("Close");
		socket.close();
	}
}

bool TCPServer::ready() const
{
	return socket.is_open();
}

void TCPServer::write(const void *data, size_t size)
{
	if (ready())
	{
		stringstream stream;

		boost::asio::write(socket, boost::asio::buffer(data, size));


		stream << "Sent " << size << "bytes" << endl;
		hex_dump(stream, data, size);
		
		log(stream.str());
	}
}


void TCPServer::read(void *data, size_t size)
{
	if (ready())
	{
		stringstream stream;

		boost::asio::read(socket, boost::asio::buffer(data, size));


		stream << "Received " << size << "bytes" << endl;
		hex_dump(stream, data, size);

		log(stream.str());
	}
}