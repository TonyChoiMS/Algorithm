#include "LinkedList.h"
//#include "LinkedList.h"
//#include <iostream>
//
//using namespace std;
//
//LinkedList::LinkedList(int value)
//{
//	head = tail = new ListElement<int>(value);
//	size = 1;
//}
//
//LinkedList::~LinkedList()
//{
//	while (head != nullptr)
//	{
//		PopFront();
//	}
//}
//
//void LinkedList::PushBack(int value)
//{
//	ListElement<int>* newElem = new ListElement<int>(value);
//
//	if (head == nullptr)
//	{
//		head = newElem;
//	}
//	else
//	{
//		tail->next = newElem;
//	}
//
//	tail = newElem;
//	size++;
//}
//
//void LinkedList::PopFront()
//{
//	if (head != nullptr)
//	{
//		ListElement<int> *RemoveElem = head;
//		head = head->next;
//		delete RemoveElem;
//		size--;
//	}
//}
//
//void LinkedList::Insert(int value)
//{
//	ListElement<int>* insert = new ListElement<int>(value);
//	ListElement<int>* scan;
//
//	if (head != nullptr)
//	{
//		if (head->Value > value)
//		{
//			insert->next = head;
//			head = insert;
//		}
//		else if (tail->Value < value)
//		{
//			tail->next = insert;
//			tail = insert;
//		}
//		else
//		{
//			scan = head;
//			while (scan->next->Value < insert->Value)
//			{
//				scan = scan->next;
//			}
//
//			insert->next = scan->next;
//			scan->next = insert;
//		}
//	}
//	else
//	{
//		head = insert;
//		tail = insert;
//		head->next = nullptr;
//	}
//	size++;
//}
//
//void LinkedList::Print()
//{
//	ListElement<int>* scan = head;
//	while (scan != nullptr)
//	{
//		cout << scan->Value << endl;
//		scan = scan->next;
//	}
//}
//
//

CustomStack::CustomStack()
{
}

CustomStack::~CustomStack()
{
	while (head)
	{
		Element *next = head->getNext();
		delete head;
		head = next;
	}
}

void CustomStack::push(void * data)
{
	// �޸� �Ҵ� ������ �߻��ϸ� ���ܰ� �߻���
	Element *element = new Element(head, data);
	head = element;
}

void * CustomStack::pop()
{
	Element *popElement = head;
	void *data;

	// StackError ���� Ŭ������ �ٸ� ���� �����ߴٰ� ����
	if (head == nullptr)
	{
		//throw StackError(E_EMPTY);
	}

	data = head->value();
	head = head->getNext();
	delete popElement;

	return data;
	return nullptr;
}

bool CustomStack::deleteStack(Element * elem)
{
	Element *curPos = head;

	if (!elem)
		return false;

	if (elem == head)
	{
		head = elem->getNext();
		delete elem;

		// ���Ұ� �� �� ���� ����Ʈ�� ���
		if (!head)
			tail = nullptr;

		return true;
	}

	while (curPos)
	{
		if (curPos->getNext() == elem)
		{
			curPos->setNext(elem->getNext());
			delete elem;
			if (curPos->getNext() == nullptr)
				tail = curPos;

			return true;
		}

		curPos = curPos->getNext();
	}

	return false;
}

bool CustomStack::insertAfter(Element * elem, int data)
{
	Element *newElem, *curPos = head;

	newElem = new Element(nullptr, data);
	if (!newElem)
	{
		return false;
	}
	newElem->value = data;

	// ����Ʈ�� �� �տ� �����ϴ� ���
	if (!elem)
	{
		newElem->setNext(head);
		head = newElem;

		// ����ִ� ����Ʈ�� ���
		if (!tail)
			tail = newElem;
		
		return true;
	}

	while (curPos)
	{
		if (curPos == elem)
		{
			newElem->setNext(curPos->getNext());
			curPos->setNext(newElem);

			// ����Ʈ�� �� �ڿ� �߰��ϴ� ���
			if (!(newElem->getNext()))
				tail = newElem;
			return true;
		}
		curPos = curPos->getNext();
	}

	// ������ ��ġ�� ��ã�� ���, �Ҵ�� �޸𸮸� ���� false�� ��ȯ�Ѵ�.
	delete newElem;
	return false;
}

void LinkedList::append(Node *child, Node **tail)
{
	Node *curNode;

	// �ڽ� ����Ʈ�� �� �ڿ� ���δ�.
	(*tail)->next = child;
	child->prev = *tail;

	// ���ο� ������ �� �ڽ� ����Ʈ�� ���� ã�Ƴ���.
	for (curNode = child; curNode->next; curNode = curNode->next)
		;
	// ����

	// ����  curNode�� ���� ��尡 �Ǿ����Ƿ� ���� �����͸� �����Ѵ�.
	*tail = curNode;
}

/**
 *		����Ʈ ����ȭ
 **/
void LinkedList::flattenList(Node * head, Node ** tail)
{
	Node *curNode = head;
	while (curNode)
	{
		// ���� ��忡 �ڽ��� �ִ� ���
		if (curNode->child)
		{
			append(curNode->child, tail);
		}
		curNode = curNode->next;
	}
}

ListElement<int>* LinkedList::FindMToLastElement(ListElement<int>* head, int m)
{
	ListElement<int> *current, *mBehind;
	int i;
	if (!head)
	{
		return nullptr;
	}
	// ����Ʈ�� ������ �ʴ��� Ȯ���ϸ鼭 �տ������� m���� ���Ҹ� ����.

	current = head;
	for (int i = 0; i < m; i++)
	{
		if (current->next)
		{
			current = current->next;
		}
		else
		{
			return nullptr;
		}
	}

	// mBehind�� head �����ͷ� ������ ���� current �����Ͱ�
	// ������ ���Ҹ� ����Ű�� �� ������ mBehind�� current�� �Բ� ������Ų��.
	mBehind = head;
	while (current->next)
	{
		current = current->next;
		mBehind = mBehind->next;
	}

	// ���� mBehind�� �츮�� ã������ �ߴ� ���Ҹ�
	// ����Ű�Ƿ� mBehind�� �����ϸ� �ȴ�.
	return mBehind;
}
