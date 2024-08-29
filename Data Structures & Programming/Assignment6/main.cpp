#include<iostream>
#include "AVLTree.h"
using namespace std;

int main() {

	AVLTree b;
	AVLTree t1;
	int c, x,count;
	node* temp = b.first;
	bool found = false;
	cout << "Now Inserting 7 entries : " << endl;
	t1.first = t1.insertNode(t1.first, 5);
	t1.first = t1.insertNode(t1.first, 45);
	t1.first = t1.insertNode(t1.first, 98);
	t1.first = t1.insertNode(t1.first, 99);
	t1.first = t1.insertNode(t1.first, 7);
	t1.first = t1.insertNode(t1.first, 67);
	t1.first = t1.insertNode(t1.first, 55);
	cout << endl << "Now Displaying : " << endl;
	t1.leveling();
	cout << endl << "Deleting one entry: " << endl;
	t1.first = t1.deleteNode(t1.first,99);
	cout << endl << "Now Displaying : " << endl;
	t1.leveling();
	cout << endl << "Now finding the element : " << endl;
	t1.find(t1.first,temp, 56, found);
	if (!found)
		cout << "Element doesn't exist ! " << endl;
	else
		cout << "Element found!!" << endl;
	t1.find(t1.first, temp, 67, found);
	if (!found)
		cout << "Element doesn't exist ! " << endl;
	else
		cout << "Element found!!" << endl;
	t1.first = t1.deleteNode(t1.first, 5);
	t1.first = t1.deleteNode(t1.first, 45);
	t1.first = t1.deleteNode(t1.first, 98);
	t1.first = t1.deleteNode(t1.first, 7);
	t1.first = t1.deleteNode(t1.first, 67);
	t1.first = t1.deleteNode(t1.first, 55);

	cout << endl << "Now inserting 15 entries into an empty tree: " << endl;

	t1.first = t1.insertNode(t1.first, 554);
	t1.first = t1.insertNode(t1.first, 4567);
	t1.first = t1.insertNode(t1.first, 984);
	t1.first = t1.insertNode(t1.first, 9);
	t1.first = t1.insertNode(t1.first, 712);
	t1.first = t1.insertNode(t1.first, 673);
	t1.first = t1.insertNode(t1.first, 555);
	t1.first = t1.insertNode(t1.first, 53);
	t1.first = t1.insertNode(t1.first, 4);
	t1.first = t1.insertNode(t1.first, 8);
	t1.first = t1.insertNode(t1.first, 997);
	t1.first = t1.insertNode(t1.first, 70);
	t1.first = t1.insertNode(t1.first, 670);
	t1.first = t1.insertNode(t1.first, 550);
	t1.first = t1.insertNode(t1.first, 30);

	cout << endl << "Now Displaying : " << endl;
	t1.leveling();
	cout << endl << "Deleting five entries: " << endl;
	t1.first = t1.deleteNode(t1.first, 554);
	t1.first = t1.deleteNode(t1.first, 70);
	t1.first = t1.deleteNode(t1.first, 8);
	t1.first = t1.deleteNode(t1.first, 4);
	t1.first = t1.deleteNode(t1.first, 9);


	cout << endl << "Now Displaying : " << endl;
	t1.leveling();

}