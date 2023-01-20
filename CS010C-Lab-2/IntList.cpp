#include <iostream>

using namespace std;

#include "IntList.h"

IntList::IntList() { //Initializes an empty list with dummy head and dummy tail.
  dummyHead = new IntNode(0);
  dummyTail = new IntNode(0);
  dummyHead -> next = dummyTail;
  dummyTail -> prev = dummyHead;
}

IntList::~IntList() { //Deallocates all remaining dynamically allocated memory.
  IntNode *temp;
  IntNode *nextPtr = dummyHead -> next;

  while (nextPtr != dummyTail) {
    temp = nextPtr;
    nextPtr = nextPtr -> next;
    delete temp;
  }
  delete dummyHead;
  delete dummyTail;
}

void IntList::push_front(int value) { //Inserts a data value (within a new node) at the front end of the list. No for loops?

  IntNode *newNode = new IntNode(value);
  dummyHead -> next -> prev = newNode;
  newNode -> next = dummyHead -> next;
  dummyHead -> next = newNode;
  newNode -> prev = dummyHead;
}

ostream & operator << (ostream &out, const IntList &rhs) {
  IntNode *temp = rhs.dummyHead -> next;
  while (temp != rhs.dummyTail) {
    if (temp -> next != rhs.dummyTail) { //Outputs to the stream all of the integer values within the list on a single line, each separated by a space.
      out << temp -> data << " ";
    }
    else { //This function does NOT send to the stream a newline or space at the end.
      out << temp -> data;
    }
    temp = temp -> next;
  }
  return out;
  delete temp;
}

bool IntList::empty() const {
  if ((dummyHead -> next == dummyTail) && (dummyTail -> prev == dummyHead)) {
    return true;
  }
  else {
    return false;
  }
}

void IntList::pop_front() {
  if (empty()) { //Does nothing if the list is already empty.
    return;
  }
  else { //Removes the node at the front end of the list (the node after the dummy head)
    IntNode *front = dummyHead -> next;
    dummyHead -> next = dummyHead -> next -> next;
    front -> next -> prev = dummyHead;
    delete front;
  }
}

void IntList::push_back(int value) { //Inserts a data value (within a new node) at the back end of the list.
  
  IntNode *newNode = new IntNode(value);
  IntNode *temp = dummyTail -> prev;
  newNode -> prev = temp;
  temp -> next = newNode;
  newNode -> next = dummyTail;
  dummyTail -> prev = newNode;
}

void IntList::pop_back() { //Did not work on submission, but works in compiler.
  if (empty()) {
    return;
  }
  else { //Removes the node at the back end of the list (the node before the dummy tail)
    IntNode *back = dummyTail -> prev;
    dummyTail -> prev = back -> prev;
    back -> prev -> next = dummyTail;
    delete back;
  }
}

void IntList::printReverse() const {
  IntNode *reverse = dummyTail -> prev;
  if(empty()) {
    return;
  }
  else {
    while (reverse != nullptr) {
      if (reverse -> prev != 0) {
        cout << reverse -> data << " ";
      }
    reverse = reverse -> prev;
    //   if (reverse != dummyHead) { //prints to a single line all of the int values stored in the list in REVERSE order, each separated by a space
    //     cout << reverse -> data << " ";
    //   }
    //   else { //This function does NOT output a newline or space at the end.
    //     cout << reverse -> data;
    //   }
    //   reverse = reverse -> prev;
    }
  }
  delete reverse;
}