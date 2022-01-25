/**
 * This Graph holds 'movie' and 'actor' nodes and has the ability 
 * to find the shortest paths between them using breadth first search
 * @author UCSC, Marian Zlateva
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>
#include <map>

#include "Node.h"

using namespace std;


class Graph{
  private:
    map <string, Node *> actors;
    int nodes;
  public:
    Graph();
    void addMovie(string movie, vector<string>movieActors);
    string getShortestPathBetweenActors(string actor1Name, string actor2Name);
    void printActors();
};

#endif