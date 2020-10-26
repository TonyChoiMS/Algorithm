#include "InterView.h"

void InterView::wcReverseWords(wchar_t str[])
{
	int start = 0, end = 0, length;
	length = wcslen(str);
	// ���ڿ� ��ü�� �����´�.
	wcReverseString(str, start, length - 1);
	while (end < length)
	{
		if (str[end] != L' ')		// �ܾ �������� �ʴ� ���ڴ� �ǳʶ�
		{
			// �ܾ� ���� ��ġ ����.
			start = end;
			// �ܾ �������� �ʴ� ���ڰ� ���� ������ ��ĵ
			while (end < length && str[end] != L' ')
				end++;
			// �ܾ� ������ �ٽ� �̵�
			end--;
			// �ܾ� ������
			wcReverseString(str, start, end);
		}
		end++;
	}
}

void InterView::wcReverseString(wchar_t str[], int start, int end)
{
	wchar_t temp;
	while (end > start)
	{
		// ���� ������
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		// �ε����� ��� ������ �̵�
		start++; end--;
	}
}
