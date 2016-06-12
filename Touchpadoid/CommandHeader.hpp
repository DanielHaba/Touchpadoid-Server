#pragma once


#pragma pack(push, 1)
__declspec(align(1)) struct CommandHeader
{
	unsigned char code;
	unsigned int index;
	unsigned int size;	
};
#pragma pack(pop)