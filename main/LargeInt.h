#pragma once

#include "doublyList.h"
#include <iostream> 
#include <string>

using namespace std;

//FORWARD DECLARATION
template <class x> class doublyList;
template <class x> class Iterator;
class LargeInt;

class LargeInt
{

	friend ostream & operator<< (ostream &, LargeInt list);
	friend istream & operator>> (istream &,  LargeInt &list);
private:

	doublyList <int> digits;
	


	doublyList <int> add(const LargeInt&, const LargeInt&);
	bool size;
	bool sign;
	
public:
	LargeInt();
	LargeInt(int);
	LargeInt(const doublyList<int> &);
	~LargeInt();
	


	LargeInt operator+( LargeInt &);

	LargeInt operator-( LargeInt &);
	LargeInt operator*(const LargeInt &);
	LargeInt operator/(const LargeInt &);
	LargeInt operator%(const LargeInt &);
//	LargeInt operator+(const LargeInt &);


	

	
};

