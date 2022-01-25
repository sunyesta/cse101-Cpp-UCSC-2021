/**
 * This Graph holds 'movie' and 'actor' nodes and has the ability 
 * to find the shortest paths between them using breadth first search
 * @author UCSC, Marian Zlateva
 */

#include <iostream>
#include <assert.h>
#include <queue>
#include <fstream>
#include <algorithm> //for reverse()

#include "Graph.h"

using namespace std;

/**
 * constructor for a graph
 */
Graph :: Graph(){
  nodes = 0;
}

/**
 * Adds a movie and the actors who were in it to the graph
 *
 * @param movieName - the name of the movie
 * @param movieActorNames - a list of the actors attributed to the movie
 */
void Graph :: addMovie(string movieName, vector<string>movieActorNames){
  Node *movieNode = new Node(MOVIE, movieName);
  nodes += 1;
  
  for(string actorName: movieActorNames){
    
    Node *actorNode = actors[actorName];
    
    //if actor is in graph, use it
    //else, create a new node
    if(!actorNode){
      actorNode = new Node(ACTOR, actorName);
      actors[actorName] = actorNode;
      nodes += 1;
    }
    
    actorNode->addConnection(movieNode);
    movieNode->addConnection(actorNode);
    
  }
  
  
}

/**
 * prints all the actor's and the movies they starred in, into a file named 'ActorTxt.txt'
 */
void Graph :: printActors(){
  
  ofstream actorTxt;
  actorTxt.open("ActorTxt.txt");
  for(auto const&[name, node] : actors){
    actorTxt<<node->toString();
  }
}

/**
 * gets the shortest path between 2 actors in the graph
 * breadth first search info src: https://cp-algorithms.com/graph/breadth-first-search.html
 * 
 * @param actor1Name - 1st actor name
 * @param actor2Name - 2nd actor name
 * 
 * return - string representing the nodes of all the actors/movies in the path
 */
string Graph :: getShortestPathBetweenActors(string actor1Name, string actor2Name){
  Node *actor1 = actors[actor1Name];
  Node *actor2 = actors[actor2Name];
  
  if(!actor1){
    cout<<"actor: ("<<actor1Name<<") not found"<<endl;
    return "";
  }
  if(!actor2){
    cout<<"actor: ("<<actor2Name<<") not found"<<endl;
    return "";
  }
  
  //---------- breadth first search
  map<Node *, Node *>parentOf;
  map<Node *, bool>visited;
  
  queue<Node *>queue;
  int procceced = 0;
  
  //start node
  queue.push(actor1);
  parentOf[actor1] = NULL;
  
  while(!queue.empty()){
    Node *top = queue.front();
    queue.pop();
    
     if(visited[top]){
       continue;
     }
    procceced++;
    
    visited[top] = true;
    //cout<<"\n\n\n\n\n";
    //iterate through all the neighbors
    for(Node *neighbor: top->getConnections()){
      
      //if we didn't visit the node, add it to the queue
      if(!visited[neighbor]){
        //cout<<"not seen yet"<<endl;
        queue.push(neighbor);
        parentOf[neighbor] = top;
      }else{
        //cout<<"already did"<<endl;
      }
    }
    
  }
    
    //reassemble
    if(!visited[actor2]){
      return ""; //no path
    }
    
    vector<Node *>path;
    for(Node *cur = actor2; cur!=NULL; cur = parentOf[cur]){
      
      path.push_back(cur);
    }
    
    reverse(path.begin(), path.end());
    
    //---------- create string
    string pathString = "";
    for(Node *cur : path){
      if(cur->isA(MOVIE)){
        pathString += "-(" + cur->getName() + ")- ";
      }else if(cur->isA(ACTOR)){
        pathString += cur->getName() + " ";
      }
    }
    
    return pathString;

}