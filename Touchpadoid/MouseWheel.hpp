#pragma once
#include "Command.hpp"



class MouseWheel : public Command
{
private:
	int delta;

public:
	MouseWheel() = default;
	virtual ~MouseWheel() = default;

	virtual bool load(void *data, size_t size) override;
	virtual void execute(long time) override;
	virtual string name() const override;
};