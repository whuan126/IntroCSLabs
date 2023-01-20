#ifndef AVLTree_H
#define AVLTree_H

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

#include "Node.h"

class AVLTree {  
 public:
  AVLTree(); //Base case, set root to null
  void insert(const string &); //Insert an item to the binary search tree and perform rotation if necessary.
  int balanceFactor(Node*); //Return the balance factor of a given node.
  void printBalanceFactors(); //Traverse and print the tree in inorder notation. Print the string followed by its balance factor in parentheses followed by a , and one space.
  void visualizeTree(const string &); //Generate dotty file and visualize the tree using dotty program. Call this function before and after rotation.
   
 private:
  Node *root;
  int height(Node *); 
  Node *insert(Node *, string); 
  Node *rotate(Node *, string, int);
  Node *rotateRight(Node *);
  Node *rotateLeft(Node *);
  void printBalanceFactors(Node *); 
  void visualizeTree(ofstream &, Node *);
};

#endif