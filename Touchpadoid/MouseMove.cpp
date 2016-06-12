#include "stdafx.h"
#include "MouseMove.hpp"



string MouseMove::name() const
{
	return "MouseMove";
}



void MouseMove::execute(long time)
{
	INPUT input;
	input.type = INPUT_MOUSE;
	input.mi.dx = static_cast<LONG>(round(moveX));
	input.mi.dy = static_cast<LONG>(round(moveY));
	input.mi.dwFlags = MOUSEEVENTF_MOVE;
	input.mi.dwExtraInfo = NULL;
	input.mi.mouseData = 0;
	input.mi.time = time;

	SendInput(1, &input, sizeof(INPUT));
}

bool MouseMove::load(void *data, size_t size)
{
	if (sizeof(float) * 2 != size)
		return false;

	float *tempArray = reinterpret_cast<float*>(data);

	moveX = tempArray[0];
	moveY = tempArray[1];

	return true;
}