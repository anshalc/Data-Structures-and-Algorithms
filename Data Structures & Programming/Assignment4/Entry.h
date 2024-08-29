//Anshal Chopra
//301384760
//Assignment 4
//References : geek4geeks, algorithm tutor.

#include<iostream>
#include<string>
#include<random>
#include<time.h>
using namespace std;

class Entry
{
    private:

        int key;
        string data;
    
    public:
        Entry(){ random(); } //constructor

        void random()
        {         
            key = rand()%100;//Returns random key 0-99 inclusive
            data = "";
            char character;
            for(int i=0;i<3;i++)
            {
                character = 'a' + rand()%26;
                data += character; //Return 3 random characters in form of a string
            }
        };       
    
        int getKey() const 
        {
            return key;
        }

        string getData() const 
        {
            return data;
        }

        string toString() const 
        { 
            return "(" + to_string(key) + "," + data+ ")";
        }
        
        ~Entry(){};//destructor
};