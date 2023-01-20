#ifndef Node_H
#define Node_H

#include <string>

using namespace std;

class Node {
 public:  
  Node(string temp);
  Node* retLeft();
  Node* retRight();
  void setHeight(int);
  int retHeight();
  string retVal();
  void setLeft(Node*);
  void setRight(Node*);

 private:
  int height;
  string data;
  Node *left;
  Node *right;
};

#endif