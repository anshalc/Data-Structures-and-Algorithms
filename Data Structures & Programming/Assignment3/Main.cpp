//Name - Anshal Chopra
//Student ID - 301384760
//CMPT225 D200
//Assignment 2

#include<iostream>
#include"ArrayList.h"
using namespace std;

void testArrayListUnderflow(){
	int size=4;
	try{
		ArrayList<int> array;

		array.insertFront(1);
		array.removeFront();
		array.removeFront();
		cout<<"did not catch exception"<<endl;
		}
	catch(EmptyListException){
		cout<<"caught EmptyStackException"<<endl;
	}
	try{
		ArrayList<int> array;

		array.insertBack(7);
		array.removeBack();
		array.removeBack();
		cout<<"did not catch exception"<<endl;
		}
	catch(EmptyListException){
		cout<<"caught EmptyStackException"<<endl;
	}

	try{
		ArrayList<int> array;

		array.insertFront(5);
		// P is the iterator begin()
		array.remove(0);
		array.remove(0);
		cout<<"did not catch exception"<<endl;
		}
	catch(EmptyListException){
		cout<<"caught EmptyStackException"<<endl;
	}
	
	cout<<"\n\n"<<endl;
}

void testIntergerIterator(){
	ArrayList<int> array;
	array.insertBack(1);
	array.insertBack(2);
	array.insertBack(3);
	array.insertBack(4);
	array.insertBack(5);
	array.insertBack(6);

	for(ArrayList<int>::Iterator iter = array.begin(); iter != array.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl;
	array.removeFront();
	array.removeFront();
	array.removeFront();
	array.insertBack(4);
	array.insertBack(5);
	array.insertBack(6);
	for(ArrayList::Iterator iter = array.begin(); iter != array.end(); iter++) {
		cout << *iter << " ";
	}	
	cout<<"\n\n"<<endl;
}

void testStringIterator(){
	ArrayList<string> array;
	array.insertBack("Hi");
	array.insertBack("My");
	array.insertBack("Name");
	array.insertBack("Is");
	array.insertBack("Anshal");
	array.insertBack("Chopra");
	for(ArrayList<string>::Iterator iter = array.begin(); iter != array.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl;
	array.removeFront();
	array.removeFront();
	array.removeFront();
	array.insertBack("Is");
	array.insertBack("Anshal");
	array.insertBack("Chopra");
	ArrayList<int>:: Iterator iter;
	for(iter = array.begin(); iter != array.end(); iter++) {
		cout << *iter << " ";
	}	

	cout<<"\n\n"<<endl;
}

int main(){
	cout<<"Testing functions created"<<endl;
	testArrayListUnderflow();
	testIntergerIterator();
	testStringIterator();
	return 0;
}
