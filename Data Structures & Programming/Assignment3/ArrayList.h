//Name - Anshal Chopra
//Student ID - 301384760
//CMPT225 D200
//Assignment 2

#include<iostream>
#include<string>
using namespace std;

class EmptyListException //error handling class
{
	private:

		string errorMsg;

	public:

		EmptyListException(const string& err)
		: errorMsg(err) { };

		string getMessage() const 
		{
			return errorMsg;
		}	
};

class InvalidIteratorException //error handling class
{
	private:

		string errorMsg;

	public:

		InvalidIteratorException(const string& err)
		: errorMsg(err) { };

		string getMessage() const 
		{
			return errorMsg;
		}	
};
template<typename T>
class ArrayList
{

private:

	int capacity;
	int numOfElem;
	int start;
	int rear;
	T* array;


public:

	class Iterator
	{
	public:
		Iterator(){}

		T* array1;
		Iterator(T* array2) //constructor for the class Iterator
		{
			array1 = array2;
		}

		T& operator*() //gives the reference to the object at the iterator position
		{
			return *array1;
		}

		Iterator operator++() //moves the iterator one forward in the ArrayList
		{
			*array1 = *(++array1);
			return *this;
		}

		Iterator operator--() //moves the iterator one backward in the ArrayList
		{
			*array1 = *(--array1);
			return *this;
		}

		bool operator==(Iterator& i) const // compares the iterator with the iterator i
		{
			return (*array1 == *(i.array1));
		}

		bool operator!=(Iterator& i) const
		{
			return (array[0] != i.array[0]);
		}

	};

	ArrayList()
	:capacity(4), numOfElem(0), start(0), rear(0)
	{
		array = new T[capacity];
	}

	T& operator[](int i) //returns the element at index i of the ArrayList
	{
		return array[i];
	}

	T& front() //returns the element at the front of the ArrayList
	{
		return array[start];
	}

	T& back() // returns the element at the back of the ArrayList
	{
		return array[rear-1];
	}

	void capacityRedefine(int elements)
	{
		if(numOfElem > capacity)
		{
			
		capacity = 2* capacity;							//doubles the size if size tends to exceed capacity
		T* newArray = new T[capacity];

		for(int i = 0; i< size(); i++)
		{
			newArray[i] = array[i];				
		}

		delete[]array;
		array = new T[capacity];						//reinitializing the array to get the elements back to it
												//array with 2*cap
		for(int i = 0; i< size(); i++)
		{
			array[i] = newArray[i];
		}

		delete[]newArray;
		}

	}

	void insertFront(const T& e) //insert at the front of the ArrayList
	{
		numOfElem++;

		capacityRedefine(numOfElem);

		for(int i = rear; i>start; i--)
		{
			array[i] = array[i-1];
		}
		array[start] = e;
	}

	void insertBack(const T& e) //insert at the back of the ArrayList
	{
		numOfElem++;
		capacityRedefine(numOfElem);
		array[rear] = e;
		rear = (rear+1) % capacity;
	}

	void insert(const Iterator &p, const T& e) //insert before the iterator p.
	{
		numOfElem++;
		capacityRedefine(numOfElem);
		T* array3 = p.array1;
		int i = 0;
		while(array[i] != *(p.array1))
		{
			i++;
		}
		for(int j = numOfElem; j > i; j--)
		{
			array[j] = array[j-1];
		}
		array[i] = e;
	}


	void removeFront() throw(EmptyListException) //removes the front element of the ArrayList
	{
		if(empty()) throw (EmptyListException("removing from empty list"));
		numOfElem--;
		start = (start+1) % capacity;
	}

	void removeBack() throw(EmptyListException) //removes the back element of the ArrayList
	{
		if(empty()) throw (EmptyListException("removing from empty list"));
		numOfElem--;
		rear = (rear-1) % capacity;
	}

	void remove(const Iterator& p) throw(EmptyListException) //removes the element at the iterator p from the ArrayList
	{
		if(empty()) throw (EmptyListException("removing from empty list"));
		numOfElem--;
		T* array1 = p.array1;
		int i = 0;
		while(array[i] != *(p.array1))
		{
			i++;
		}
		for(int j = numOfElem; j>i ; j--)
		{
			array[j+1] = array[j];
		}
	}

	int size() //number of elements int the ArrayList
	{
		return numOfElem;
	}

	bool empty() //is size = 0?
	{
		return (numOfElem == 0);
	}

	Iterator begin()  //an iterator to the first element
	{
		return Iterator(array);

	}

	Iterator end()  //an iterator to the last element
	{
		for(int i=0;i<numOfElem;i++)
		{
			*(array++);
		}
		return Iterator(array);

	}

	~ArrayList()
	{
		delete[] array;
		capacity = 4;
		numOfElem = 0;
		start = 0;
		rear =0;
	}
};

