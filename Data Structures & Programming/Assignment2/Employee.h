//Name - Anshal Chopra
//Student ID - 301384760
//CMPT225 D200
//Assignment 2


//THE BEGINNING

#include<iostream>
#include<string>
using namespace std;


class Employee
{

private:													//member data
	string employee ;
	string id;

public:
	Employee(string employee_name, string employee_id)		//constructor with arguments
	{
		employee = employee_name;
		id = employee_id;
	}

	string getName()										//getter for the employee name
	{
		return employee;
	}

	string getID()											//getter for employee id
	{
		return id;
	}

	string toString()										//combining employee name and id
	{
		string final = getName() + " " + getID();
		return final;
	}
};

//THE END