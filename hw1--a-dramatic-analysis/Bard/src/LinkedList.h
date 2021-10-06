#ifndef LIST_H
#define LIST_H

#include <string>

using namespace std;

struct Node{
      string word;
      int frequency;
      Node *next;
};


class LinkedList{
  private:
    Node *head;
    void addNode(string, Node*);
  public:
    LinkedList();
    void insert(string);
    void print();
  
  
};

#endif