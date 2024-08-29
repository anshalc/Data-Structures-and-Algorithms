//Anshal Chopra
//301384760
//Assignment 4
//References : geek4geeks, algorithm tutor.

#include<iostream>
#include "Heap.h"
using namespace std;


void print(Entry arr[], int n) 
{
for (int i=0; i<n; ++i)
cout << arr[i].toString() << " ";
cout << "\n";
}

void heapsort1(Entry arr[],int n)
{
   Heap H(n);
   for(int i=0;i<n;i++)
       H.insert(arr[i]);
   arr=H.heapSort();
   cout<<"Array 1 after sorting:\n";
   print(arr,15);
}

void heapsort2(Entry arr[],int n)
{
   Heap H(n);
   H.make(arr, n);
   arr=H.heapSort();
   cout<<"Array 2 after sorting:\n";
   print(arr,31);
}

//main function
int main()
{
   srand(time(0));

   Entry E1[15];
   Entry E2[31];
   cout<<"Array 1 before sorting:\n";
   print(E1,15);
   heapsort1(E1,15);
   cout<<endl;
   cout<<"Array 2 before sorting:\n";
   print(E2,31);
   heapsort2(E2,31);
}
