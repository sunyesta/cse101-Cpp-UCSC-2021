#include"List.h"
#include <stdlib.h>
#include <assert.h>


//----------------------- node -----------------------
typedef struct NodeObj* Node;
typedef struct NodeObj{
   Node next; // next linked node
   Node prev; // previous linked node
   int data; // data held inside node
}NodeObj;

// Constructors-Destructors ----------------------

/**
 * @brief The constructor for a node
 *
 * @param data the data inside the node
 * @return the new node (possible NULL if memory allocation failed)
 */
Node newNode(int data){
   Node n = (Node)calloc(1,sizeof(NodeObj));
   if(n == NULL){
      return NULL;
   }

   n->data = data;

   return n;
}


/**
 * @brief The destructor for a node
 *
 * @param n the node
 */
void freeNode(Node *n){
   assert(n && *n);

   free(*n);
   *n = NULL;

   return;
}

//----------------------- linked list -----------------------

typedef struct ListObj {
   int length; // length of list
   Node head; // head sentinal node of list
   Node tail; // tail sentinal node of list
   int cursorIndex; // cursor index of list
   Node cursorNode; // node that the cursor points to in the list
}ListObj;

// Constructors-Destructors ----------------------


/**
 * @brief The constructor for a list
 *
 * @return the created list (possible NULL if memory allocation failed)
 */
List newList(){
   //allocate space for the ADT
   List L = (List)calloc(1,sizeof(ListObj));
   if(L == NULL){
      return NULL;
   }

   //create the sentinal nodes
   L->head = newNode(0);
   if(L->head == NULL){
      free(L);
      return NULL;
   }

   L->tail = newNode(0);
   if(L->tail == NULL){
      free(L);
      free(L->head);
      return NULL;
   }

   //connect the sentinal nodes
   L->head->next = L->tail;
   L->tail->prev = L->head;

   L->length = 0;

   //set cursor
   L->cursorIndex = -1;
   L->cursorNode = NULL;

   return L;
}

/**
 * @brief The destructor for a list
 *
 * @param pL a pointer to a List
 */
void freeList(List* pL){

   //deletes all nodes in the list except the tail
   for (Node cur = (*pL)->head->next; cur != NULL; cur = cur->next) {
      
      //deletes the previous node to cur
      freeNode(&(cur->prev));
   }

   freeNode(&( ((*pL)->tail) ));

   free(*pL);
   *pL = NULL;

   return;
}


// Access functions -------------------------------


/**
 * @brief returns the number of elements in a list
 *
 * @param L the list
 * @return the number of elements in L
 */
int length(List L){
   assert(L);

   return L->length;
}

/**
 * @brief returns the index of the cursor element in a list
 *
 * @param L the list
 * @return the index of the cursor element in L, -1 if cursor undefined
 */
int index(List L){
   assert(L);

   return L->cursorIndex;
}

/**
 * @brief returns the front element of a list
 *
 * @param L the list
 * @return the front element of L
 */
int front(List L){
   assert(L);

   return L->head->next->data;
}

/**
 * @brief returns the back element of a list
 *
 * @param L the list
 * @return the back element of L
 */
int back(List L){
   assert(L);

   return L->tail->prev->data;
}

/**
 * @brief get returns the cursor element of a list
 *
 * @param L the list
 * @return the cursor element of L
 */
int get(List L){
   assert(L);
   assert(L->cursorIndex >= 0);

   return L->cursorNode->data;
}

/**
 * @brief checks if 2 lists are the same
 *
 * @param A the first list
 * @param B the second list
 * @return 1, if the lists are equal
 *         0, otherwise
 */
int equals(List A, List B){
   assert(A);
   assert(B);

   Node curA = A->head->next;
   Node curB = B->head->next;

   while(true){
      //if both lists reach the end at the same time, the lists are equal
      if(curA == A->tail && curB == B->tail){
         return 1;
      //if only one list reached the end, the lists are not equal
      }else if(curA == A->tail || curB == B->tail){
         return 0;
      }

      //if the data inside the nodes isn't equal, they are not equal
      if(curA->data != curB->data){
         return 0;
      }

      curA = curA->next;
      curB = curB->next;
   }

   return 1;
}

// Manipulation procedures ------------------------

/**
 * @brief empties a list
 *
 * @param L the list
 */
void clear(List L){
   assert(L);
   assert(L->length > 0);

   assert(L->head->next);

   //if list size >= 2, clear the list using this method
   if(L->head->next != NULL){

      //deletes all the nodes btwn the head and tail, exclusive
      for (Node cur = L->head->next->next; cur != NULL; cur = cur->next) {
         
         //deletes the previous node to cur
         freeNode(&(cur->prev));
      }

      //if list size == 1, manually clear the tree
   }else{
      freeNode(&(L->head->next));
   }

   //reconnect the sentinal nodes
   L->head->next = L->tail;
   L->tail->prev = L->head;

   L->length = 0;

   return;
}


/**
 * @brief overwrites the cursor element’s data with new data
 *
 * @param L the list
 * @param x the new data
 */
void set(List L, int x){
   assert(L);
   assert(L->length > 0);
   assert(L->cursorIndex >= 0);
   L->cursorNode->data = x;

   return;
}


/**
 * @brief moves a list's cursor to the first element
 *
 * @param L the list
 */
void moveFront(List L){
   assert(L);
   
   if(L->length > 0){
      L->cursorIndex = 0;
      L->cursorNode = L->head->next;
   }

   return;
}

/**
 * @brief moves a list's cursor to the last element
 *
 * @param L the list
 */
void moveBack(List L){
   assert(L);

   if(L->length > 0){
      L->cursorIndex = L->length - 1;
      L->cursorNode = L->tail->prev;
   } 

   return;
}

