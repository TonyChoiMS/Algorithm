//#pragma once
//
//template<class T>
//class ListElement
//{
//public:
//	friend class LinkedList;
//
//	ListElement(const T &value) : next(nullptr), data(value){}
//	~ListElement() {}
//
//	ListElement* GetNext() const { return next; }
//	const T& Value() const { return data; }
//	void SetNext(ListElement* elem) { next = elem; }
//	void SetValue(const T &value) { data = value; }
//	
//private:
//	ListElement *next;
//	T data;
//};
//
//class LinkedList
//{
//public:
//	LinkedList(int value);
//	~LinkedList();
//
//	void PushBack(int value);
//	void PopFront();
//	void Insert(int value);
//	void Print();
//
//private:
//	int size;
//	ListElement<int>* head;
//	ListElement<int>* tail;
//};
//
