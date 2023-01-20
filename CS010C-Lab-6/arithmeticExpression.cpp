#include <iostream>
#include <cstdlib>
#include <cctype>
#include <sstream>
#include <fstream>
#include <stack>
#include <queue>

#include "arithmeticExpression.h"

using namespace std;

arithmeticExpression::arithmeticExpression(const string &val) {
  infixExpression = val;
  root = 0;
}

TreeNode* arithmeticExpression::getRoot() {
  return root;
}

/* Converts the infixExpression to its equivalent postfix string
       and then generates the tree and assigns the root node to the 
       root data field. The key for the first node is 'a', 'b' for the second node and so on. */
void arithmeticExpression::buildTree() {
  string postfixExpression = infix_to_postfix();
  char firstKey = 'a';
  stack<TreeNode *> stack;
  for (unsigned int i = 0; i < postfixExpression.size(); i++) {
    char b = postfixExpression.at(i);
    if (b == '+'|| b == '-'|| b == '*'|| b =='/') {
      TreeNode* newRoot = new TreeNode(b, firstKey + i);
      newRoot -> left = stack.top();
      stack.pop();
      newRoot -> right = stack.top();
      stack.pop();
      stack.push(newRoot);
    }
    else {
      stack.push(new TreeNode(b, firstKey + i));
    } 
  }
  root = stack.top();
  stack.pop();
}

void arithmeticExpression::infix() {
  if (root == 0) {
    return;
  }
  else {
    infix(root);
  }
  return;
}

void arithmeticExpression::infix (TreeNode *root) { //Helper function for infix
  if (root) {
    if (root -> left != nullptr || root -> right != nullptr) {
      cout << "(";
    }
    infix (root -> right);
    cout << root -> data;
    infix (root -> left);
    if (root -> left != 0 || root -> right) {
      cout << ")";
    }
  }
  else {
    return;
  }
}

void arithmeticExpression::prefix() {
  if (root == 0) {
    return;
  }
  else {
    prefix(root);
  }
  return;
}

void arithmeticExpression::prefix(TreeNode *root) { //Helper function for prefix
  if (root) {
    cout << root -> data;
    prefix(root -> right);
    prefix(root -> left);
  }
  else {
    return;
  }
}

void arithmeticExpression::postfix() {
  if (root == 0) {
    return;
  }
  else {
    postfix(root);
  }
}

void arithmeticExpression::postfix(TreeNode *root) {
  if (root) {
    postfix(root -> right);
    postfix(root -> left);
    cout << root -> data;
  }
  else {
    return;
  }
}

int arithmeticExpression::evaluate() {
  //try {
    if (root == 0) {
      return 0;
    }
    if (root != nullptr) {
      return evaluateIntegerExpression(root);
    }
    else {
      throw std::invalid_argument("expression not valid");
    }
    return 0;
  //}
  // catch (std::invalid_argument const&) {
  //    cout << "expression not valid" << endl;
  //    exit(0);
  // }
  return 0;
  // throw invalid_argument("expression not valid");
}

int arithmeticExpression::evaluateIntegerExpression(TreeNode *root) {
  //try {
    //isValidIntegerExpression(root);
    if (isValidIntegerExpression(root) == true) {
    //    throw invalid_argument("expression not valid");
    // }
      if (detectInt(root->data)) {
        return root->data-'0';
      }
      char op = root->data;
      
      int left = evaluateIntegerExpression(root->left);
      int right = evaluateIntegerExpression(root->right);
      if (op == '+') {
        return (left + right);
      }
      if (op == '-') {
        return right - left;
      }
      if (op == '*') {
        return (left * right);
      }
      if (op == '/') {
        return (left / right);
      }
    }
    else {
      throw std::invalid_argument("expression not valid");
      exit(0);
    }
  //}
  // catch (std::invalid_argument const&) {
  //   std::cout << "expression not valid" << endl;
  // }
  return 0;
 }

bool arithmeticExpression::detectInt(char ok) {
  if (ok == '+') {
    return false;
  }
  if (ok == '-') {
    return false;
  }
  if (ok == '*') {
    return false;
  }
  if (ok == '/') {
    return false;
  }
  return true;
}

bool arithmeticExpression::isValidIntegerExpression(TreeNode *root) {
  //try {
    if (root == nullptr) {
      //return false;
      throw std::invalid_argument("expression not valid");
    }
    if (root -> left != nullptr) {
      return isValidIntegerExpression(root -> left);
    }
    if (root -> right != nullptr) {
      return isValidIntegerExpression(root -> right);
    }
    if (root -> data == '+' || root -> data == '-' || root -> data == '*' || root -> data == '/'|| root -> data == '1' || root -> data == '2' || root -> data == '3' || root -> data == '4' || root -> data == '5' || root -> data == '6' || root -> data == '7' || root -> data == '8' || root -> data == '9') {
      return true;
    }
    else {
      throw std::invalid_argument("expression not valid");
    }
  //}
  // catch (std::invalid_argument const&) {
  //   cout << "expression not valid" << endl;
  //   exit(0);
  // }
  return true;
}

void arithmeticExpression::visualizeTree(ofstream &out, TreeNode *root) {
  out << "testing123";
}

int arithmeticExpression::priority(char op) {
    int priority = 0;
    if(op == '('){
        priority =  3;
    }
    else if(op == '*' || op == '/'){
        priority = 2;
    }
    else if(op == '+' || op == '-'){
        priority = 1;
    }
    return priority;
}

string arithmeticExpression::infix_to_postfix(){
    stack<char> s;
    ostringstream oss;
    char c;
    for(unsigned i = 0; i< infixExpression.size();++i){
        c = infixExpression.at(i);
        if(c == ' '){
            continue;
        }
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
            if( c == '('){
                s.push(c);
            }
            else if(c == ')'){
                while(s.top() != '('){
                    oss << s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty() && priority(c) <= priority(s.top())){
                    if(s.top() == '('){
                        break;
                    }
                    oss << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else{ //c is an operand
            oss << c;
        }
    }
    while(!s.empty()){
        oss << s.top();
        s.pop();
    }
    return oss.str();
  }

void arithmeticExpression::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error opening "<< outputFilename<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}