/**
 * @brief moves a list's cursor to the previous element
 *
 * @param L the list
 */
void movePrev(List L){
   assert(L);
   assert(L->cursorIndex >= -1); //DEBUG

   //the cursor should not be altered if undefined
   if(L->cursorIndex == -1){
      return;
   }

   //decrement the cursor
   L->cursorIndex-=1;
   L->cursorNode = L->cursorNode->prev;

   return;
}

/**
 * @brief moves a list's cursor to the next element
 *
 * @param L the list
 */
void moveNext(List L){
   assert(L);
   assert(L->cursorIndex >= -1); //DEBUG

   //the cursor should not be altered if undefined
   if(L->cursorIndex == -1){
      return;
   }
   //increment the cursor
   L->cursorIndex+=1;
   L->cursorNode = L->cursorNode->next;

   //if the cursor is past the last element of the list, set it to undefined
   if(L->cursorIndex == L->length){
      L->cursorIndex = -1;
   }

   return;
}

/**
 * PRIVATE
 * @brief inserts a new node in the next position of an existing node
 *
 * @param L   the List
 * @param x   the data inside the new node
 * @param cur the existing node
 */
void insertNext(List L, int x, Node cur){
   assert(L);
   assert(cur);
   assert(cur != L->tail); //can't insert after the tail node

   //creates the new node
   Node n = newNode(x);
   if(n == NULL){
      return;
   }

   //fix new
   n->prev = cur;
   n->next = cur->next;

   //relinks the node that used to be right behind the head node
   cur->next->prev = n;

   //links the head node to the new node
   cur->next = n;

   L->length+=1;

   return;
}

/**
 * PRIVATE
 * @brief inserts a new node in the previous position of an existing node
 *
 * @param L   the List
 * @param x   the data inside the new node
 * @param cur the existing node
 */
void insertPrev(List L, int x, Node cur){
   assert(L);
   assert(cur);
   assert(cur != L->head); //can't insert bfr the head node

   //creates the new node
   Node n = newNode(x);
   if(n == NULL){
      return;
   }

   //fix new
   n->prev = cur->prev;
   n->next = cur;

   //relinks the node that used to be right behind the head node
   cur->prev->next = n;

   //links the head node to the new node
   cur->prev = n;

   L->length+=1;

   return;
}

/**
 * @brief Inserts a new element at the front of a list
 *
 * @param L The list
 * @param x the element
 */
void prepend(List L, int x){
   assert(L);

   insertNext(L, x, L->head);

   if(L->cursorIndex != -1){
      //increments the cursorIndex bc there are more nodes behind the cursor now
      L->cursorIndex+=1;
   }

   return;
}

/**
 * @brief Inserts a new element at the back of a list
 *
 * @param L The list
 * @param x the element
 */
void append(List L, int x){
   assert(L);

   insertPrev(L, x, L->tail);

   return;
}

/**
 * @brief Inserts a new element in a list in front of its curor element
 *
 * @param L The list
 * @param x the element
 */
void insertBefore(List L, int x){
   assert(L);
   assert(L->length>0);
   assert(L->cursorIndex >= 0);

   insertPrev(L, x, L->cursorNode);

   return;
}

/**
 * @brief Inserts a new element in a list behind its curor element
 *
 * @param L The list
 * @param x the element
 */
void insertAfter(List L, int x){
   assert(L);

   insertNext(L, x, L->cursorNode);

   return;
}

/**
 * PRIVATE
 * @brief removes and deletes a node from a list
 *        (cursor fixing is only supported for deleteFront(), delete(), and deleteBack())
 *
 * @param L   the list
 * @param cur the Node
 */
void removeNode(List L, Node cur){
   assert(L);
   assert(L->length>0);
   assert(cur == L->head->next || cur == L->tail->next || cur == L->cursorNode);
   
   //fixes cursor
   //
   //sets the cursor to undefined if we are deleting its corresponding node
   if(cur == L->cursorNode){
      L->cursorIndex = -1;
   //decrements the cursorIndex bc there are less nodes infront of the cursor now
   }else if(cur == L->head->next){
      L->cursorIndex-=1;
   }   

   Node n = cur->next;
   Node p = cur->prev;

   p->next = n;
   n->prev = p;

   freeNode(&cur);

   L->length-=1;

   return;
}

/**
 * @brief Deletes the front element of a list
 *
 * @param L The list
 */
void deleteFront(List L){
   assert(L);

   removeNode(L, L->head->next);
   
   return;
}

/**
 * @brief Deletes the back element of a list
 *
 * @param L The list
 */
void deleteBack(List L){
   assert(L);

   removeNode(L, L->tail->prev);

   return;
}

/**
 * @brief Deletes the cursor element of a list and makes the cursor undefined
 *
 * @param L the list
 */
void delete(List L){
   assert(L);
   assert(L->cursorIndex >= 0);

   removeNode(L, L->cursorNode);

   return;
}

/**
 * @brief Prints a list from front(left) to back(right) into an output file
 *
 * @param out the output file
 * @param L the list
 */
void printList(FILE* out, List L){
   assert(L);

   //itterates through all the nodes btwn head and tail, exclusive
   for (Node cur = L->head->next; cur != L->tail; cur = cur->next) {
      fprintf(out, "%d ",cur->data);
   }
   fprintf(out, "");

   return;
}

/**
 * @brief copies the contents of a list into a new list
 * @param L the list
 * @return List the new list
 */
List copyList(List L){
   assert(L);

   List newL = newList();

   //itterates through all the nodes btwn head and tail, exclusive
   for (Node cur = L->head->next; cur != L->tail; cur = cur->next){
      append(newL, cur->data);
   }

   return newL;
}


