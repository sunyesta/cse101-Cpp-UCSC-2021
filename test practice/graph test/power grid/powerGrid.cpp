#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>
#include <list>
#include <utility>


#include "SnakesAndLadders.h"
#include "foodNetwork.h"

using namespace std;

#define pb push_back
#define mp make_pair
#define rr return 0
#define ll long long
typedef pair<int,int> pii;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

#define judge(expression){ if(expression){ cout<<"YES\n"; }else{ cout<<"NO\n"; } }
#define getLetters(s,vec){for(int i=0; i< (int)s.length(); i++){  if(s[i]>='a' && s[i]<='z') vec.pb(s[i]);}}
#define getDigits(s,vec){for(int i=0; i< (int)s.length(); i++){  if(s[i]>='0' && s[i]<='9') vec.pb(s[i]-'0');}}
#define printVec(vec){cout<<"["; for(int i=0; i<(int)vec.size();i++){ cout<<vec[i]<<", "; } cout<<"]";}
#define printPairs(vec){cout<<"["; for(pair<int,int> n:nums){  cout<<"("<<n.first<<", "<<n.second<<")";}cout<<"]\n";}
#define prtset(n) {cout<<"["; for(auto i:n) cout<<i<<" "; cout<<"]\n";}

#define isEqual(v1, v2){ return (v1.size() == v2.size() &&std::equal(v1.begin(), v1.end(), v2.begin()));}




/*17. You are given a directed, unweighted graph G representing the power
grid, as an adjacency list. Each vertex is a power station, and an edge
(u, v) means that power goes from u to v. A source vertex denotes a
power generator. A sink vertex denotes a power supplier, typically to a
neighborhood. Your job is to understand the robustness of the power grid,
under failure of a power station s. (Note that this may not be a source,
it could be some internal vertex.) If s fails, it stops transmitting power to
any of the outneighbors. This could potentially result in some sink node t
not receiving power at all, representing a power failure in a neighborhood.
Thus, a sink node t will not receive power if every path from every source
to t passes through the power station s. Design an algorithm that given
2
G and a vertex s, determines all the sink vertices t (if any) that stop
receiving power when s fails.*/

//A sink node is a node such that no edge emerges out of it.



class Node{
   public:
      string data;
      vector<Node *>neighbors;
      
      Node(string data){
         this->data = data;
      }

      void addNeighbor(Node *newNeighbor){
         neighbors.pb(newNeighbor);
      }

};

class Graph{
   public:

      map<string, Node *>verticies;
      
      void insert(string sourceName, string destinationName);
      bool checkForPath(string startName, string endName);
};


void Graph :: insert(string sourceName, string destinationName){
   Node *source = verticies[sourceName];
   if(!source){
      source = new Node(sourceName);
      verticies[sourceName] = source;
   }

   Node *destination = verticies[destinationName];
   if(!destination){
      destination = new Node(destinationName);
      verticies[destinationName] = destination;
   }

   source->addNeighbor(destination);

}

 bool Graph :: checkForPath(string startName, string endName){
   Node *start = verticies[startName];
   Node *end = verticies[endName];

   if(!start || !end){
      cout<<"data not present"<<endl;
      return false;
   }


   queue<Node *>q;
   map<Node *,bool>used;
   map<Node *, Node *>parentOf;

    q.push(start);
    used[start] = true;

    while(!q.empty()){
        Node *cur = q.front();
        q.pop();
        
        for(Node *neighbor: cur->neighbors){
            if(!used[neighbor]){
                used[neighbor] = true;
                q.push(neighbor);
            }
        }
        
    }
   
    if(used[end]){
      return true;
    }else{
       return false;
    }

}


//////////////////////////////////////////////////////////////////////////

//for the point in the graph, cut it out and then check if any of it's neighbors have neighbors, if they don't then cut them out
vector<Node *> whatPointsAreCutOff(Graph *myGraph, Node *cutPt){
    vector<Node *> sinkNodes;
    for(Node *neighbor: cutPt->neighbors){
        if(neighbor->neighbors.size() == 0){
            sinkNodes.pb(neighbor);
        }
    }

    return sinkNodes;

}

//////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv){

   if(argc < 2){
    cout<<"invalid number of args"<<endl;
    return 1;
  }

  //--------------------- opening files ---------------------//
  
  ifstream infile;
  ofstream outfile;
  
  infile.open(argv[1]);
  if(infile.fail()){
    cout<<"failed to open file!"<<endl;
    return 1;
  }
  
  //--------------------- solution ---------------------//
  
  //loop through each line of the input
  string thisLine;
 Graph myGraph;
  while(getline(infile,thisLine)){
    
    //make the current line opperable by >>
    istringstream thisLineISS(thisLine);
   
    string source, middle, destination;

    thisLineISS>>source>>middle>>destination;


    myGraph.insert(source,destination);
   
  }

}

void q17(){

}
