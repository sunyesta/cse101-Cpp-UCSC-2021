// Filename: linkedlist.h
// 
// Header file for the class LinkedList that represents a linked list
// 
// Japheth Frolick, August 2019
// C. Seshadhri, Jan 2020

#ifndef LIST_H
#define LIST_H

#include <string>

using namespace std;

// node struct to hold data
struct Node
{
	int data;
	Node *next;
};

class LinkedList
{
	private:
		Node *head; // Stores head of linked list
		void deleteFirstOccurrence(Node*, Node*, int);
		void deleteKthOccurrence(Node *, Node *, int , int, int);
		void deleteLastOccurrence(Node *cur, Node *prev, Node *lastFound, Node *lastFoundPrev, int x);
		void deleteAllButFirstOccurrence(Node *cur, Node *prev, bool passedFirst, int x);
	public:
		LinkedList(); // Default constructor sets head to null
		void insert(int); // insert int into list 
		Node* find(int); // find int in list, and return pointer to node with that int. If there are multiple copies, this only finds one copy
		Node* deleteNode(int); // remove a node with int (if it exists), and return pointer to deleted node. This does not delete all nodes with the value.
		void deleteList(); // deletes every node to prevent memory leaks, and frees memory
		string print(); // Construct string with data of list in order 
		int length(); // Returns the length of the linked list

		// Advanced functions follow
		void reverseFront(int); // reverse every segment of int entries
		void reverseBack(int); // reverse every segment of int entries
		void deleteFirstOccurrence(int);
		void deleteKthOccurrence(int , int);
		void deleteLastOccurrence(int x);
		void deleteAllButFirstOccurrence(int x);
		bool isPalindrome();
		void rotate(int);
};

#endif
