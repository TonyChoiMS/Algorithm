#pragma once

#include <string.h>

class wcReverseWords
{
public:
	void Solution(wchar_t str[])
	{
		int start = 0;
		int end = 0;
		int length = wcslen(str);

		// 문자열 전체를 뒤집는다.
		wcReverseString(str, start, length - 1);
		while (end < length)
		{
			if (str[end] != L' ')
			{
				// 단어를 구성하지 않는 문자는 건너뜀
				// 단어 시작 위치 저장
				start = end;

				// 단어를 구성하지 않는 문자가 나올 때까지 스캔
				while (end < length && str[end] != L' ')
					end++;

				// 단어 끝으로 다시 이동
				end--;
				// 단어 뒤집기
				wcReverseString(str, start, end);
			}

			end++;		// 다음 토큰으로 이동
		}
	}

private:
	void wcReverseString(wchar_t str[], int start, int end)
	{
		wchar_t temp;
		while (end > start)
		{
			// 문자 뒤집기
			temp = str[start];
			str[start] = str[end];
			str[end] = temp;
			// 인덱스를 가운데 쪽으로 이동
			start++;
			end--;
		}
	}
};
