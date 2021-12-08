
#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>
#include <list>
#include <utility>
#include <vector>


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
      bool getDiameterOfNode(string startName);
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

 int Graph :: getDiameterOfNode(string startName){
   Node *start = verticies[startName];
   
   

   if(!start || !end){
      cout<<"data not present"<<endl;
      return false;
   }


   queue<Node *>q;
   map<Node *,bool>used;
   map<Node *, Node *>parentOf;
   map<Node *,int>distanceTo;


    q.push(start);
    used[start] = true;

    while(!q.empty()){
        Node *cur = q.front();
        q.pop();
        
        for(Node *neighbor: cur->neighbors){
            if(!used[neighbor]){
                used[neighbor] = true;
                q.push(neighbor);
                distanceTo[neighbor] = distanceTo[cur]+1;
            }
        }
        
    }
   

   //get longest shortest path
   
   int maxDist = -1;

   for (auto const& [node, dist] : distanceTo){
      if(dist>maxDist){
         maxDist = dist;
      }
   }

   return maxDist;

}


//////////////////////////////////////////////////////////////////////////
/*19. The diameter of a graph G is the largest shortest path distance in G
(meaning, it is maxu,v∈V dist(u, v), where dist(u, v) is the shortest path
distance). Give an algorithm to compute the diameter of a undirected
graph G. Give a more efficient algorithm to determine the diameter of an
undirected tree T*/


int graphDiameter(Graph *myGraph){
   int diameter = 0;
   for (auto const& [data1, node1] : myGraph->verticies){
      int calc = myGraph->getDiameterOfNode(node1);
      if(calc>diameter){
         diameter = calc;
      }
   }

   return diameter;
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
   

  cout<<"diameter = "<<graphDiameter(myGraph);
}
