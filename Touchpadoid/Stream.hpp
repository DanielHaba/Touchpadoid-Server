#pragma once



struct Stream
{
	virtual ~Stream() = default;

	virtual bool ready() const = 0;
	virtual void write(const void *data, size_t size) = 0;
	virtual void read(void *data, size_t size) = 0;
};