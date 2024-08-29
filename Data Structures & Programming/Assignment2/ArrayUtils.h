//Name - Anshal Chopra
//Student ID - 301384760
//CMPT225 D200
//Assignment 2


//THE BEGINNING

#include<iostream>
#include<string>
using namespace std;

template <typename T>
class ArrayUtils					//for reversing the arrays
{
public:
	static T* reverse(T* arr, int sz)	
	{
		Stack<T> rev;				//initialising a variable with class Stack

		for(int i = 0; i<sz; i++)	//inserting elements into the variable
		{
			rev.push(arr[i]);
		}

		int j = 0;

		while(!rev.empty())
		{
			arr[j] = rev.pop();		//reversing the elements of the input array argument
			j++;
		}

		return arr;					//returning the array
	}
};

//THE END
