/**
 * A node could be either a movie or actor type. Each node
 * stores the movie/actor's name and connections(neighbors)
 * @author UCSC, Marian Zlateva
 */

#include <iostream>
#include <assert.h>

#include "Node.h"

using namespace std;


Node :: Node(nodeType type, string name){
  this->type = type;
  this->name = name;
}

/**
 * @return - the name of the movie/actor stored in the node
 */
string Node :: getName(){
  return name;
}

/**
 * checks if a node is a specific type
 * 
 * @param type - the nodeType you are trying to check for
 * 
 * @return true if type matches the node's type
 */
bool Node :: isA(nodeType type){
  return this->type == type;
}

/**
 * @return - the node's connections
 */
vector<Node *> Node :: getConnections(){
  return connections;
}

/**
 * adds a connection to the node
 * 
 * @param node - the node we are connecting to this node
 */
void Node :: addConnection(Node *node){
  //there will never be a case where we need to check if a node is already in the map
  connections.push_back(node);
}

/**
 * @return - a string representing the node's data
 */
string Node :: toString(){
  string printString = "";
  
  printString += "\"" + name + "\"\n";
  
  printString += "\tConnections:\n";
  
  for(Node *cur : connections){
    printString += "\t" + cur->getName() + "\n";  
  }
  
  return printString;
}