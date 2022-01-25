#include "LinkedList.h"

#include <iostream>
#include <cstring>

using namespace std;

/**
 * The constructor for a LinkedList
 */
LinkedList :: LinkedList(){
  _head = NULL;
}

/**
 * Deletes the linked list
 */
void LinkedList :: deleteList(){
  Node *next = NULL;
  for(Node *cur = _head; cur != NULL; cur = next){
    next = cur->next;

    delete(cur);

	}
	
  _head = NULL;
  
  
  return;
}


/**
 * Inserts a word into the linked list by either incrementing the
 * frequency of a node or creatinga new node
 *
 * @param word - the word data being inserted
 */
void LinkedList :: insert(string word){
  
  Node *cur = _head; //tracker of the current node
  
  //traverse the linked list
  while(cur!=NULL){
    
    //if a node containing the word was found, increment
    //its frequency instead of creating a new node
    if(cur->word == word){
      cur->frequency++;
      return;
    }
    
    cur = cur->next;
  }
  
  //if no node was found, create a node
  Node *newNode = new Node(word);
  newNode->next = _head;
  _head = newNode;
  
  return;
}

/**
 * Finds the nth most frequent word in the linked list 
 * given that the list is already sorted by frequency
 *
 * @param n - the requested level of "most frequent word"
 * @return - the nth most frequent word in the linked list
 */
string LinkedList :: findnthMostFrequentWord(int n){
  
  //if the list is empty, word does not exist
	if(_head == NULL){
      return "-";
	}
  
  Node *cur = _head; ////tracker of the current node
  
	//traverse the list n times
  for(int i=0; i<n; i++){
		
    cur = cur->next;
    
    //if the end of the list is reached, word does not exist
    if(cur == NULL){
      return "-";
    }
    
  }
	
	return cur->word;
}

/**
 * Sorts the linked list by frequency and, if 2 words
 * share the same frequency it sorts them alphebetically
 * 
 * bubble sort was algorithm was implemented by conpepts present here: https://www.geeksforgeeks.org/bubble-sort/ 
 */
void LinkedList :: bubbleSort(){
  
  //if the list is empty, do nothing
  if(_head == NULL){
    return;
  }
  
  //perform sorting
  bool swapped = false;
  Node *ptr1, *ptr2 = NULL;
  
  do{
    swapped = false;
    ptr1 = _head;
    
    while(ptr1->next != ptr2){
      
      if((ptr1->frequency < ptr1->next->frequency) ||
         (ptr1->frequency == ptr1->next->frequency && ptr1->word.compare(ptr1->next->word)>0)){
        
        ptr1->swapData(ptr1->next);
        swapped = true;
      }
      
      ptr1 = ptr1->next;
    }
    
    ptr2 = ptr1;
  } while(swapped);
  
  return;
}



/**
 * Prints the linked list
 */
void LinkedList :: print(){
  for(Node *cur = _head; cur != NULL; cur = cur->next){
    cur->print();
    cout<<" -> ";
  }
  
  cout<<endl;
  
  return;
}