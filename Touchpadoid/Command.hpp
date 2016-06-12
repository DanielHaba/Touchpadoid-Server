#pragma once



struct Command
{
	virtual ~Command() = default;

	virtual string name() const = 0;
	virtual void execute(long time) = 0;
	virtual bool load(void *data, size_t size) = 0;
};