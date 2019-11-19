#pragma once

template<class T>
class ListElement
{
public:
	friend class LinkedList;

	ListElement(const T &value) : next(nullptr), data(value) {}
	~ListElement() {}

	ListElement* GetNext() const { return next; }
	const T& Value() const { return data; }
	void SetNext(ListElement* elem) { next = elem; }
	void SetValue(const T &value) { data = value; }

private:
	ListElement *next;
	T data;
};

class LinkedList
{
public:
	LinkedList(int value);
	~LinkedList();

	void PushBack(int value);
	void PopFront();
	void Insert(int value);
	void Print();
	ListElement<int>* FindMToLastElement(ListElement<int>* head, int m);
	bool DeleteElement(ListElement<int> **head, ListElement<int> *deleteMe)
	{
		ListElement<int> *elem;

		if (!head || !*head || !deleteMe)
			return false;

		elem = *head;
		if (deleteMe == *head)
		{
			// 머리 처리용 특별 케이스
			*head = elem->next;
			delete deleteMe;
			return true;
		}

		while (elem)
		{
			if (elem->next == deleteMe)
			{
				// elem이 deleteMe 앞의 원소
				elem->next = deleteMe->next;
				delete deleteMe;
				return true;
			}
			elem = elem->next;
		}

		return false;			// deleteMe를 못찾았을 경우
	}

private:
	int size;
	ListElement<int>* head;
	ListElement<int>* tail;
};

class CustomStack
{
public:
	CustomStack();
	~CustomStack();
	
	void push(void *data);
	void *pop();
	
protected:
	class Element
	{
	public:
		Element(Element *n, void *d) : next(n), data(d) {}
		Element *getNext() const { return next; }
		void *value() const { return data; }
		Element *setNext(Element *elem) { next = elem; }
	private:
		Element *next;
		void *data;
	};

	Element *head;
	Element *next;
	Element *tail;

public:
	bool deleteStack(Element *elem);
	bool insertAfter(Element *elem, int data);
};

