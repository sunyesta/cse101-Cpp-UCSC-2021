
#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>
#include <list>
#include <string>
#include <utility>
#include <vector>
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

/*16. A triangle is a set of edges {(u, v),(v, w),(w, u)}. (Equivalently, a triangle
is a cycle of length 3.) Given a vertex s, we wish to count the number of
distinct triangles in G that involve s. Get a solution with O(n) space.*/



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
      bool checkForPath(Node *start, Node *end);
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

 bool Graph :: checkForPath(Node *start, Node *end){

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
   
    string source;

    thisLineISS>>source;
    

    string dest;
    while(thisLineISS>>dest){
        myGraph.insert(source,dest);
    }

   
  }
    
  int triangles = 0;
    

  map<Node *, bool>used;
  //itterate through all verticie matches in the graphs
    for(int i=0; i<myGraph.verticies.size(); i++){
        Node *vert1, *vert2;
        for(int j=i+1; j<myGraph.verticies.size(); j++){
            vert1 = myGraph.verticies[i];
            vert2 = myGraph.verticies[j];
            

            //if a path between the verts is found (using BSF) and
            //for each neighbor that they share, they make a new triangle
            //(make sure )
            if(myGraph.checkForPath(vert1, vert2) == true){
                
                for(Node *neighbor1 : vert1->neighbors){
                    for(Node *neighbor2 : vert2->neighbors){
                        if(neighbor1 == neighbor2 && used[neighbor1] == false){
                            triangles++;
                        }
                    }
                }
            }
            




        }

        used[vert1] = true;
        used[vert2] = true;
    }

    cout<<"triangles = "<<triangles;
}


