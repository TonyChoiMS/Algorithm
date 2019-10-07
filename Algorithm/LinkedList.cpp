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
