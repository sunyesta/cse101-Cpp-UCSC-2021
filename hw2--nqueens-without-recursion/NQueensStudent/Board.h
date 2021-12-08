/**
 * A board is an object who's primary purpose is storing queens in it's cells
 * @author UCSC, Marian Zlateva
 */

#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <fstream>

using namespace std;

class Board{
  private:
    vector<vector<bool>>_layout;
    int _size;
    int _queens;
  public:
    Board(int size);
    int size();
    int getQueenCount();
    void addQueen(int row, int col);
    void removeQueen(int row, int col);
    bool isSafeCell(int row, int col);
    bool allQueensSafe();
    void outputQueens(ofstream &outfile);
    void print();
};

#endif