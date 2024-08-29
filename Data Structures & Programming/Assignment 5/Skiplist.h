#include<iostream>
#include<cstring>
#include "Quadnode.h"
using namespace std;

#define MAXLVL 10
const float P = 0.5;

class SkipList {
private:

   QuadNode *head;
   int count;
   int level;

public:

   SkipList(){ // constructor
    Entry* e = new Entry(-1,"...");
    head = new QuadNode(e, MAXLVL); 
    level = 0;
    count = 0;
   }

   int size(){
       return count;
   }
  
   bool empty(){
       return size()==0;
   }
   
   Entry* find(int key){
      QuadNode *position = head; 
        
 
      for(int i = level; i >= 0; i--) 
      { 
          while(position->right[i] && 
                 position->right[i]->key < key) 
              position = position->right[i]; 
    
      } 
    

      position = position->right[0]; 
    

      if(position and position->key == key)  
          return position->entry;
      return head->entry;
     }

   void put(int k,string v){
         //Entry *entry=find(k);
        
             Entry *entry=new Entry(k,v);
             insert(entry);
             return;
         

         //entry->setData(v);
   }

   void insert(Entry *E){
   
      QuadNode *position = head; 
      int key = E->getKey();
      // create nwarray array and initialize it 
      QuadNode *nwarray[MAXLVL+1]; 
      memset(nwarray, 0, sizeof(QuadNode*)*(MAXLVL+1));

      for (int i = level; i >= 0; i--) 
      { 
          while (position->right[i] != NULL && 
                position->right[i]->key < key) 
              position = position->right[i]; 
          nwarray[i] = position; 
      } 
  
      position = position->right[0]; 

      if (position == NULL || position->key != key) 
      { 
          int rlevel = randomLevel(); 
          if (rlevel > level) 
          { 
              for (int i=level+1;i<rlevel+1;i++) 
                  nwarray[i] = head;  
              level = rlevel; 
          } 
    
          QuadNode* n = createNode(E, rlevel); 
 
          for (int i=0;i<=rlevel;i++) 
          { 
              n->right[i] = nwarray[i]->right[i]; 
              nwarray[i]->right[i] = n; 
          } 
      }

   }
 
   void erase(int key){
   
      QuadNode *position = head; 
      // create nwarray array and initialize it 
      QuadNode *nwarray[MAXLVL+1]; 
      memset(nwarray, 0, sizeof(QuadNode*)*(MAXLVL+1)); 
    
      for(int i = level; i >= 0; i--) 
      { 
          while(position->right[i] != NULL  && 
                position->right[i]->key < key) 
              position = position->right[i]; 
          nwarray[i] = position; 
      } 

      position = position->right[0]; 
    
      // If position node is target node 
      if(position != NULL and position->key == key) 
      { 

          for(int i=0;i<=level;i++) 
          { 
 
              if(nwarray[i]->right[i] != position) 
                  break; 
    
              nwarray[i]->right[i] = position->right[i]; 
          } 
    
          // Remove levels having no elements  
          while(level>0 && 
                head->right[level] == 0) 
              level--; 
              count--;
           cout<<"Successfully deleted key "<<key<<"\n"; 
      } 
   }


   Entry* greaterEntry(int key){
      QuadNode *position = head; 
          
      for(int i = level; i >= 0; i--) 
      { 
          while(position->right[i] && 
                 position->right[i]->key < key) 
              position = position->right[i]; 
    
      } 
    

      position = position->right[0]->right[0]; 
    
      // If position node have key equal to 
      // search key, we have found our target node 
      if(position and position->key > key)  
          return position->entry;
      return head->entry;
   }
 
   Entry* lessEntry(int key){
      QuadNode *position = head; 
  
      for(int i = level; i >= 0; i--) 
      { 
          while(position->right[i] && 
                 position->right[i]->key < key) 
              position = position->right[i]; 
    
      } 
    
      //position = position->right[0]; 
    
      // If position node have key equal to 
      // search key, we have found our target node 
      if(position and position->key < key)  
          return position->entry;
      return head->entry;
     
       }

   void print(){
     if(empty()){
             cout<<"Empty list"<<endl;
             return;
      }
         
        cout<<"\nSkip List"<<"\n"; 
        for (int i=level;i>=0;i--) 
        { 
            QuadNode *node = head->right[i]; 
            QuadNode *position = head->right[0];
            cout << "-inf--"; 
            while (position != NULL) 
            { 
                if(position == node){
                  cout << node->key<<"--"; 
                  node = node->right[i]; 
                }
                else{
                  if(position->key > 9)
                    cout<<"----";
                  else
                    cout<<"---";
                }
                position = position->right[0];
            } 
            cout << "inf-\n"; 
        }  
   }

  QuadNode* createNode(Entry *E, int level){ 
      QuadNode *n = new QuadNode(E, level); 
      count++;
      return n; 
  }

  int randomLevel() { 
      float r = (float)rand()/RAND_MAX; 
      int lvl = 0; 
      while (r < P && lvl < MAXLVL) 
      { 
          lvl++; 
          r = (float)rand()/RAND_MAX; 
      } 
      return lvl; 
  }
  
 
   virtual ~SkipList(){
   }
};