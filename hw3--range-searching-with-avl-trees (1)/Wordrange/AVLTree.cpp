/**
 * This AVL tree holds strings
 * @author UCSC, Marian Zlateva
 */

#include <iostream>
#include <assert.h>

#include "AVLTree.h"

using namespace std;


/**
 * Constructor for an AVLTree
 */
AVLTree :: AVLTree(){
  _root = NULL;
}

/**
 * Inserts a new data into the tree
 *
 * @param data - the data 
 */
void AVLTree :: insert(string data){
  
  //insert the data
  bool success = false;
  _root = insert(data, _root, success);
  
}

/**
 * Recursive private function for insert()
 * Inserts a node with data into the tree
 *
 * @param n - the node being inserted
 * @param lastAdded - the node that was just added 
 * 
 * @return - the new root after tree is balanced
 */
Node *AVLTree :: insert(string data, Node *cur, bool &success){
  
  //if there is no node in the current location, place the data there
  if(cur== NULL){
    
    success = true;
    Node *n = new Node(data);
    
    if(_root == NULL){
      _root = n;
    }
      
    return n;
  }
  
  //if data is less than cur, go to the left
  if(data < cur->getData()){
    cur->left = insert(data, cur->left, success);

  //if data is greater than cur, go to the right
  }else if(data > cur->getData()){
     cur->right = insert(data, cur->right, success);

  }else{
    //data = cur data and is already present in the tree
    return cur;
  }
  
  //if a new node was added, fix the cur node's properties and balance the tree
  if(success==true){
    
    cur->recalculateLevelsBelow();
    cur->descendants += 1;
    //return cur;
    return balanceSubtree(cur, data);
  
  //no node was added so no rebalancing needed
  }else{
    return cur;
  }
}

/**
 * Balances a subtree
 * NOTE: should only be called by insert()
 *
 * @param root - the root node of the subtree
 * @param lastAdded - the node that was just added 
 * 
 * @return - the new root after tree is balanced
 */
Node *AVLTree :: balanceSubtree(Node *root, string lastAddedData){
  
  //Balance factor = heightOfLeftSubtree - heightOfRightSubtree
  int balanceFactor = root->getBananceFactor();
  
  //if subtree is already balanced, terminate with no root change
  if(abs(balanceFactor) != 2){
    return root;
  }
  
  Node *newRoot = NULL;
  
  
  //positive balanceFactor = left heavy
  //negative balanceFactor = right heavy
  
  //LL case
  if(balanceFactor == 2 && lastAddedData < root->left->getData()){
    newRoot = rotateRight(root);

  //RR case
  }else if(balanceFactor == -2 && lastAddedData > root->right->getData()){
    newRoot = rotateLeft(root);

  //LR case
  }else if(balanceFactor == 2 && lastAddedData > root->left->getData()){
    root->left = rotateLeft(root->left);
    newRoot = rotateRight(root);
  
  //RL case
  }else if(balanceFactor == -2 && lastAddedData < root->right->getData()){
    root->right = rotateRight(root->right);
    newRoot = rotateLeft(root);
    
  }
  
  return newRoot;
}

/**
 * Rotates a subtree to the left
 * A,B,C,D represented here: https://youtu.be/1QSYxIKXXP4
 * 
 * @param root - the root node of the subtree
 * 
 * @return - the new root
 */
Node *AVLTree :: rotateLeft(Node *root){
  
  //save node pointers
  Node *R = root->right;
  Node *RR = root->right->right;
  
  Node *A = root->left;
  Node *B = root->right->left;

  //perform rotation
  R->left = root;
  R->right = RR;
  
  root->left = A;
  root->right = B;
  
  
  //fix descendants count
  root->recalculateDescendants();
  R->recalculateDescendants();
  
  
  //fix levels below
  root->recalculateLevelsBelow();
  R->recalculateLevelsBelow(); // this one must be called last
  
  
  return R;
}

/**
 * Rotates a subtree to the right
 * A,B,C,D represented here: https://youtu.be/1QSYxIKXXP4
 * 
 * @param root - the root node of the subtree
 * 
 * @return - the new root
 */
