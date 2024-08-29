//Name - Anshal Chopra
//Student ID - 301384760
//CMPT225 D200
//Assignment 2


//THE BEGINNING

#include<iostream>
#include<string>
#include"Stack.h"
#include"Employee.h"
#include"ArrayUtils.h"
using namespace std;

void testStackUnderflow()   //test for whtether the error exception worked 
{
	try
	{
		Stack<int> test;
	
		test.push(5);
		test.pop();
		test.pop();
		cout<<"did not catch exception";
		
	}

	catch(EmptyStackException)
	{
		cout<<"\n\nError Caught: EmptyStackException\n\n";
	}
}


void testStackGrowth()
{
	Stack<int> test;	//test whether the capacity gets increased or not
	for(int i = 1; i<6; i++)
	{
		test.push(i);
		cout<<"Pushed Element: "<<i<<"\n";
	}
	cout<<"\nCapacity(5 elements): "<<test.capacity()<<"\n\n";

	for(int i = 6; i< 10; i++)
	{
		test.push(i);
		cout<<"Pushed Element: "<<i<<"\n";

	}
	cout<<"\nCapacity(9 elements): "<<test.capacity()<<"\n\n";
}


void testReverseIntegers()	//test whether ArrayUtils reverse the arrays
{
	int A[12] = {1, 2, 3, 4, 5, 6,
				 7, 8, 9, 10, 11, 12};

	cout<<"Correct Order: ";			 
	for(int i = 0; i < 12; i++)
	{
		cout<<A[i]<<" | ";
	}
	cout<<"\n";

	ArrayUtils<int>::reverse(A, 12); //reverse function
	
	cout<<"Reverse Order: ";
	for(int i = 0; i < 12; i++)
	{
		cout<<A[i]<<" | ";
	}
	cout<<"\n\n";
	
}


void testReverseStrings()	//test whether ArrayUtils reverse the arrays
{
	string A[12] = {"Ram", "Shyam", "Anshal", "Arrsh",
		 "Jyotiraditya", "Archit", "Anisha",
		 "Sanya", "Rachit", "Sayyam", "Saheb",
		 "Anshuman"};

	cout<<"Correct Order: ";			 
	for(int i = 0; i < 12; i++)
	{
		cout<<A[i]<<" | ";
	}
	cout<<"\n";

	ArrayUtils<string>::reverse(A, 12);	//reverse function

	cout<<"Reverse Order: ";
	for(int i = 0;i<12;i++)
	{
		cout<<A[i]<<" | ";
	}
	cout<<"\n\n";
	
}


void testReverseEmployees()	//test whether ArrayUtils reverse the arrays
{
	Employee E[12] = {{"Ram", "1"}, {"Shyam", "2"}, {"Anshal", "3"}, {"Arrsh", "4"},
		 {"Jyotiraditya", "5"}, {"Archit", "6"}, {"Anisha", "7"},
		 {"Sanya", "8"}, {"Rachit", "9"}, {"Sayyam", "10"}, {"Saheb", "11"},
		 {"Anshuman", "12"}};

	string A[12];
	for(int i = 0;i<12 ; i++)
	{
		A[i] = E[i].toString();
	}

	cout<<"Correct Order: ";			 
	for(int i = 0; i < 12; i++)
	{
		cout<<A[i]<<" | ";
	}
	cout<<"\n";

	ArrayUtils<string>::reverse(A, 12); //reverse function

	cout<<"Reverse Order: ";
	for(int i = 0;i<12;i++)
	{
		cout<<A[i]<<" | ";
	}
	cout<<"\n\n";

}

int main()  //main function
{
	testStackUnderflow();	//test for whtether the error exception worked 

	testStackGrowth();	//test whether the capacity gets increased or not

	testReverseIntegers();	//test whether ArrayUtils reverse the arrays

	testReverseStrings();	//test whether ArrayUtils reverse the arrays

	testReverseEmployees();	//test whether ArrayUtils reverse the arrays
}

//THE END