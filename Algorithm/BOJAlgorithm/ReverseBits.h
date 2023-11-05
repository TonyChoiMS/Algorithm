#pragma once
#include <iostream>
class ReverseBits
{
public:
	ReverseBits();
	~ReverseBits();

	// 32bits unsigned 정수값이 주어진다.
	// 
	uint32_t Solution(uint32_t n)
	{
		int ret = 0;
		for (int i = 0; i < 32; ++i)
		{
			ret |= ((n & 1) << (31 - i));
			n >>= 1;
		}

		return ret;
	}

	uint32_t Solution1(uint32_t n)
	{
		unsigned int ret = 0;
		unsigned int l = 2147483648, r = 1;

		for (int i = 0; i < 16; i += 1)
		{
			ret |= ((n & l) >> (31 - (i * 2))) | ((n & r) << (31 - (i * 2)));
			l = l >> 1;
			r = r << 1;
		}

		return ret;
	}
};