Node *AVLTree :: rotateRight(Node *root){
  
  //save node pointers
  Node *L = root->left;
  Node *LL = root->left->left;
  
  Node *C = root->left->right;
  Node *D = root->right;
  
  //perform rotation
  L->left = LL;
  L->right = root;
  
  root->left = C;
  root->right = D;
  
  //fix descendants count
  root->recalculateDescendants();
  L->recalculateDescendants(); 
  
  //fix levels below
  root->recalculateLevelsBelow();
  L->recalculateLevelsBelow(); // this one must be called last
  
  return L;
}

int AVLTree :: countBtwn(string min, string max){
  // root + root's descendants - less than min - greater than max
  return 1 + _root->descendants - getLessThanTarget(_root, min) - getGreaterThanTarget(_root, max);
}

/**
 * Counts the number of nodes less than the target
 * 
 * @param cur - the root node
 * @param target - the target value
 * 
 * @return - the number of nodes less than the target 
 */
int AVLTree :: getLessThanTarget(Node *cur, string target){
  if(cur==NULL){
    return 0;
  }
  
  string curData = cur->getData();
  
  int leftTree = 0, curNode = 0, rightTree = 0;
  
  //-----------------
  
  //conditions:
  if(curData < target){
    //left: everything to the left is less than the target
    //cur: this node is less than the target
    //right: we are unsure about the right
    
    leftTree = cur->getLeftCount();
    curNode = 1;
    rightTree = getLessThanTarget(cur->right, target);

  }else if(curData > target){
    //left: we are unsure about the left
    //cur: this node greater than the target
    //right: everything to the right greater than the target
    
    leftTree = getLessThanTarget(cur->left, target);
    curNode = 0;
    rightTree = 0;
    
  }else if(curData == target){
    //left: everything to the left of this node is less than the target
    //cur: this node is = to the target
    //right: everything to the right is greater than the target
    
    leftTree = cur->getLeftCount();
    curNode = 0;
    rightTree = 0;
    
  }
  
  return leftTree+curNode+rightTree;
}

/**
 * Counts the number of nodes greater than the target
 *
 * @param cur - the root node
 * @param target - the target value
 * 
 * @return - the number of nodes greater than the target 
 */
int AVLTree :: getGreaterThanTarget(Node *cur, string target){
  if(cur==NULL){
    return 0;
  }
  
  string curData = cur->getData();
  
  int leftTree = 0, curNode = 0, rightTree = 0;
  
  //-----------------
  
  //conditions:
  if(curData < target){
    //left: everything to the left is less than the target
    //cur: this node is less than the target
    //right: we are unsure about the right
    
    leftTree = 0;
    curNode = 0;
    rightTree = getGreaterThanTarget(cur->right, target);

  }else if(curData > target){
    //left: we are unsure about the left
    //cur: this node greater than the target
    //right: everything to the right greater than the target
    
    leftTree = getGreaterThanTarget(cur->left, target);
    curNode = 1;
    rightTree = cur->getRightCount();
    
  }else if(curData == target){
    //left: everything to the left of this node is less than the target
    //cur: this node is = to the target
    //right: everything to the right is greater than the target
    
    leftTree = 0;
    curNode = 0;
    rightTree = cur->getRightCount();
    
  }
  
  return leftTree+curNode+rightTree;
}

/**
 * DEBUG ONLY
 * prints the tree
 */
void AVLTree :: print(){
  cout<<"printing tree"<<endl;
  print("",_root,false);
}

/**
 * Recursive helper function to print()
 * tree printing algorithm src: https://stackoverflow.com/a/51730733
 *
 * @param prefix - the prefix to the current print
 * @param cur - the current node being printed
 * @param isLeft - true if the current node is the left node
 */
void AVLTree :: print(string prefix, Node *cur, bool isLeft){
  if(cur == NULL){
    return;
  }
  
  cout<<prefix;
  
  if(!isLeft){
    cout<<"├──";
    prefix+="│   ";
  }else{
    cout<<"└──";
    prefix+="    ";
  }
  

  cout<<cur->toString()<<endl;
  
  
  print(prefix,cur->right,false);
  print(prefix,cur->left,true);
  
}