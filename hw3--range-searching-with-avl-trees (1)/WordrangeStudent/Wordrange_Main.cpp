/**
 * Main function uses the AVLTree class to insert and read from the tree
 * @author UCSC, Marian Zlateva
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "AVLTree.h"

using namespace std;

//===========================================================================

int main(int argc, char **argv){
  
  if(argc < 3){
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
  
  outfile.open(argv[2]);
  if(outfile.fail()){
    cout<<"failed to open file!"<<endl;
    return 1;
  }
  
  //--------------------- solution ---------------------//

  AVLTree myTree;
  
  //loop through each line of the input
  string thisLine;
  while(getline(infile,thisLine)){
    
    //make the current line opperable by >>
    istringstream thisLineISS(thisLine);
    
    char operation;
    thisLineISS>>operation;
    
    //insert into the tree
    if(operation == 'i'){
      
      string data;
      thisLineISS>>data;
      
      myTree.insert(data);
    
    //count the number of strings (currently stored) that are 
    //lexicographically between the next 2 strings
    }else if(operation == 'r'){
      
      string start, end;
      
      thisLineISS>>start>>end;
      
      outfile<<myTree.countBtwn(start,end)<<endl;
    }
    
    
    
  }
  
  
}