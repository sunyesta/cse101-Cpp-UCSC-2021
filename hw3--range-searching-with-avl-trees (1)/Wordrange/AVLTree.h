/**
 * This AVL tree holds strings
 * @author UCSC, Marian Zlateva
 */

#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <string>

#include "Node.h"

using namespace std;


class AVLTree{
  private:
    Node *_root;
    Node *insert(string data, Node *cur, bool &success);
    Node *balanceSubtree(Node *root, string lastAddedData);
    Node *rotateLeft(Node *root);
    Node *rotateRight(Node *root);
    int getLessThanTarget(Node *cur, string target);
    int getGreaterThanTarget(Node *cur, string target);
    void print(string prefix, Node *cur, bool isLeft);
    
  public:
    AVLTree();
    void insert(string data);
    int countBtwn(string start, string end);
    void print();
};

#endif