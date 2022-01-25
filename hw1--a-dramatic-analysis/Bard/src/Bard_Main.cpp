#include "LinkedList.h"

#include <iostream> //reading files
#include <fstream>  //


#define MAX_WORD_LEN 100
#define ARGC 2
using namespace std;


int main(int argc, char** argv){
  
  //check for correct # of args
  if(argc < ARGC+1){
    cout<<"invalid number of args"<<endl;
    return 1;
  }
  
  //open files
  ifstream shakespeareTxt;
  
  ifstream infile;
  ofstream outfile;
  
  shakespeareTxt.open("shakespeare-cleaned5.txt");
  if(shakespeareTxt.fail()){
    cout<<"failed to open file!"<<endl;
    return 1;
  }
  
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
  
  
  
  LinkedList lists[MAX_WORD_LEN];
  
  //read file word by word and store results in correct list
  string word;
  while(shakespeareTxt>>word){
    
    //skip words that are out of the array limits
    if(word.length() <= 0 || word.length()> MAX_WORD_LEN){
      continue;
    }
    
    //store word in index that matches its length
    lists[word.length()-1].insert(word);
  }
  
  //shakespeareTxt no longer needed so close it
  shakespeareTxt.close();
  
  //sort all the lists
  for(int i=0; i<MAX_WORD_LEN; i++){
    lists[i].bubbleSort();
  }
  
  //parse the infile and give the correct outputs
  int wordLen;
  int n;
  while(infile>>wordLen && infile>>n){
    outfile<<lists[wordLen-1].findnthMostFrequentWord(n)<<endl;
  }
  
  //in/outfiles no longer needed so close them
  infile.close();
  outfile.close();
  
  //free list memory
  for(int i=0; i<MAX_WORD_LEN; i++){
    lists[i].deleteList();
  }
  
  return 0;
}


