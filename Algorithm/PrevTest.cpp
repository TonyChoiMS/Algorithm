#include "PrevTest.h"
#include <queue>

using namespace std;
/**
 * LINE 2019 ��ݱ� ����ä�� ���� 1��.
 * ���� : ���� �ڴϿ� ������ ��Ȱ�� ���ǿ��� '�� ��ƺ���' ������ �Ѵ�. �� ������ ������ �ڴϸ� ��ų�, �ڴϰ� �ʹ� �ָ� �޾Ƴ��� ������. ������ �����µ� �ɸ��� �ּ� �ð��� ���Ͻÿ�.
 * ����
 * 1. �ڴϴ� ó�� ��ġ C���� 1�� �� 1��ŭ �����̰�, ���Ŀ��� ������ �پ� �� �ʸ��� ���� �̵� �Ÿ� + 1��ŭ �����δ�. �� �ð��� ���� �ڴ��� ��ġ�� C, C+1, C+3, C+6, ... �̴�.
 * 2. ������ ���� ��ġ B���� ���� ���� B-1, B+1, 2*B �� �ϳ��� ������ �� �ִ�.
 * 3. �ڴϿ� ������ ��ġ p�� ���� 0<= x <= 200,000�� �����Ѵ�.
 * 4. ������ ������ ����� ��ġ�δ� �̵��� �� ����, �ڴϰ� ������ ����� ������ ������.
 *
 * �Է� : ǥ�� �Է��� ù �ٿ� �ڴ��� ��ġ C�� ������ ��ġ B�� �������� �����Ͽ� ������� �д´�.
 * ��� : ������ �ڴϸ� ���� �� �ִ� �ּҽð� N�ʸ� ǥ�� ����Ѵ�. �� ������ �ڴϸ� ���� ���� ��쿡�� -1�� ����Ѵ�.
 */
int PrevTest::LineTest1(int conyPosition, int brownyPosition)
{
	int time = 0;
	bool visit[200001][2];
	queue<pair<int, int>> queue;

	memset(visit, 0, sizeof(visit));
	queue.push(make_pair(brownyPosition, 0));

	while (true)
	{
		conyPosition += time;

		// �ڴϰ� �ָ� �������� ���
		if (conyPosition > 200000)
			return -1;

		// ����ϰ� �ڴϸ� ����� ��� �ð� ���� ����
		if (visit[conyPosition][time % 2])
			return time;

		for (int i = 0, size = queue.size(); i < size; i++)
		{
			int currentPosition = queue.front().first;
			int newTime = (queue.front().second + 1) % 2;
			int newPosition;

			queue.pop();

			newPosition = currentPosition - 1;
			if (newPosition > 0 && !visit[newPosition][newTime])
			{
				visit[newPosition][newTime] = true;
				queue.push(make_pair(newPosition, newTime));
			}

			newPosition = currentPosition + 1;
			if (newPosition < 200001 && !visit[newPosition][newTime])
			{
				visit[newPosition][newTime] = true;
				queue.push(make_pair(newPosition, newTime));
			}

			newPosition = currentPosition * 2;
			if (newPosition < 200001 && !visit[newPosition][newTime])
			{
				visit[newPosition][newTime] = true;
				queue.push(make_pair(newPosition, newTime));
			}
		}
		time++;
	}
}
