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

		// ���ڿ� ��ü�� �����´�.
		wcReverseString(str, start, length - 1);
		while (end < length)
		{
			if (str[end] != L' ')
			{
				// �ܾ �������� �ʴ� ���ڴ� �ǳʶ�
				// �ܾ� ���� ��ġ ����
				start = end;

				// �ܾ �������� �ʴ� ���ڰ� ���� ������ ��ĵ
				while (end < length && str[end] != L' ')
					end++;

				// �ܾ� ������ �ٽ� �̵�
				end--;
				// �ܾ� ������
				wcReverseString(str, start, end);
			}

			end++;		// ���� ��ū���� �̵�
		}
	}

private:
	void wcReverseString(wchar_t str[], int start, int end)
	{
		wchar_t temp;
		while (end > start)
		{
			// ���� ������
			temp = str[start];
			str[start] = str[end];
			str[end] = temp;
			// �ε����� ��� ������ �̵�
			start++;
			end--;
		}
	}
};
