#ifndef NODE_H
#define NODE_H

#include <string>

using namespace std;


class Node{
  public:
    string word;
    int frequency;
    Node *next;
    
    Node(string);
    void deleteNode();
    void swapData(Node*);
    void print();
  
};

#endif