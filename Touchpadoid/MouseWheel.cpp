#include "stdafx.h"
#include "MouseWheel.hpp"

string MouseWheel::name() const
{
	return "MouseWheel";
}

bool MouseWheel::load(void *data, size_t size)
{
	if (size != sizeof(int))
		return false;

	delta = *reinterpret_cast<int*>(data);
	return true;
}

void MouseWheel::execute(long time)
{
	INPUT input;
	input.type = INPUT_MOUSE;
	input.mi.dx = 0;
	input.mi.dy = 0;
	input.mi.dwExtraInfo = NULL;
	input.mi.time = time;
	input.mi.mouseData = delta;
	input.mi.dwFlags = MOUSEEVENTF_WHEEL;

	SendInput(1, &input, sizeof(INPUT));
}