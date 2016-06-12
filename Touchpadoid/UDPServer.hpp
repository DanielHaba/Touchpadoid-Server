#pragma once
#include "Log.hpp"
#include "Server.hpp"



class UDPServer : public Server
{
private:
	boost::asio::io_service &service;
	boost::asio::ip::udp::socket socket;
	unsigned short port;

public:
	UDPServer(boost::asio::io_service &service);
	UDPServer(boost::asio::io_service &service, Log &log);
	virtual ~UDPServer();

	virtual void open(unsigned short port) override;
	virtual void close() override;

	virtual bool ready() const override;
	virtual void write(const void *data, size_t size) override;
	virtual void read(void *data, size_t size) override;
};