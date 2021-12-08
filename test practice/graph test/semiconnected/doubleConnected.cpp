
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
      bool checkForPath(string startName, string endName);
      bool semiconnected();
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

/*18. A directed graph G is semiconnected if for all pairs of vertices u, v, there
is either a path from u to v, or from v to u (but not both). Give an
algorithm to determine if G is semiconnected.*/

bool Graph :: semiconnected(Graph *myGraph){
   for (auto const& [data1, node1] : myGraph->verticies){
      for (auto const& [data2, node2] : myGraph->verticies){
         bool foundPath1 = myGraph->checkForPath(data1, data2);   
         bool foundPath2 = myGraph->checkForPath(data2, data1);   

         if((foundPath1 || foundPath2) && !(foundPath1 && foundPath2)){
            //good
         }else{
            //semiconnected
            return false;
         }
      }
   }

   return true;
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

  if(myGraph.semiconnected()){
     cout<<"semiconnected"<<endl;
  }else{
     cout<<"not semiconnected"<<endl;
  }
}



