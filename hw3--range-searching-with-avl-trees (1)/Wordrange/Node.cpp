/**
 * These nodes are to be used by the AVL tree class
 * @author UCSC, Marian Zlateva
 */

#include <iostream>
#include <assert.h>

#include "Node.h"

using namespace std;

/**
 * Constructor for a node
 * 
 * @param data - the data going into the node
 */
Node :: Node(string data){
  _data = data;
  
  descendants = 0;
  levelsBelow = 0;
  
  left = NULL;
  right = NULL;
}

/**
 * @return - the data in the node
 */
string Node :: getData(){
  return _data;
}

/**
 * calculates the balance factor of a node
 * 
 * @return - the balance factor of the node
 */
int Node :: getBananceFactor(){  
  return getLeftLevelsBelow()-getRightLevelsBelow();
}

/**
 * gets the levels below the current node that are strictly to the left
 * 
 * @return - number of levels below the node that are to the left
 */
int Node :: getLeftLevelsBelow(){
  if(left){
    return left->levelsBelow + 1;
  }else{
    return 0;
  }
}

/**
 * gets the levels below the current node that are strictly to the right
 * 
 * @return - number of levels below the node that are to the right
 */
int Node :: getRightLevelsBelow(){
  if(right){
    return right->levelsBelow + 1;
  }else{
    return 0;
  }
}

/**
 * recalculates the levels below the current node
 * NOTE: requires left and right nodes to have correct levels below count
 */
void Node :: recalculateLevelsBelow(){
  levelsBelow = max(getLeftLevelsBelow(), getRightLevelsBelow());
}

/**
 * gets the descendants that are strictly to the left of the current node
 * 
 * @return - number of descendants strictly to the left
 */
int Node :: getLeftCount(){
  
  if(left){
    //left node + its descendants
    return 1 + left->descendants;
  }else{
    return 0;
  }
}

/**
 * gets the descendants that are strictly to the right of the current node
 * 
 * @return - number of descendants strictly to the right
 */
int Node :: getRightCount(){
  if(right){
    //right node + its descendants
    return 1 + right->descendants;
  }else{
    return 0;
  }
}

/**
 * recalculates the descendants of the current node
 * NOTE: requires left and right nodes to have correct descendants count
 */
void Node :: recalculateDescendants(){
  descendants = getLeftCount() + getRightCount();
}

/**
 * @return - the default string for a node
 */
string Node :: toString(){
  string txt = "[" + ((string)_data) + ", dec=" + to_string(descendants) + ", levelsBelow=" + to_string(levelsBelow) +"]";
  return txt;
}