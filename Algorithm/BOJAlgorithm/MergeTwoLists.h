#pragma once

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
	
};

class MergeTwoLists
{
public:
	ListNode* solution(ListNode* l1, ListNode* l2)
	{
		if (l1 == nullptr)
			return l2;
		else if (l2 == nullptr)
			return l1;

		ListNode* mergedList = new ListNode();
		ListNode* headMergedList = mergedList;

		while (l1 != nullptr && l2 != nullptr)
		{
			if (l1->val >= l2->val)
			{
				ListNode* nextNode = new ListNode();
				mergedList->val = l2->val;
				mergedList->next = nextNode;
				mergedList = mergedList->next;
				l2 = l2->next;
			}
			else
			{
				ListNode* nextNode = new ListNode();
				mergedList->val = l1->val;
				mergedList->next = nextNode;
				mergedList = mergedList->next;
				l1 = l1->next;
			}
		}

		ListNode* remainL;
		if (l1 != nullptr)
			remainL = l1;
		else if (l2 != nullptr)
			remainL = l2;

		while (remainL != nullptr)
		{
			ListNode* nextNode = new ListNode();
			mergedList->val = remainL->val;

			if (remainL->next == nullptr)
			{
				mergedList->next = nullptr;
				break;
			}
			else
			{
				mergedList->next = nextNode;
				mergedList = mergedList->next;
				remainL = remainL->next;
			}
		}

		return headMergedList;
	}
};
