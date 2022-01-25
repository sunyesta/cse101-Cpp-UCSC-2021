#ifndef LIST_H
#define LIST_H

#include <string>

#include "Node.h"
using namespace std;



class LinkedList{
  private:
    Node *_head;
    void addNode(string, Node*);
    void bubbleSort(Node*);
    
  public:
    LinkedList();
    void insert(string);
    string findnthMostFrequentWord(int);
    void bubbleSort();
    void print();
    void deleteList();
  
  
};

#endif