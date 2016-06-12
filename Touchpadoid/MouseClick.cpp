#include "stdafx.h"
#include "MouseClick.hpp"


string MouseClick::name() const
{
	return "MouseClick";
}

bool MouseClick::load(void *data, size_t size)
{
	if (size != 2)
		return false;

	unsigned char *temp = reinterpret_cast<unsigned char*>(data);
	button = static_cast<Button>(temp[0]);
	action = static_cast<Action>(temp[1]);

	if (button != Left && button != Right)
		return false;

	if (action != Press && action != Release && action != Click)
		return false;

	return true;
}

void MouseClick::execute(long time)
{
	INPUT input;
	input.type = INPUT_MOUSE;
	input.mi.dx = 0;
	input.mi.dy = 0;
	input.mi.mouseData = 0;
	input.mi.time = time;
	input.mi.dwExtraInfo = NULL;

	if (button == Left)
	{
		if (action == Press)
		{
			input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
		}
		else if (action == Release)
		{
			input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
		}
		else if (action == Click)
		{
			input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP;
		}
	}
	else if (button == Right)
	{
		if (action == Press)
		{
			input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
		}
		else if (action == Release)
		{
			input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
		}
		else if (action == Click)
		{
			input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP;
		}
	}


	SendInput(1, &input, sizeof(INPUT));
}