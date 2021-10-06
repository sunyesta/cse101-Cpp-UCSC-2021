// Filename: linkedlist.cpp
// 
// Contains the class LinkedList that represents a linked list. This contains some basic operations, such as insert, delete, find, length
// 
// Japheth Frolick, August 2019
// C. Seshadhri, Jan 2020

#include "linkedlist.h"
#include <cstdlib>
#include <iostream>
#include <vector> 
#include <algorithm>
#include <string>
using namespace std;

// Default constructor sets head and tail to null
LinkedList :: LinkedList()
{
	head = NULL;
}

// Insert(int val): Inserts the int val into list, at the head of the list. Note that there may be multiple copies of val in the list.
// Input: Int to insert into the linked list
// Output: Void, just inserts new Node
void LinkedList :: insert(int val)
{
	Node *to_add = new Node; // creates new Node
	to_add->data = val; // sets the data to hold input val
	
    to_add->next = head; // make to_add point to existing head
    head = to_add; // set head to to_add
}

// find(int val): Finds a Node with data "val"
// Input: int to be found
// Output: a pointer to a Node containing val, if it exists. Otherwise, it returns NULL
// Technically, it finds the first Node in the list containing val
Node* LinkedList :: find(int val)
{
    Node *curr = head; // curr is the current Node as it progresses through the linked list. Initialized to head to start at the head of the list
    // curr will look over list. At every iteration, we will check if curr->data is val. If so, we are done. Otherwise, we proceed through the list.
    while(curr != NULL) //looping over list
    {
        if (curr->data == val) // found val, so return curr
            return curr;
        curr = curr->next; // otherwise, proceed through list
    }
    // if loop terminates, val not found
    return NULL;
}

// deleteNode(int val): Delete a Node with data val, if it exists. Otherwise, do nothing.
// Input: int to be removed
// Output: pointer to Node that was deleted. If no Node is deleted, return NULL. If there are multiple Nodes with val, only the first Node in the list is deleted.
Node* LinkedList :: deleteNode(int val)
{
    Node* prev = NULL;
    Node* curr = head;
    while(curr != NULL) // loop over list, starting from head
    {
        if(curr->data == val) // we found Node with val, so break
            break; 
        //otherwise, proceed list
        prev = curr; // move prev by one Node
        curr = curr->next; // move curr by one Node
    }
    // at this point, curr points to Node with val. If curr is null, then val is not in the list.
    if (curr == NULL) // val not found
        return NULL; 
    // val is in list. Note that curr is not NULL. There is a case analysis now. If prev is null, then curr is head. So we delete head directly.
    // Otherwise, we delete the Node after prev.
    if (prev == NULL) // we need to delete head
        head = head->next; // delete head
    else // we delete Node after prev. Note that both curr and prev are not NULL
        prev->next = curr->next; // make prev point to Node after curr. This removes curr from list
    return curr;
}

// Deletes every Node to prevent memory leaks.
// Input: None
// Output: Void, just deletes every Node of the list
void LinkedList :: deleteList()
{
	Node *curr = head; // curr is the current Node as it progresses through the linked list. Initialized to head to start at the head of the list
    Node *temp = NULL;

	// curr will loop over list. At every iteration, we first store a pointer to the next Node, and then delete the current Node.
    while(curr != NULL){ // Looping over list
		temp = curr->next; // store pointer to next Node in the list
		delete(curr); // delete the current Node
		curr = temp; // update curr to proceed through list
	}
	head = NULL;
    return;
}

// Prints list in order
// Input: None
// Output: string that has all elements of the list in order
string LinkedList :: print()
{
    string list_str = ""; // string that has list
	Node *curr = head; // curr is the current Node as it progresses through the linked list. Initialized to head to start at the head of the list
	// curr will loop over list. It prints the content of curr, and then moves curr to next Node.
	while(curr != NULL){ // looping over list
        list_str = list_str + to_string(curr->data) + " "; //append string with current Node's data
		curr = curr->next; // proceed through list
	}
    if (list_str.length() > 0) // string is non-empty
        list_str.pop_back(); // remove the last (extra) space from string
    return list_str + "\n";
}

// Computes the length of the linked list
// Input: None
// Output: Int, length of list
int LinkedList :: length()
{
    int length = 0; // initialize length to zero
	Node *curr = head; // curr is ths current Node as it progresses through the linked list. Initialized to head to start at the head of the list
	
	while(curr != NULL){ // looping over list
		length++; // increment length
		curr = curr->next; // proceed to next Node
	}
	return length;
}

void LinkedList :: reverseFront(int val){
    Node *oldHead = head;
    
    Node *cur = head;
    Node *prev = NULL;
    
    Node *next;
    
    //itterate over the list 'val' times or until it ends
    for(int i=0; i<val && cur!=NULL; i++){
        //save the next node for future use
        next = cur->next;
        
        //point the current node to the previous node
        cur->next = prev;
        
        //update the previous node for the next itteration
        prev = cur;
        
        //go to the next node that needs to be flipped
        cur = next;
        
        //update the old head so that instead of leading to NULL, it ends up leading to the first nonflipped node
        oldHead->next = next;
        
    }
    
    //update the head
    head = prev;
    
}

