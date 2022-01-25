#include "Node.h"

#include <iostream>
using namespace std;

/**
 * The constructor for a Node
 */
Node :: Node(string word){
  this->word = word;
  this->frequency = 1;
  this->next = NULL;
}

/**
 * Deletes the node
 */
void Node :: deleteNode(){
  
}

/**
 * Swaps the data of 2 nodes
 *
 * @param otherNode - The node that is being swapped with the current node
 */
void Node :: swapData(Node *otherNode){
  
  //save the data of the other node
  string otherWord = otherNode->word;
  int otherFrequency = otherNode->frequency;
  
  //overwrite the data of the other node with the data of the current node
  otherNode->word = word;
  otherNode->frequency = frequency;
  
  //overwrite the data of the current node with the data of the other node
  word = otherWord;
  frequency = otherFrequency;
}

/**
 * Prints the node
 */
void Node :: print(){
  cout << this->word << " " << this->frequency;
}