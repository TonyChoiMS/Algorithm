#pragma once


#include <vector>
#include <functional>

// ����� ������ 1~10^5�±�����.
// 0 <= Node.val <= 9
// �ð����⵵ O(n), �������⵵ O(1)�� �� �� �ִ°�?
// ��带 �ѹ� ��ȸ�ϴ� �͸����� ������ ���� �� �� �־���ϸ�,
// �������⵵ O(1)�� �־����� ListNode*�� �����ϰ� ���ο� �ڷᱸ���� ����� �ȵ�.
class PalindromeLinkedList
{
	struct ListNode 
	{
		int val;
		ListNode *next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode *next) : val(x), next(next) {}
		
	};
public:
	PalindromeLinkedList() {}
	~PalindromeLinkedList() {}

public:
	void Start()
	{
		ListNode* head;
		head = new ListNode(1);
		head->next = new ListNode(2);
		head->next->next = new ListNode(2);
		head->next->next->next = new ListNode(1);
		std::cout << "Sol : " << Solution(head) << std::endl;
	}

	ListNode* reverse(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode* rest_head = reverse(head->next);
		ListNode* rest_tail = head->next;
		rest_tail->next = head;
		head->next = nullptr;
		return rest_head;
	}

	bool Solution(ListNode* head)
	{
		// BruteForce ���
		// Palindrome�� ����� �Ȱ����� Ȯ���ϴ� �˰��� �̹Ƿ�, �迭�� ������ ���鼭, 
		// ���� ���� ���� ���� ������ Ȯ���ϴ� ����� ���.
		// �� ����� �ð����⵵�� O(n)�� �� �� ������, �������⵵�� O(n)�̹Ƿ� �������� ���ϴ� ���� �ƴϴ�.
		// ������ LeetCode�� �Է��غ� ��� ��Ÿ�� �ð��� �ٸ� ����� ���� ��û ����...
		// Runtime: 240 ms
		// Memory Usage : 128.2 MB
		/*std::vector<int> vec;

		while (head != nullptr)
		{
			std::cout << "val : " << std::endl;
			vec.push_back(head->val);
			head = head->next;
		}

		int size = vec.size() / 2;
		std::cout << size << std::endl;
		for (int i = 0; i < size; i++)
		{
			if (vec[i] == vec[vec.size() - 1 - i])
				continue;
			else
				return false;
		}

		return true;*/

		// ���ȣ���� ����ϴ� ���
		// StackOverflow���� �Ұ��� ��� �� �ϳ��ε�, ��Ÿ�� �ð��� ���� �ߴ� ��ĺ��� �����ɸ�...
		// Runtime: 268 ms
		// Memory Usage : 146.2 MB
		/*std::function<bool(ListNode*)> ip_rec = [&](ListNode* p) -> bool
		{
			if (p)
			{
				if (!ip_rec(p->next)) return false;
				if (p->val != head->val) return false;
				head = head->next;
			}
			return true;
		};

		return ip_rec(head);*/
		
		// LeetCode���� �߰��� Ǯ�̹�
		// Runtime: 204 ms
		// Memory Usage : 116.4 MB
		if (head == nullptr || head->next == nullptr)
			return true;
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast != nullptr && fast->next != nullptr) {
			fast = fast->next->next;
			if (fast != nullptr)
				slow = slow->next;
		}
		ListNode* rev = reverse(slow->next);
		ListNode* curr = head;

		while (rev != nullptr) {
			if (curr->val != rev->val)
				return false;
			curr = curr->next;
			rev = rev->next;
		}
		return true;
	}
};