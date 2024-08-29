//Anshal Chopra
//301384760
//Assignment 4
//References : geek4geeks, algorithm tutor.

#include<iostream>
#include<string>
#include"Entry.h"
using namespace std;

class Heap 
{

private:
   Entry *arr;
   int cap;
   int cSize;
   
   void swap(Entry *a,Entry *b);
   int leftChild(int index);
   int rightChild(int index);
   int parent(int index);
   int getMax1(int i,int j,int k);
   int getMax2(int i,int j);
   int getMin(int i,int j);
   void increaseSize();

public:
   Heap(); //constructor without arguments
   Heap(int totalSize); //constructor with arguments
   int size(); //number of elements in the heap
   bool empty(); //is size = 0?
   Entry& removeMax(); //returns the maximum entry e in the heap, and deletes it
   void insert(Entry& e); //insert the entry e into the heap
   void make(Entry entries[],int n); // does the linear bottom-up makeHeap operation
   void heapifyUp(int index);
   void heapifyDown(int index);
   Entry *heapSort();
   void print();
   virtual ~Heap();
  
};

Heap::Heap() //constructor without arguments
{
   cap = 10;//default size
   arr = new Entry[cap];
   cSize = 0;
}

Heap::Heap(int totalSize) //constructor with arguments
{
   this->cap = totalSize;
   arr = new Entry[totalSize];
   cSize = 0;
}

void Heap::swap(Entry *a,Entry *b)
{
   Entry E = *a;
   *a = *b;
   *b = E;
}

int Heap::leftChild(int index)
{
   return 2*index+1;
}

int Heap::rightChild(int index)
{
   return 2*index+2;
}

int Heap::parent(int index)
{
   if(index<=0)
       return -1;
   return (index-1)/2;
}

int Heap::getMax1(int i,int j,int k)
{
   if(arr[i].getKey() >= arr[j].getKey() && arr[i].getKey() >= arr[k].getKey())
       return i;

   else if(arr[j].getKey() > arr[i].getKey() && arr[j].getKey() > arr[k].getKey())
       return j;

   else
       return k;
}

int Heap::getMax2(int i,int j)
{
   if(arr[i].getKey() >= arr[j].getKey())
       return i;
   else
       return j;
}

int Heap::getMin(int i,int j)
{
   if(arr[i].getKey() < arr[j].getKey())
           return i;
       else
           return j;
}

void Heap::increaseSize()
{
   Entry *newArr = new Entry[cap*2];

   for(int i=0;i<cap;i++)
       newArr[i] = arr[i];

   Entry *temp = arr;
   delete [] temp;
   arr = newArr;
   cap = cap*2;
}

int Heap::size() //number of elements in the heap
{
   return cSize;
}

bool Heap::empty() //is size = 0?
{
   return cSize == 0;
}

Entry& Heap::removeMax() //returns the maximum entry in the heap, and deletes it
{
   Entry& temp = arr[0];
   cSize--;
   heapifyDown(0);
   return temp;
}

void Heap::insert(Entry &e) //insert the entry e into the heap
{
   if(size() == cap)
       increaseSize();
   arr[cSize] = e;
   cSize++;
   heapifyUp(cSize-1);
}

void Heap::make(Entry entries[],int n) //does the linear bottom-up makeHeap operation
{
   for(int i = 0; i < n; i++)
       arr[i] = entries[i];
   cSize = n;
   for(int i = n-1; i >= 0; i--)
       heapifyDown(i);
}

void Heap::heapifyDown(int index)
{
   if(empty())
       return;
   if(index < 0)
       return;
   while(index < cSize)
   {
       int l = leftChild(index);
       int r = rightChild(index);
       int i;
       if(l < cSize && r < cSize)
           i = getMax1(index,l,r);

       else if(l < cSize)
           i=getMax2(index,l);

       else
           return;

       if(i == index)
           return;

       swap(&arr[index],&arr[i]);
       index = i;
   }
}

void Heap::heapifyUp(int index)
{
   if(index >= cSize || index <= 0)
       return;
   while(index > 0)
   {
       int p = parent(index);
       int i = getMin(index,p);
       if(i == index)
           return;
       swap(&arr[index],&arr[p]);
       index = p;
   }
}

Entry* Heap::heapSort()
{
   for (int i = cSize-1; i > 0; i--)
   {
       swap(&arr[0], &arr[i]);
       cSize--;
       heapifyDown(0);
   }
   return arr;
}

void Heap::print()
{
   for(int i = 0; i < cSize; i++)
       cout << arr[i].toString() << " ";
   cout << "\n";
}

Heap::~Heap() //destructor
{
   delete []arr;
}
