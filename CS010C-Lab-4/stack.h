#ifndef STACK_H
#define STACK_H

#include <stdexcept>

using namespace std;

int const MAX_SIZE = 20;

template<typename T>
class stack {
 private:
  T data[MAX_SIZE];
  int numElements;

 public:
  stack();
  void push(T val);
  void pop();
  void pop_two();
  T top();
  bool empty();
};

template<typename T>
stack<T>::stack() { //stack(): constructs an empty stack.
  numElements = 0;
}

template<typename T>
void stack<T>::push(T val) { //inserts a new element (val) of type T (T could be integer or string) into the data.
  if (numElements == MAX_SIZE) { //If the data array is full, this function should throw an overflow_error exception with error message "Called push on full stack.".
    throw overflow_error("Called push on full stack.");
  }
  data[numElements] = val;
  numElements++;
}

template<typename T>
void stack<T>::pop() { //removes the last element from data.
  if (numElements == 0) { //If the data array is empty, this function should throw an outofrange exception with error message "Called pop on empty stack.".
    throw out_of_range("Called pop on empty stack.");
  }
  numElements--;
}

template<typename T>
void stack<T>::pop_two() { //removes the last two elements from data.
  if (numElements == 0) { //If empty then the error message should be "Called pop_two on empty stack.".
    throw out_of_range("Called pop_two on an empty stack.");
  }
  else if(numElements == 1) { //If the size is 1 then the error message should be "Called pop_two on a stack of size 1.".
    throw out_of_range("Called pop_two on a stack of size 1.");
  }
  numElements = numElements - 2;
}

template<typename T>
T stack<T>::top() { //returns the top element of stack (last inserted element).
  if (numElements == 0) { //If stack is empty, this function should throw an underflow_error exception with error message "Called top on empty stack.".
    throw underflow_error("Called top on empty stack.");
  }
  return data[numElements - 1];
}

template<typename T>
bool stack<T>::empty() {
  if (numElements == 0) {
    return true;
  }
  else {
    return false;
  }
}

#endif