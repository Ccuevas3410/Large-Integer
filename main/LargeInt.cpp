#include "pch.h"
#include "doublyList.cpp"
#include "LargeInt.h"

#include <string>
#include <iostream>
using namespace std;


LargeInt::LargeInt()
{
}


LargeInt::~LargeInt()
{
}

LargeInt ::LargeInt(const doublyList<int> &l)
{
	digits = l;
}
//OVERLOADING STREAM EXTRACTION OPERATOR
istream &operator>>(istream &input,  LargeInt &list) {
	

	
	string numbers = " ";
	int pos = 0;

	input >> numbers;

	if (numbers[0] == '-')
	{
		list.sign = true;
		pos = 1;

	}
	for (int i = pos; i < numbers.length(); i++)
	{

		list.digits.append(numbers[i] - '0');

	}
	return input;
	

}

// OUT STREAM TO PRINT THE NUMBERS/LIST
ostream &operator<<(ostream &output, LargeInt list) {

	Iterator<int> i = list.digits.begin();
	if (list.sign)
	{
		cout << "-";
	}

	for (; i != list.digits.end(); i++)
	{
		output << *i;
	}

	return output;
}


LargeInt LargeInt::operator+( LargeInt &obj) {
	LargeInt result;

	Iterator <int> i = digits.last();
	Iterator <int> j= obj.digits.last();

	int carry = 0;

	int sizeOne = digits.length;
	int sizeTwo = obj.digits.length;

	
	if (sizeOne <= sizeTwo)
	{
		for (; i != digits.end(); i--)
		{
			result.digits.insertItemFirst((*i + *j + carry) % 10);
			carry = (*i + *j) / 10;
			j--;
		}
		for ( ; j!= obj.digits.end();j--)
		{
			result.digits.insertItemFirst((*j + carry) % 10);
			carry = ( *j+carry) / 10;

		}

		if (carry!=0)
		{
			result.digits.insertItemFirst(carry);
		}


		
	}
	else
	{
		for (; j != digits.end(); j--)
		{
			result.digits.insertItemFirst((*i + *j + carry) % 10);
			carry = (*i + *j) / 10;
			i--;
		}
		for (; i != obj.digits.end(); i--)
		{
			result.digits.insertItemFirst((*i + carry) % 10);
			carry = (*i + carry) / 10;

		}

		if (carry != 0)
		{
			result.digits.insertItemFirst(carry);
		}


	}

	

	return result;
}



LargeInt LargeInt::operator-(LargeInt &obj) {
	LargeInt result;

	Iterator <int> i = digits.last();
	Iterator <int> j = obj.digits.last();

	int borrow = 0;

	int sizeOne = digits.length;
	int sizeTwo = obj.digits.length;


	if (sizeOne <= sizeTwo)
	{
		for ( ; i != digits.end(); i--)
		{
			if (*j< *i) {
				result.digits.insertItemFirst((*j + 10) - borrow - *i);
				borrow = 1;

			}
			else
			{
				result.digits.insertItemFirst((*j - borrow) - *j);
				borrow = 0;
			}
			j--;
		}
	}

	return result;
}

