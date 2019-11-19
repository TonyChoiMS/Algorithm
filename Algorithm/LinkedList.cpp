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
	// 메모리 할당 오류가 발생하면 예외가 발생됨
	Element *element = new Element(head, data);
	head = element;
}

void * CustomStack::pop()
{
	Element *popElement = head;
	void *data;

	// StackError 예외 클래스는 다른 데서 정의했다고 가정
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

		// 원소가 한 개 뿐인 리스트의 경우
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

	// 리스트의 맨 앞에 삽입하는 경우
	if (!elem)
	{
		newElem->setNext(head);
		head = newElem;

		// 비어있는 리스트의 경우
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

			// 리스트의 맨 뒤에 추가하는 경우
			if (!(newElem->getNext()))
				tail = newElem;
			return true;
		}
		curPos = curPos->getNext();
	}

	// 삽입할 위치를 못찾은 경우, 할당된 메모리를 비우고 false를 반환한다.
	delete newElem;
	return false;
}

void LinkedList::append(Node *child, Node **tail)
{
	Node *curNode;

	// 자식 리스트를 맨 뒤에 붙인다.
	(*tail)->next = child;
	child->prev = *tail;

	// 새로운 꼬리가 될 자식 리스트의 끝을 찾아낸다.
	for (curNode = child; curNode->next; curNode = curNode->next)
		;
	// 생략

	// 이제  curNode가 꼬리 노드가 되었으므로 꼬리 포인터를 갱신한다.
	*tail = curNode;
}

/**
 *		리스트 단층화
 **/
void LinkedList::flattenList(Node * head, Node ** tail)
{
	Node *curNode = head;
	while (curNode)
	{
		// 현재 노드에 자식이 있는 경우
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
	// 리스트가 끝나지 않는지 확인하면서 앞에서부터 m개의 원소를 센다.

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

	// mBehind를 head 포인터로 설정한 다음 current 포인터가
	// 마지막 원소를 가리키게 될 때까지 mBehind와 current를 함께 전진시킨다.
	mBehind = head;
	while (current->next)
	{
		current = current->next;
		mBehind = mBehind->next;
	}

	// 이제 mBehind가 우리가 찾으려고 했던 원소를
	// 가리키므로 mBehind를 리턴하면 된다.
	return mBehind;
}
