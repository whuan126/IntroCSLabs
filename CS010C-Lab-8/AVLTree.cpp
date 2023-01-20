#include "AVLTree.h"

using namespace std;

void AVLTree::visualizeTree(const string &outputFilename) { //Provided
  ofstream outFS(outputFilename.c_str());
  if (!outFS.is_open()) {
    cout << "Error" << endl;
    return;
  }
  outFS << "digraph G {" << endl;
  visualizeTree(outFS, root);
  outFS << "}";
  outFS.close();
  string jpgFilename = outputFilename.substr(0, outputFilename.size() - 4)+ ".jpg";
  string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
  system(command.c_str());
}

void AVLTree::visualizeTree(ofstream & outFS, Node *n){ //Provided
  if(n) {
    if(n -> retLeft()) {
      visualizeTree(outFS,n -> retLeft());
      outFS << n -> retVal() << " -> " << n -> retLeft() -> retVal() <<";"<< endl;    
    }

    if(n -> retRight()) {
      visualizeTree(outFS,n -> retRight());
      outFS << n -> retVal() << " -> " << n -> retRight() -> retVal() << ";" << endl;    
    }
  }
}

AVLTree::AVLTree() {
  root = nullptr;
}

void AVLTree::printBalanceFactors() {
  printBalanceFactors(root);
}

void AVLTree::printBalanceFactors(Node *nroot) {
  if(nroot != nullptr) {
    printBalanceFactors(nroot -> retLeft());
    cout << nroot -> retVal() << "(" << balanceFactor(nroot) << "), ";
    printBalanceFactors(nroot -> retRight());
  }
}

Node* AVLTree::insert(Node* nroot, string temp) {
  if(nroot == nullptr) {
    return (new Node(temp));
  }
  if(temp < nroot -> retVal()) {
    nroot-> setLeft(insert(nroot -> retLeft(), temp));
  }
  else if(temp > nroot -> retVal()) {
    nroot -> setRight(insert(nroot -> retRight(), temp));
  }
  else {
    return nroot;
  }
  nroot -> setHeight(1 + max(height(nroot -> retLeft()), height(nroot -> retRight())));
  int balanceF = balanceFactor(nroot);
  if(balanceF < -1 || balanceF > 1) {
    return rotate(nroot, temp, balanceF);
  } 
  return nroot;
}

Node *AVLTree::rotate(Node *nroot, string temp, int bal)  {
  if(bal > 1 && temp > nroot -> retLeft() -> retVal()) {
    nroot -> setLeft(rotateLeft(nroot -> retLeft()));
    return rotateRight(nroot);
  }
  else if(bal > 1 && temp < nroot -> retLeft() -> retVal()) {
    return rotateRight(nroot);
  }
  else if(bal < -1 && temp > nroot -> retRight() -> retVal()) {
    return rotateLeft(nroot);
  }
  else if(bal < -1 && temp < nroot -> retRight() -> retVal()) {
    nroot -> setRight(rotateRight(nroot -> retRight()));
    return rotateLeft(nroot);
  }
  else {
    return nroot;
  }
}

Node *AVLTree::rotateRight(Node *right) {
  Node *temp = right -> retLeft();
  Node *rChild = temp -> retRight();
  temp -> setRight(right);
  right -> setLeft(rChild);
  right -> setHeight(max(height(right -> retLeft()), height(right -> retRight())) + 1);
  temp -> setHeight(max(height(temp -> retLeft()), height(temp -> retRight())) + 1);
  return temp;
}

Node *AVLTree::rotateLeft(Node *left) {
  Node *temp = left -> retRight(); 
  Node *lChild = temp -> retLeft();
  temp -> setLeft(left);
  left -> setRight(lChild);
  left -> setHeight(max(height(left -> retLeft()), height(left -> retRight())) + 1);
  temp -> setHeight(max(height(temp -> retLeft()), height(temp -> retRight())) + 1);
  return temp;
}

void AVLTree::insert(const string &temp) {
   root = insert(root, temp);
}

int AVLTree::balanceFactor(Node* nroot)  {
  if (nroot == nullptr){
    return 0;
  }
  return height(nroot -> retLeft()) - height(nroot -> retRight());
}

int AVLTree::height(Node *nroot) {
  if(nroot == nullptr) {
    return 0;
  }
  return nroot -> retHeight();
}