//NOT DONE
void LinkedList :: reverseBack(int val){
    
    int nodeCount = 0;

    Node *tail;
    for( tail = head; tail->next!=NULL; tail=tail->next){
        nodeCount++;
    }
    nodeCount++;

    
    int leftNodes = nodeCount - val; //calculate which node to break the circulation


    Node *oldHead = head;
    
    Node *cur = head;
    Node *prev = NULL;
    
    Node *next;
    
    //itterate over the list 'val' times or until it ends
    for(int i=0; i<val && cur!=NULL; i++){
        //save the next node for future use
        next = cur->next;
        
        //point the current node to the previous node
        cur->next = prev;
        
        //update the previous node for the next itteration
        prev = cur;
        
        //go to the next node that needs to be flipped
        cur = next;
        
        //update the old head so that instead of leading to NULL, it ends up leading to the first nonflipped node
        oldHead->next = next;
        
    }
    
    //update the head
    head = prev;
}


void LinkedList :: deleteFirstOccurrence(Node *cur, Node *prev, int x){
    //once the end of the list is reached, the node was not found so just return
    if(cur == NULL){
        return;
    
    //if a node with the correct data was found, delete it and return
    }else if(cur->data == x){
        if(prev != NULL){
            prev->next = cur->next;
        }
        
        delete(cur);
        cur = NULL;

        return;
        
    //if data doesn't match, just keep going
    }else{
        deleteFirstOccurrence(cur->next, cur, x);
    }
}

void LinkedList :: deleteFirstOccurrence(int x){
    deleteFirstOccurrence(head, NULL, x);
}




void LinkedList :: deleteKthOccurrence(Node *cur, Node *prev, int x, int k, int count){
    //once the end of the list is reached, the node was not found so just return
    if(cur == NULL){
        return;

    //if a node with the correct data was found, delete it if it's the kth occurence
    }else if(cur->data == x){
        
        //if the node is the kth occurence, delete it and return
        if(count == k-1){
            if(prev != NULL){
                prev->next = cur->next;
            }
            
            delete(cur);
            cur = NULL;
            return;
        
        //if node was not the kth occurence, increment count and keep going
        }else{
            deleteKthOccurrence(cur->next, cur, x, k, count+1);
        }
    
    //if data doesn't match, just keep going
    }else{
        deleteKthOccurrence(cur->next, cur, x, k, count);
    }
}

void LinkedList :: deleteKthOccurrence(int x, int k){
    deleteKthOccurrence(head, NULL, x, k, 0);
}


void LinkedList :: deleteLastOccurrence(Node *cur, Node *prev, Node *lastFound, Node *lastFoundPrev, int x){
    //once the end of the list is reached, delete the last occurence of the node with x
    if(cur == NULL){
        //check to see if a node was found
        if(lastFound == NULL){
            return;
        }

        //if the node is not the head node, fix the attachment
        if(lastFoundPrev != NULL){
            lastFoundPrev->next = lastFound->next;
        }else{
            head = lastFound->next;
        }
        
        //delete the node
        delete(cur);
        cur = NULL;

        return;
    }else if(cur->data == x){
        deleteLastOccurrence(cur->next, cur, cur, prev, x);
    }else{
        deleteLastOccurrence(cur->next, cur, lastFound, lastFoundPrev, x);
    }

}

void LinkedList :: deleteLastOccurrence(int x){
    deleteLastOccurrence(head, NULL, NULL, NULL, x);
}



void LinkedList :: deleteAllButFirstOccurrence(Node *cur, Node *prev, bool passedFirst, int x){
    //once the end of the list is reached, return
    if(cur == NULL){
        return;

    //if a node with the correct data was found, delete it if it's the kth occurence
    }else if(cur->data == x){
        
        //if the node is not the first occurence, delete it and keep going
        if(passedFirst == true){

            Node *next = cur->next;

            if(prev != NULL){
                prev->next = cur->next;
            }else{
                head = cur->next;
            }
            
            delete(cur);
            cur = NULL;
            
            deleteAllButFirstOccurrence(next, prev, passedFirst, x);
        
        //if node is the first occurence, set passedFirst to true and keep going
        }else{
            deleteAllButFirstOccurrence(cur->next, cur, true, x);
        }
    
    //if data doesn't match, just keep going
    }else{
        deleteAllButFirstOccurrence(cur->next, cur,passedFirst, x);
    }
    
}

void LinkedList :: deleteAllButFirstOccurrence(int x){
    deleteAllButFirstOccurrence(head, NULL, false, x);
}



bool LinkedList :: isPalindrome(){
    
    //make a list that is the reverse of this list
    LinkedList *reverseList = new LinkedList();

    for(Node *cur = head; cur!=NULL; cur=cur->next){
        reverseList->insert(cur->data);
    }
    
    //make sure that the reverse list and the normal list are the same
    for(Node *norm = head, *rev = reverseList->head;
        norm!=NULL;
        norm = norm->next, rev = rev->next){
        
        //if a node is not the same, list is not palindrome
        if(norm->data != rev->data){
            return false;
        }
    }
    
    //if loop terminates succesfully, list is a palindrome
    return true;
}



void LinkedList :: rotate(int x){

    int nodeCount = 0;
    
    //count nodes and find the tail by traversing the list
    Node *tail;
    for( tail = head; tail->next!=NULL; tail=tail->next){
        nodeCount++;
    }
    nodeCount++; //since the loop doesn't actually run when the node is on the
                 //tail, we need to increment it manually
    
    tail->next = head; //make the linked list circluar
    
    x = x % nodeCount; //normalize x so that the below calculation works
    int leftNodes = nodeCount - x; //calculate which node to break the circulation


    //get to the node that will be the new end
    Node *cur = tail;
    for(int i=0; i<leftNodes; i++){
        cur = cur->next;
    }
    
    head = cur->next; //reset the head
    cur->next = NULL; //break the circulation
    
}


