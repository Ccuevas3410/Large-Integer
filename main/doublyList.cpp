
#include "pch.h"  
#include "doublyList.h"  
#include <iostream>  
#include <assert.h> 

using namespace std;

template<class x>
doublyList<x>::doublyList()
{
	length = 0;
	head = tail = nullptr;
}

template<class x>
doublyList<x>::doublyList(const doublyList<x> &obj) {


	head = nullptr;
	copy(obj);

}

template<class x>
doublyList<x>::~doublyList()
{
	destroyList();

}

template<class x>
void doublyList<x>::destroyList() {

	Node <x> *garbage;
	while (head != nullptr)
	{
		garbage = head;
		head = head->next;
		delete garbage;

	}

	head = nullptr;
	tail = nullptr;
	length = 0;
}

template<class x>
void doublyList<x>::printList() {

	if (head == nullptr)
	{
		cout << "List is empty\n";
	}
	else
	{
		Node <x> *dummyNode = head;

		while (dummyNode != nullptr)
		{
			cout << dummyNode->data << " ";  //We are looping through the Linked list with this.  
			dummyNode = dummyNode->next;  //We are assigning the address of next node to the TEMP node so it can keep looping through it.  
		}

	}

	cout << "\n";
	cout << "List finished printing!\n \n";

}

template <class x>
void doublyList<x>::reversePrint() {

	if (head == nullptr)
	{
		cout << "List is empty!\n";
	}
	else
	{
		Node<x> *dummyNode = tail;
		while (dummyNode != nullptr)
		{

			cout << dummyNode->data << " ";
			dummyNode = dummyNode->back;

		}

	}
	cout << "\n";
	cout << "List finished printing BACKWARDS!\n \n";

}

template <class x>
void doublyList<x>::insertItemFirst(x value) {

	Node <x> *dummyNode = new Node<x>;
	if (head == nullptr)
	{

		dummyNode->data = value;
		dummyNode->back = head;
		dummyNode->next = head;
		head = dummyNode;
		tail = dummyNode;
		length++;
	}
	else
	{
		dummyNode->data = value;
		dummyNode->next = head;
		dummyNode->back = nullptr;
		head->back = dummyNode;
		head = dummyNode;
		length++;
	}

}

template <class x>
void doublyList<x>::searchItem(x item) {

	Node <x> *dummyNode = head;
	int count = 1;

	//WHILE NEXT IS NOT EMPTY AND DATA IS NOT FOUND, ADVANCE
	while (dummyNode->next != nullptr && dummyNode->data != item)
	{
		dummyNode = dummyNode->next;
		count++;
	}

	//IF DATA IS FOUND, SAY IT
	if (dummyNode->data == item)
	{
		cout << "Value " << item << " found in list! " << count << "position\n";
	}

	else
	{
		cout << "Value " << item << " not in the list \n";
	}

}

template <class x>
void doublyList<x>::deleteItem(x item) {

	if (length == 0)
	{
		cout << "Empty list\n";

	}
	else
	{
		cout << "Deleting..." << item << " from list\n";
		Node <x> *garbage;
		Node <x> *walker = head;

		//IF THE VALUE IS AT THE HEAD NODE.
		if (head->data == item) {
			garbage = head;

			//IF VALUE IS AT THE HEAD NODE AND THERE IS NO MORE NODES, SET ALL TO NULL.
			if (head->next == nullptr)
			{
				head = nullptr;
				tail = nullptr;
			}
			// IF VALUE IS AT HEAD NODE AND THERE ARE MORE NODES, WALK.
			else
			{
				head = walker->next;
				head->back = nullptr;
			}

			delete garbage;
			length--;
		}

		//IF VALUE IS NOT AT HEAD NORE
		else {

			while (walker != nullptr && walker->data != item) {
				walker = walker->next;
			}
			//IF ITEM IS FOUND AND IT IS THE LAST NODE.
			if (walker->next == nullptr) {
				garbage = walker;
				walker->back->next = nullptr;
				tail = walker->back;
				delete garbage;
				length--;

			}

			else {

				garbage = walker;
				walker->back->next = walker->next;
				walker->next->back = walker->back;
				delete garbage;
				length--;
			}
		}
	}

	cout << "Item " << item << " deleted \n";
	cout << "The new length of this list is: " << length << "\n\n";
}

template <class x>
void doublyList<x> ::append(x value) {

	Node <x> *dummyNode = new Node<x>;

	//IF HEAD IS NULL, SET IT EQUAL TO DUMMY, WHICH IS TAIL RIGHT NOW.

	if (tail == nullptr)
	{
		dummyNode->data = value;
		dummyNode->next = nullptr;
		dummyNode->back = nullptr;
		head = dummyNode;
		tail = dummyNode;
		length++;
	}

	// IF THERE ARE MORE NODES, SET DUMMY TO BEING TAIL.
	else
	{
		dummyNode->data = value;
		dummyNode->back = tail;
		dummyNode->next = nullptr;
		tail->next = dummyNode;
		tail = dummyNode;
		length++;
	}

}

template <class x>
int doublyList<x>::getLength() {
	return length;
}

template <class x>
Iterator<x> doublyList<x>::begin() {

	Iterator<x> temp(head);
	return temp;

}

template <class x>
Iterator<x> doublyList<x>::end() {

	Iterator<x> temp(nullptr);
	return temp;
}

template <class x>
Iterator<x> doublyList<x>::last() {

	Iterator<x> temp(tail);
	return temp;
}


template <class x>
void doublyList<x>::copy(const doublyList<x> &obj) {

	Node <x> *walker;
	Node <x> *copyData;

	if (obj.head == nullptr)
	{
		head = nullptr;
		tail = nullptr;
		length = 0;
	}

	else
	{
		walker = obj.head;
		length = obj.length;

		head = new Node <x>;
		head->data = walker->data;
		head->next = nullptr;
		head->back = nullptr;
		tail = head;

		walker = walker->next; //THIS WALKER WALKS OBJ HEAD TO NEXT NODE

		while (walker != nullptr)
		{
			copyData = new Node <x>;
			copyData->data = walker->data;
			copyData->next = nullptr;
			copyData->back = tail;
			tail->next = copyData;
			tail = copyData;

			walker = walker->next;
		}

	}
}

template <class x>
doublyList<x>&doublyList<x>::operator= (const doublyList<x> &obj) {
	//THIS IS TO AVOID SELF COPY
	{
		if (this != &obj)
			copy(obj);
	}
	return *this;

}

/*template <class x>
void doublyList<x>::replaceItem(x olditem, x newitem) {

	int count = 0;
	if (head == nullptr)
	{
		cout << "Nothing to replace\n";

	}

	Node <x> *walker = head;
		while(walker->next != nullptr)
		{
		walker = walker->next;

			if (walker->data == olditem)
			{
			walker->data = newitem;
			count++;

			}


		else if (walker->data != olditem)
		{



		}
	}
		if (count == 0)
		{
			cout << "Nothing has been found";

		}
		else
		{
			cout << count << " items changed\n";
			cout << endl;
		}


}*/