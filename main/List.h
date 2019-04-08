#pragma once


#include "pch.h"
using namespace std;

template< class x>
struct Node {

	x data;
	Node *next,*back;
};


template<class x>
class List
{
private:
	
	Node <x> *head,*tail;
public:
	List();
	~List();
	int length;
	
	void printList();
	void insertItemFirst(x);
	void append(x);
	void searchItem(x);
	void deleteItem(x);
	void copy(const List<x> &);
	int getLength();

//	Iterator begin();
	//Iterator end();
	//List operator=(const);

};
/*template <class x>
class Iterator {
	
	friend class List;
public:
	Iterator();
private:

	Node<x> *position;
	List<x> *container;

};
*/