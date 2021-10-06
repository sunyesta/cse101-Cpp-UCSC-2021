// Filename: listwrapper.cpp
//
// This is the main wrapper for the LinkedList class.
// 
// After running make, the usage is:
//     ./listwrapper <INPUT_FILE> <OUTPUT_FILE>
// 
// The input file contains a list of operations performed on a linked list. The operations are insert, delete, and print. 
// Each line is of the form "i <INT>", "d <INT>", or "p". This means "insert", "delete", and "print" respectively. The second INT argument is for inserting/deleting that number.
// 
// Only the print operations generate output, which is the list printed in order in a single line.
// The output file contains the output of all print commands.
// 
// In addition, the console output shows the operations performed, and also prints the list (for every print command).
// Look at the associated pdf in this directory for more details.
// 
// Japheth Frolick, August 2019
// C. Seshadhri, Jan 2020

#include <iostream>
#include "linkedlist.h"
#include <stack>
#include <stdexcept>
#include <fstream>
#include <array>
#include <vector> 
#include <algorithm>
#include <sstream>
#include <cstring>
using namespace std;


int main(int argc, char** argv)
{




    LinkedList myList; // initializing the linked list

    myList.insert(5);
    myList.insert(4);
    myList.insert(3);
    myList.insert(2);
    myList.insert(1);
    
    cout<<myList.print();
    

    myList.reverse(5);
    cout<<myList.print();


    myList.deleteFirstOccurrence(3);
    cout<<myList.print();


    myList.insert(3);
    myList.insert(5);
    myList.insert(2);
    myList.insert(5);
    myList.insert(1);
    myList.insert(5);
    cout<<myList.print();
    
    myList.deleteKthOccurrence(5, 2);
    cout<<myList.print();

    myList.deleteLastOccurrence(5);
    cout<<myList.print();

    myList.insert(5);
    myList.insert(5);
    myList.insert(5);
    myList.insert(5);
    myList.insert(5);
    myList.insert(4);
    myList.insert(4);
    myList.insert(5);
    myList.insert(5);
    myList.insert(5);
    cout<<myList.print();
    
    cout<<myList.isPalindrome()<<endl;
    
    myList.deleteAllButFirstOccurrence(5);
    cout<<myList.print();
    
    LinkedList palList;
    palList.insert(5);
    palList.insert(4);
    palList.insert(3);
    palList.insert(2);
    palList.insert(1);
    palList.insert(2);
    palList.insert(3);
    palList.insert(4);
    palList.insert(5);
    cout<<palList.print();
    
    cout<<palList.isPalindrome()<<endl;

    LinkedList simpleList;
    simpleList.insert(5);
    simpleList.insert(4);
    simpleList.insert(3);
    simpleList.insert(2);
    simpleList.insert(1);
    cout<<simpleList.print();

    simpleList.rotate(7);
    cout<<simpleList.print();
    
    
}
