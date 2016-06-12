#pragma once
#include "Command.hpp"


class MouseMove : public Command
{
protected:
	float moveX;
	float moveY;

public:
	MouseMove() = default;
	virtual ~MouseMove() = default;



	virtual void execute(long time) override;
	virtual bool load(void *data, size_t size) override;
	virtual string name() const override;
};