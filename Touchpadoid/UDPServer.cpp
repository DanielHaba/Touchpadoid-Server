#include "stdafx.h"
#include "UDPServer.hpp"

#include "stdafx.h"
#include "TCPServer.hpp"

using boost::asio::ip::udp;


UDPServer::UDPServer(boost::asio::io_service &service)
	: Server("UDPServer"), service(service), socket(service), port(0)
{
	log("Create");
}

UDPServer::UDPServer(boost::asio::io_service &service, Log &logger)
	: Server(logger, "UDPServer"), service(service), socket(service), port(0)
{
	log("Create");
}


UDPServer::~UDPServer()
{
	log("Destroy");
}




void UDPServer::open(unsigned short port)
{
	if (!ready())
	{

		socket.open(udp::v4());
		socket.bind(udp::endpoint(udp::v4(), port));
		this->port = port;

		log("Open");
	}
}

void UDPServer::close()
{
	if (ready())
	{
		socket.shutdown(udp::socket::shutdown_both);
		socket.close();

		log("Close");
	}
}

bool UDPServer::ready() const
{
	return socket.is_open();
}

void UDPServer::write(const void *data, size_t size)
{
	return;

	if (ready() && size > 0)
	{
		stringstream stream;
		udp::endpoint to(boost::asio::ip::address_v4::broadcast(), 13620);

		socket.send_to(boost::asio::buffer(data, size), to);


		stream << "Sent " << size << "bytes" << endl;
		hex_dump(stream, data, size);

		log(stream.str());
	}
}


void UDPServer::read(void *data, size_t size)
{
	if (ready() && size > 0)
	{
		stringstream stream;
		udp::endpoint from;
		size_t readed;

		readed = socket.receive_from(boost::asio::buffer(data, size), from);


		stream << "Received " << readed << "bytes" << endl;
		hex_dump(stream, data, readed);

		log(stream.str());
	}
}