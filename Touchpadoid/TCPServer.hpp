#pragma once
#include "Log.hpp"
#include "Server.hpp"



class TCPServer : public Server
{
private:
	boost::asio::io_service &service;
	boost::asio::ip::tcp::socket socket;

public:
	TCPServer(boost::asio::io_service &service);
	TCPServer(boost::asio::io_service &service, Log &log);
	virtual ~TCPServer();

	virtual void open(unsigned short port) override;
	virtual void close() override;

	virtual bool ready() const override;
	virtual void write(const void *data, size_t size) override;
	virtual void read(void *data, size_t size) override;
};