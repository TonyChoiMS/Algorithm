#pragma once


#include <vector>
#include <functional>

// 노드의 개수는 1~10^5승까지다.
// 0 <= Node.val <= 9
// 시간복잡도 O(n), 공간복잡도 O(1)에 할 수 있는가?
// 노드를 한번 순회하는 것만으로 정답을 유추 할 수 있어야하며,
// 공간복잡도 O(1)은 주어지는 ListNode*를 제외하곤 새로운 자료구조를 만들면 안됨.
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
		// BruteForce 방식
		// Palindrome은 뒤집어도 똑같은지 확인하는 알고리즘 이므로, 배열의 절반을 돌면서, 
		// 앞의 값과 뒤의 값이 같은지 확인하는 방법을 사용.
		// 이 방법은 시간복잡도는 O(n)이 될 수 있으나, 공간복잡도도 O(n)이므로 문제에서 원하는 답은 아니다.
		// 심지어 LeetCode에 입력해본 결과 런타임 시간도 다른 사람에 비해 엄청 높음...
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

		// 재귀호출을 사용하는 방법
		// StackOverflow에서 소개한 방법 중 하나인데, 런타임 시간이 위에 했던 방식보다 오래걸림...
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
		
		// LeetCode에서 발견한 풀이법
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