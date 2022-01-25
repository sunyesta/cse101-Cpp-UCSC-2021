/**
 * These nodes are to be used by the AVL tree class
 * @author UCSC, Marian Zlateva
 */

#ifndef NODE_H
#define NODE_H

#include <string>

using namespace std;

class Node{
  private:
    string _data;
    
  public:
    Node *left;
    Node *right;
    int descendants;
    int levelsBelow;
  
    Node(string data);
    int getLeftCount();
    int getRightCount();
    string getData();
    int getBananceFactor();
    int getLeftLevelsBelow();
    int getRightLevelsBelow();
    void recalculateLevelsBelow();
    void recalculateDescendants();
    string toString();
};

#endif