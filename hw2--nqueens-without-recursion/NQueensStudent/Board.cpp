/**
 * A board is an object who's primary purpose is storing queens in it's cells
 * @author UCSC, Marian Zlateva
 */

#include "Board.h"

#include <iostream>
#include <assert.h>

using namespace std;

enum QueenState {FREE = false, TAKEN = true};

/**
 * The constructor for a Board
 */
Board :: Board(int size){
  
  int rows = size, cols = size;
  vector<vector<bool>>temp(rows,vector<bool>(cols,false));
  _layout = temp;
  _size = size;
  _queens = 0;
}

/**
 * Gets the size of the board
 *
 * @return - the board size
 */
int Board :: size(){
  return _size;
}

/**
 * Gets the number of queens on the board
 *
 * @return - the queen count
 */
int Board :: getQueenCount(){
  return _queens;
}

/**
 * Places a queen on the board
 *
 * @param row - the row to put the queen on
 * @param col - the column to put the queen on
 */
void Board :: addQueen(int row, int col){
  assert(row<_size && row>=0 && col<_size && col>=0);
  
  if(_layout[row][col] == FREE){
    _layout[row][col] = TAKEN;
    _queens++;
  } 
  
  return;
}

/**
 * Removes a queen from the board
 *
 * @param row - the row the queen is on
 * @param col - the column the queen is on
 */
void Board :: removeQueen(int row, int col){
  assert(row<_size && row>=0 && col<_size && col>=0);
  
  if(_layout[row][col]==TAKEN){
    _layout[row][col] = FREE;
    _queens--;
  }
  
  return;
}

/**
 * Checks if a cell on the board is safe from the queens on the board
 *
 * @param row - the row of the cell being checked
 * @param col - the column of the cell being checked
 */
bool Board :: isSafeCell(int row, int col){
  assert(row<_size && row>=0 && col<_size && col>=0);
  
  /*
     row/cols to check:
          |
          |
       ---X---
          |
          |
  */
  
  //check horizontal
  for(int c=0; c<_size; c++){
    if(_layout[row][c]==TAKEN){
      return false;
    }
  }
  
  //check vertical
  for(int r=0; r<_size; r++){
    if(_layout[r][col]==TAKEN){
      return false;
    }
  }
  
  /*
     Diagonals to check:
          \   /
           \ /
            X
           / \
          /   \
  */
  
  
  //check if there are queens on the top left diagonal
  for(int r=row, c=col; r>=0 && c>=0; r--, c--){
    if(_layout[r][c]==TAKEN){
      return false;
    }
  }
  
  //check if there are queens on the bottom right diagonal
  for(int r=row, c=col; r<_size && c<_size; r++, c++){
    if(_layout[r][c]==TAKEN){
      return false;
    }
  }
  
  //check if there are queens on the top right diagonal
  for(int r=row, c=col; r>=0 && c<_size; r--, c++){
    if(_layout[r][c]==TAKEN){
      return false;
    }
  }
  
  //check if there are queens on the bottom left diagonal
  for(int r=row, c=col; r<_size && c>=0; r++, c--){
    if(_layout[r][c]==TAKEN){
      return false;
    }
  }
  
  return true;
}

/**
 * Checks if the current queens on the board are all safe from eachother
 *
 * @return - true if all the queens are safe from eachother
 *         - false otherwise
 */
bool Board :: allQueensSafe(){
  for(int r=0; r<_size; r++){
    for(int c=0; c<_size; c++){
      
      //if a cell in the board has a queen, check to see
      //if that queen is safe from other queens
      if(_layout[r][c]==TAKEN){
        
        _layout[r][c]=FREE; //temporairly free the cell
        bool safe = isSafeCell(r,c);
        _layout[r][c]=TAKEN; //revert back
        
        if(!safe){
          return false;
        }
        
      }
      
    }
  }
  
  return true;
}

/**
 * Prints the locations of all the queens in <row> <col> format
 * ordered from the top left queen to the bottom right queen
 *
 * @param outfile - reference to the file being printed to
 */
void Board :: outputQueens(ofstream &outfile){
  for(int r=0; r<_size; r++){
    for(int c=0; c<_size; c++){
      if(_layout[r][c]==TAKEN){
        outfile<<r+1<<" "<<c+1<<" ";
      }
    }
  }
  outfile<<endl;
}

/**
 * DEBUG
 * prints the board
 */
void Board :: print(){
  for(int r=0; r<_size; r++){
    for(int c=0; c<_size; c++){
      cout<<_layout[r][c]<<" ";
    }
    cout<<endl;
  }
  
  return;
}