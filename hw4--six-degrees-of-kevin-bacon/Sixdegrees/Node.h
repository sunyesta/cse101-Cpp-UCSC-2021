/**
 * A node could be either a movie or actor type. Each node
 * stores the movie/actor's name and connections(neighbors)
 * @author UCSC, Marian Zlateva
 */

#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>

using namespace std;

enum nodeType {MOVIE, ACTOR};

class Node{
  private:
    nodeType type;
    string name;
    vector<Node *>connections;
    
  public:
    Node(nodeType type, string name);
    void addConnection(Node *);
    string getName();
    bool isA(nodeType type);
    vector<Node *> getConnections();
    string toString();
};

#endif