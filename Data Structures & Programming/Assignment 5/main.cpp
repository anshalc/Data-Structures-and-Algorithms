#include<iostream>
#include <cstdlib>
#include<cstring>
#include "Skiplist.h"
using namespace std;

int main(){
        
        SkipList list1;

        SkipList list;
        list.put(1,"one");
        list.put(2, "two");
        list.put(3, "three");
        list.put(4, "four");
        list.put(5, "five");
        list.put(6, "six");
        list.put(7, "seven");
        list.put(8, "eight");

        cout << "Printing initial list" << endl;//printing the skip list
       
        list.print();


        cout << "Deleting the entry 4 from skip list" << endl;//deleting an entry
        list.erase(4);

        cout << "Printing list after deleting entry 4" << endl;
       
        list.print();

        cout << "Finding element with key 2:" << list.find(2)->toString()<<endl; //finding an element that exists
        

        cout << "finding element with key 4:" <<list.find(4)->toString()<< endl; //finding deleted element
       
        cout << "greaterEntry  for element with key 3:" <<list.greaterEntry(5)->toString()<<endl; //greater entry

        cout << "lessEntry for element with key 4:" <<list.lessEntry(4)->toString()<<endl;  //lesser entry

        //generate a list with 40 random entries
        SkipList newlist;
        for (int i = 0;i < 40;i++) {
                newlist.insert(new Entry());
        }
        
        newlist.print();
    return 0;
}