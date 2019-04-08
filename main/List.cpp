
#include "pch.h"
#include "List.h"
#include <iostream>

using namespace std;
template<class x>
List<x>::List()
{
	length = 0;
	head = nullptr;
	tail = nullptr;

}
template<class x>
List<x>::~List()
{
	Node <x> *garbage = head;
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
void List<x>::printList() {

	if (head == nullptr)
	{
		cout << "List is empty\n";
		return;
	}
	else
	{
		Node <x> *dummyNode = head;

		while (dummyNode != nullptr)
		{

			cout << dummyNode->data << "  ";  //We are looping through the Linked list with this.
			dummyNode = dummyNode->next;  //We are assigning the address of next node to the TEMP node so it can keep looping through it.

		}


	}
	cout << "\n";
	cout << "List finished printing!\n ";
}


template <class x>
void List<x>::insertItemFirst(x value) {

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
void List<x>::searchItem(x item) {

	Node <x> *dummyNode = head;


	while (dummyNode->next != nullptr && dummyNode->data != item)
	{
		dummyNode = dummyNode->next;

	}
	if (dummyNode->data == item)
	{
		cout << "Value found! \n";
	}
	else
	{


		cout << "Value not in the list \n";


	}
}

template <class x>
void List<x>::deleteItem(x item) {

	if (length == 0)
	{
		cout << "Empty list\n";
	}
	else
	{
		cout << "Deleting...\n";
		Node <x> *garbage = head;

		//IF THE VALUE IS AT THE HEAD NODE
		if (garbage->data == item) {
			head = head->next;
			delete garbage;
			length--;
		}

		else
		{
			while (garbage->next != nullptr && garbage->next->data != item)
				garbage = garbage->next;
		}
		if (garbage->next != nullptr)
		{
			Node <x> *t = garbage->next;
			delete t;
			length--;

		}
	}
	cout << "Item " << item << " deleted \n";
	cout << "The new length of this list is: " << length << "\n";

}



template <class x>
void List<x> ::append(x value) {

	// Creates a temporary Node to hold the last node and set Dummy's data and next pointer 
	Node <x> *dummyNode = new Node<x>;
	//Puts the data entered into the Dummy node and set the next address to Null as THIS should be the LAST node;

	// If the head Node is null, the set it equal to dummy node which is the TAIL in this case.
	if (tail == nullptr)
	{
		dummyNode->data = value;
		dummyNode->next = nullptr;
		dummyNode->back = nullptr;
		head = dummyNode;
		tail = dummyNode;

		length++;
	}
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
int List<x>::getLength() {
	return length;
}

/*template <class x>
List<x> ::begin() {


}
*/
/*template <class x>
void copy(const List<x> &obj) {


	if (obj.length == 0)
	{
		head = nullptr;
		length = 0;
	}
	else
	{
		Node <x>  copyHead = obj.head;
		length = obj.length;
		head = new Node <x>;
		head->data = copyHead -> data;
		Node <x> walker = head;


		while (copyHead->next != nullptr) {


			walker->next = new Node <x>;
			walker = walker->next;
			copyHead = copyHead->next;
			walker->info = copyHead->info;
		}


		walker->next = nullptr;
	}

	*/


