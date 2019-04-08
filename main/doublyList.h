#pragma once  
#include "pch.h"  
using namespace std;

//FORDWARD DECLARATION   
template<class x> struct Node;
template<class x> class doublyList;
template<class x> class Iterator;

template<class x>
struct Node {

	x data;
	Node *next, *back;
};


template<class x>
class doublyList
{
private:
	Node <x> *head, *tail;
public:

	doublyList();
	doublyList(const doublyList<x>&);
	~doublyList();

	int length;
	int getLength();
	void printList();
	void reversePrint();
	void insertItemFirst(x);
	void append(x);
	void searchItem(x);
	void deleteItem(x);
	void destroyList();
	void copy(const doublyList<x> &);
	

	Iterator<x> begin();
	Iterator<x> last();
	Iterator<x> end();

	doublyList<x> &operator= (const doublyList<x> &);
	

};

template <class x>
class Iterator {

	friend class doublyList<x>;
public:
	Iterator();
	Iterator(Node<x> *pos) { position = pos; }

	bool operator==(const Iterator& obj) {
		return position == obj.position;
	}
	bool operator!=(const Iterator& obj) {
		return position != obj.position;
	}
	int &operator*() {
		return position->data;
	}

	//PRE INCREMENT OPERATOR OVERLOAD
	Iterator operator++() {

		position = position->next;
		return position;
	}
	//POST INCREMENT OPERATOR OVERLOAD
	Iterator operator++(int) {

		position = position->next;
		return position;
	}
	Iterator operator--() {

		position = position->back;
		return position;
	}
	Iterator operator--(int) {

		position = position->back;
		return position;
	}


private:
	Node<x> *position;
	doublyList<x> *container;

};