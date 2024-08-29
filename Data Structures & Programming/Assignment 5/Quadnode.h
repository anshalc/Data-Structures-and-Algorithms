#include "Entry.h"
#include<cstring>
class QuadNode {
    
  public:

    Entry * entry;
    QuadNode * prev;
    QuadNode * next;
    QuadNode **right;
    QuadNode **left; 

    int key;
    

  QuadNode(Entry * entry,int count)
  {
    this -> entry = entry;
    right = new QuadNode*[count+1]; 
    left = new QuadNode*[count+1];
    this->key = entry->getKey();

    memset(right, 0, sizeof(QuadNode*)*(count+1));
    memset(left, 0, sizeof(QuadNode*)*(count+1)); 
 
  }
  
  Entry * getEntry() {return entry;}

  void setEntry(Entry * entry) { this -> entry = entry;}

  QuadNode * getNext() {return next;}

  QuadNode * getPrevious() {return prev;}
  
  void setNext(QuadNode * next) { this -> next = next;}
  
  void setPrevious(QuadNode * prev) { this -> prev = prev;}

  virtual~QuadNode() {}
};