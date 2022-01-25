/**
 * Main function uses the AVLTree class to insert and read from the tree
 * @author UCSC, Marian Zlateva
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Graph.h"

using namespace std;

//===========================================================================

int main(int argc, char **argv){
  
  if(argc < 3){
    cout<<"invalid number of args"<<endl;
    return 1;
  }
  
  
  //--------------------- opening files ---------------------//
  
  ifstream movieList;
  ifstream infile;
  ofstream outfile;
  
  movieList.open("./cleaned_movielist.txt");
  if(movieList.fail()){
    cout<<"failed to open 'cleaned_movielist.txt'"<<endl;
    return 1;
  }
  
  infile.open(argv[1]);
  if(infile.fail()){
    cout<<"failed to open ''"<<argv[1]<<"'"<<endl;
    return 1;
  }
  
  outfile.open(argv[2]);
  if(outfile.fail()){
    cout<<"failed to open ''"<<argv[2]<<"'"<<endl;
    return 1;
  }
  
  //--------------------- solution ---------------------//

  Graph myGraph;
  
  //loop through each line of the movieList
  string thisLine;
  while(getline(movieList, thisLine)){
    
    //make the current line opperable by >>
    istringstream thisLineISS(thisLine);
    
    string movie;
    thisLineISS>>movie;
    
    //get all the actors
    vector<string>actors;
    string actor;
    while(thisLineISS>>actor){
      actors.push_back(actor);
    }
    
    //insert the data into the graph
    myGraph.addMovie(movie, actors);
    
  }
  
  myGraph.printActors();
  //-------- proccess infile
  
  //loop through each line of the input
  while(getline(infile, thisLine)){
    
    //make the current line opperable by >>
    istringstream thisLineISS(thisLine);
    
    string actor1, actor2;
    
    thisLineISS>>actor1>>actor2;
    
    //print the shortest path between the actors
    string path = myGraph.getShortestPathBetweenActors(actor1, actor2);
    if(path!= ""){
      outfile<<path<<endl;
    }else{
      outfile<<"Not present"<<endl;
    }
    
    
    
    
  }
  
  
}