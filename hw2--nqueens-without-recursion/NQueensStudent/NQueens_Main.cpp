/**
 * Main function solves the NQueens problem as described in README.md
 * @author UCSC, Marian Zlateva
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <assert.h>

#include "Board.h"
using namespace std;


/**
 * NOT IN USE
 * recursive implementation
 * places the remaining queens on the board so that no 2 queens attack 
 * eachother and the # of queens = to the width or length of the board
 * 
 * @param board - the board to be populated with queens
 * 
 * @return - true if all queens are able to be placed on the board
 *         - false otherwise
 */
bool placeQueensRecursive(Board &board){
  //if we placed all the queens, no need to keep looking
  if(board.getQueenCount() == board.size()){
    return true;
  }
  
  //itterate over every cell on the board
  for(int r=0; r<board.size(); r++){
    for(int c=0; c<board.size(); c++){
      
      //if a cell is safe, add a queen there
      if(board.isSafeCell(r,c)==true){
        board.addQueen(r,c);
        
        bool success = placeQueensRecursive(board);
        if(success){
          return true;
        }else{
          
          //if finding a location for future queens was not successful,
          //we need to remove the current queen and look for an alternative position
          board.removeQueen(r,c);
        }
      }
    }
  }
  
  return false;
}


//class to be used by recurStack in placeQueensStack()
class stackObj{
  public:
    int row;
    int col;
    bool placedQueen;
    stackObj(int row, int col, bool placedQueen){
      this->row = row;
      this->col = col;
      this->placedQueen = placedQueen;
    }
};

/**
 * itterative stack implementation
 * places the remaining queens on the board so that no 2 queens attack 
 * eachother and the # of queens = to the width or length of the board
 * 
 * @param board - the board to be populated with queens
 * 
 * @return - true if all queens are able to be placed on the board
 *         - false otherwise
 */
bool placeQueensStack(Board &board){
  stack<class stackObj>recurStack;
  recurStack.push(stackObj(0,0,false));
  
  
  while(recurStack.empty()==false){
    stackObj stackTop = recurStack.top();
    recurStack.pop();
    
    //if we placed all the queens, no need to keep looking
    if(board.getQueenCount() == board.size()){
      return true;
    }
    
    int startRow = 0;
    int startCol = 0;
    
    //if the queen in stackTop on has already been placed,
    //that means we are back tracking and we need to remove the queen
    //and start searching at the next possible location
    if(stackTop.placedQueen){
      board.removeQueen(stackTop.row,stackTop.col);
      
      startRow = stackTop.row;
      startCol = stackTop.col+1;
    }
    
    
    //itterate over every cell on the board
    //(here we start on the last visited row and col in case we are backtracking)
    for(int r=startRow; r<board.size(); r++){
      for(int c=startCol; c<board.size(); c++){
        
        //if a cell is safe, add a queen there
        if(board.isSafeCell(r,c)==true){
          board.addQueen(r,c);
          
          //save the location of the current stackTop
          //onto the stack in case we need to backtrack
          recurStack.push(stackObj(r,c,true));
          
          //push the next stackObj onto the stack to find a location for the next queen 
          recurStack.push(stackObj(0,0,false));
          
          goto endloop;
        }
      }
      
      //reset the col so that next row will start at col 0
      startCol = 0;
    }
    
    endloop:
    continue;
  }
  
  //if the stack empties, that means there is no solution
  return false;
}

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
  
  //loop through each line of the input
  string thisLine;
  while(getline(infile,thisLine)){
    
    //make the current line opperable by >>
    istringstream thisLineISS(thisLine);
    
    
    int n; //board size = nxn and # of queens on board = n
    thisLineISS>>n;
    
    Board board(n);
    
    //add the inital queens
    int row,col;
    while(thisLineISS>>row && thisLineISS>>col){
      
      //decriment by 1 bc input is indexed from 1 instead of 0
      board.addQueen(row-1,col-1); 
    }
    
    //generate solution
    if(board.allQueensSafe() && placeQueensStack(board)){
      board.outputQueens(outfile);
      //board.print(); cout<<endl;
    }else{
      outfile<<"No solution\n";
    }
    
  }
  
  //--------------------- closing files ---------------------//
  
  infile.close();
  outfile.close();
 
}

