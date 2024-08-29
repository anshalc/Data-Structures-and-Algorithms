//Name - Anshal Chopra
//Student ID - 301384760
//CMPT225 D200
//Assignment 1



class Animal //parent class / superclass
{
private:

	int age;   //private information

public:

	Animal() : age(1){} //Constructor 1, with no arguments, setting the default age to 1 month

	Animal(int ageOfAnimals) //Constructor 2, with the age of the animal as the argument
	{
		age = ageOfAnimals;
	}

	virtual string noise() const //virtual function for late binding
	{
		return "Hmmmm";
	}

	static int repeats() //for all the repeats() to lay out the same value.
	{
		return 3;
	}

	const int ageinMonths() //returns the age of the animal (inherited by subclasses)
	{
		return age;
	}

	void print() //prints the age and the noise of the animal.(inherited by subclasses)
	{
		cout<<ageinMonths()<<" ";
		for(int i = 0; i < repeats(); i++)
		{
			cout<<noise()<<" ";
		}
		cout<<"\n\n"; //prints space
	}


};


class Wolf: public Animal //child class / subclass1
{
public:

	Wolf() : Animal(1){} //Constructor 1  with no arguments

	Wolf(int ageOfWolf) : Animal(ageOfWolf) //Constructor 2 with 1 argument
	{}

	string noise() const //declared virtual before
	{
		return "Grrrr";
	}

	int repeats() //static function
	{
		return 2;
	}

};


class Cow: public Animal //child class / subclass2
{
public:

	Cow() : Animal(1){} //Constructor 1  with no arguments

	Cow(int ageOfCow) : Animal(ageOfCow) //Constructor 2 with 1 argument
	{}

	string noise() const //declared virtual before
	{
		return "Moohh";
	}

	int repeats() //static function
	{
		return 1;
	}


};


class Pig: public Animal //child class / subclass3
{
public:

	Pig() : Animal(1){} //Constructor 1  with no arguments

	Pig(int ageOfPig) : Animal(ageOfPig) //Constructor 2 with 1 argument
	{}

	string noise() const //declared virtual before
	{
		return "Oinkk";
	}

	int repeats() //static function
	{
		return 3;
	}

};


class Snake: public Animal //child class / subclass4
{
public:

	Snake() : Animal(1){} //Constructor 1  with no arguments

	Snake(int ageOfSnake) : Animal(ageOfSnake) //Constructor 2 with 1 argument
	{}

	string noise() const //declared virtual before
	{
		return "Sssss";
	}

	int repeats() //static function
	{
		return 4;
	}

};
