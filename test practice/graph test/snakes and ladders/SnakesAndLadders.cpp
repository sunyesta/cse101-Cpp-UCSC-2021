
#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>
#include <list>
#include <utility>
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


/*13. Consider a game of snakes and ladders. Determine the minimum number
of throws required to win the game.*/

enum actionsList {LAND_ON, PASSTHROUGH};

class Cell{
    public:
        int cellNum;
        Cell *cellActions[2];
    
        Cell(){
            cellNum = -1;
            cellActions[LAND_ON] = NULL;
            cellActions[PASSTHROUGH] = NULL;
        }
};

//assume dice of infinite size bc size is not specified

/*
 * Prints a sequence of rolls to get the shortest path in a game of snakes and ladders
 *
 * @param boardString - a sequence of numbers representing the cells on the board.
 *                      0, if there is no jump, else, put the cell to jump to
 *                      EX: "0 0 22 0 8 0 0 0 0 0 26 0 0 0 0 0 4 0 7 29 9 0 0 0 0 0 1 0 0 0"
 */
void q13(string boardString){
    
    vector<int>board;
    vector<Cell *>boardGraph;

    board.pb(0);
    boardGraph.pb(new Cell);
    
    //fill the board with each index holding the persumed destination if the
    //player landed on that specific cell
    //Also, create a new cell object for every index in the board graph
    istringstream boardISS(boardString);
    for(int jump; boardISS>>jump;){
        boardGraph.pb(new Cell());
        if(jump > 0){
            board.pb(jump);
        }else{

            //if there is no jump, we add the next consecutive cell
            board.pb(board.size());
        }
    }

    //
    for(int i=0; i<boardGraph.size(); i++){
        Cell *cur = boardGraph[i];

        cur->cellNum = i;

        int landOnNum = board[i]; //if we land on cur, `landOnNum` is where we go
        cur->cellActions[LAND_ON] = boardGraph[landOnNum];

        if(i+1<boardGraph.size()){
            //if we pass through cur, we just go to the next consecutive cell
            cur->cellActions[PASSTHROUGH] = boardGraph[i+1];

        }else{
            //if there is no next consecutive cell, we just stay on the cell
            cur->cellActions[PASSTHROUGH] = boardGraph[i];
        }
        
    }
    
    
    //breadth first search
    
    Cell *start = boardGraph[0];
    Cell *end = boardGraph[boardGraph.size()-1];

    map<Cell *,bool>used;
    map<Cell *,Cell *>parentOf;

    queue<Cell *>q;

    q.push(start);
    used[start] = true;
    parentOf[start] = NULL;

    while(!q.empty()){
        Cell *cur = q.front();
        q.pop();
        
        for(Cell *possibleCell: cur->cellActions){
            if(!used[possibleCell]){
                used[possibleCell] = true;
                q.push(possibleCell);
                parentOf[possibleCell] = cur;
            }
        }
        
    }
    
    //reconstruct path

    if(!used[end]){
        cout<<"no path to end"<<endl;
    }

    vector<Cell *>path;
    for(Cell *cur = end; cur!=NULL; cur = parentOf[cur]){
        path.pb(cur);
    }

    reverse(path.begin(), path.end());
    
    
    //print rolls
    

    int lastNum = path[0]->cellNum;
    int count = 0;

    //itterate through the found path of cells
    for(int i=1; i<path.size(); i++){
        Cell *cell = path[i];
        int cellNum = cell->cellNum;

        //if there is a jump, reset the count and print the # of cells it took to get here
        if(cellNum != lastNum+1){
            cout<<count<<" ";
            count=0;
        }else{
            count++;
        }

        lastNum = cellNum;
    }

    //last print in case there is a cell > 0
    if(count > 0){
        cout<<count; 
    }
}

int main(){
    q13("0 0 22 0 8 0 0 0 0 0 26 0 0 0 0 0 4 0 7 29 9 0 0 0 0 0 1 0 0 0");

}


