#pragma once

#include <wchar.h>

class InterView
{
public:
	InterView() {}
	~InterView() {}

	void wcReverseWords(wchar_t str[]);
	void wcReverseString(wchar_t str[], int start, int end);
};

