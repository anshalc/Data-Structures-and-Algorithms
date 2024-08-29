//Name - Anshal Chopra
//Student ID - 301384760
//CMPT225 D200
//Assignment 1
#include<iostream>
#include<string>
using namespace std;

#include"Assignment1.h"
int main()
{ 
//Initialising variables with classes and subclasses

	Animal A(10);
	A.print();

	Wolf W(28);
	W.print();

	Cow C(21);
	C.print();

	Pig P(6);
	P.print();

	Snake S(12);
	S.print();

//Creating 2D dynamic array of class Animal

	Animal **animals;
	animals = new Animal*[10];
	animals[0] = new Cow(10);
	animals[1] = new Pig(16);
	animals[2] = new Animal(22);
	animals[3] = new Snake(6);
	animals[4] = new Wolf(4);
	animals[5] = new Cow(52);
	animals[6] = new Pig(18);
	animals[7] = new Cow(8);
	animals[8] = new Snake(19);
	animals[9] = new Wolf(32);

	for(int i = 0; i < 10; i++)
	{
		animals[i]->print();
		delete[]animals[i]; //deallocating the array
	}

	delete[]animals; //deallocating the array
	
}
