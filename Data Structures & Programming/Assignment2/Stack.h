//Name - Anshal Chopra
//Student ID - 301384760
//CMPT225 D200
//Assignment 2


//THE BEGINNING

#include<iostream>
#include<string>
using namespace std;


class EmptyStackException //error handling class
{
	private:

		string errorMsg;

	public:

		EmptyStackException(const string& err)
		: errorMsg(err) { };

		string getMessage() const 
		{
			return errorMsg;
		}	
};


template<typename T>
class Stack
{ 

private:									//member data
	T* array;								//array of stack elemts
	int cap;								//stack capacity
	int position;							// index of the top of the stack

public:
	Stack();								//constructor with no arguments
	Stack(int cap);							//constructor with 1 argument
	int size() const;						//number of items in the stack
	int capacity();							//stack capacity
	bool empty() const;						//is the stack empty?
	void push(const T& elem);				//push element onto stack
	T& pop() throw(EmptyStackException);	//pop the stack
	~Stack();								//destructor

};


template <typename T> Stack<T> :: Stack()
:array(new T[4]), cap(4), position(-1) { }				//constructor without capacity


template <typename T> Stack<T> :: Stack(int cap)
:array(new T[cap]), cap(this->cap), position(-1) { } 	//constructor with capacity


template <typename T> int Stack<T> :: size() const 		//number of elemts in the stack
{
	return (position + 1);
}


template <typename T> int Stack<T> :: capacity()		//capacity of the stack
{
	return cap;
}


template<typename T> bool Stack<T>:: empty() const  	//is the stack empty?
{
	return(position<0);
}


template<typename T> void Stack<T> :: push(const T& elem) //push items onto stack
{
	if(size() == capacity())
	{ 
		cap = 2* cap;							//doubles the size if size tends to exceed capacity
		T* newArray = new T[cap];

		for(int i = 0; i< size(); i++)
		{
			newArray[i] = array[i];				
		}

		delete[]array;
		array = new T[cap];						//reinitializing the array to get the elements back to it
												//array with 2*cap
		for(int i = 0; i< size(); i++)
		{
			array[i] = newArray[i];
		}

		delete[]newArray;						//deleting the new array created
	}						

		position++;
		array[position] = elem;
}


template<typename T> T& Stack<T> :: pop() throw(EmptyStackException)	//pop the stack and returning the element popped
{
	if(empty()) throw(EmptyStackException("pop from empty stack"));
	T& element = array[position];
	position--;
	return element;
} 


template<typename T> Stack<T> :: ~Stack() //destructor
{
	delete [] array;
	position = -1;
}

//THE END