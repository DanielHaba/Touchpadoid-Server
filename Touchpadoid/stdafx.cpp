// stdafx.cpp : source file that includes just the standard includes
// Touchpadoid.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file


void hex_dump(ostream &output, const void *data, size_t size)
{
	ostream::fmtflags flags = output.flags();

	for (size_t i = 0; i < size; ++i)
	{
		if (i > 0)
		{
			if (i % 8 == 0)
			{
				output << endl;
			}
			else
			{
				output << ' ';
			}
		}

		unsigned char byte = static_cast<const unsigned char*>(data)[i];

		output << uppercase << setfill('0') << setw(2) << hex;
		output << static_cast<unsigned int>(byte);
	}

	output.flags(flags);
}