


#include "pch.h"  
#include "doublyList.cpp"  
#include "doublyList.h"  
#include "LargeInt.h"

#include <iostream>  
#include <assert.h> 
#include <string>


using namespace std;

int main()
{
	
	LargeInt numberOne;
	LargeInt numberTwo;
	LargeInt result;

	cout << "Enter your first number: ";
	cin >> numberOne;
	cout << "Enter your second number: ";
	cin >> numberTwo;

	

	result = numberOne - numberTwo;

	cout << result;
	

	return 0;
}