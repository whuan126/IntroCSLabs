#include "Node.h"

using namespace std;

Node::Node (string temp) {
  data = temp;
  left = nullptr;
  right = nullptr;
  height = 1;
}

Node *Node::retLeft() { //Returns left val
  return left;
}

Node *Node::retRight() { //Returns right val
  return right;
}

void Node::setHeight (int h) { //Set height of tree = input
  height = h;
}

int Node::retHeight() { //Return height
  return height;
}

string Node::retVal() { //Return data
  return data;
}

void Node::setLeft(Node *tempL) {
  left = tempL;
}

void Node::setRight(Node *tempR) {
  right = tempR;
}