#pragma once
#include "Command.hpp"


class MouseClick : public Command
{
public:
	enum Button
	{
		Left = 0,
		Right,
	};

	enum Action
	{
		Press = 0,
		Release,
		Click,
	};

private:
	Button button;
	Action action;


public:
	MouseClick() = default;
	virtual ~MouseClick() = default;


	virtual bool load(void *data, size_t size) override;
	virtual void execute(long time) override;
	virtual string name() const override;
};

