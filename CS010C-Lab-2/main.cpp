#include <iostream>

using namespace std;

#include "IntList.h"

int main() {
  IntList *newList = new IntList;

  if (newList -> empty() == true) {
    cout << "List is empty" << endl;
  }
  
  cout << "Push front numbers" << endl;
  newList -> push_front(5);
  newList -> push_front(7);
  newList -> push_front(14);
  newList -> push_front(10);
  newList -> push_front(21);
  cout << "Test push front " << *newList << endl;
  cout << endl;

  newList -> pop_front();
  cout << "Test pop front " << *newList << endl;
  cout << endl;

  newList -> push_back(100);
  cout << "Test push back 1 " << *newList << endl;
  newList -> push_back(420);
  cout << "Test push back 2 " << *newList << endl;
  cout << endl;

  newList -> pop_back();
  cout << "Test pop back " << *newList << endl;
  newList -> pop_front();
  cout << "Test pop front " << *newList << endl;
  newList -> pop_back();
  cout << "Test pop back " << *newList << endl;
  cout << endl;

  cout << "Test print reverse ";
  newList -> printReverse();
  cout << endl << endl;

  IntList *rev = new IntList;
  //rev -> push_back(-51);
  rev -> push_back(75);
  //rev -> push_back(-34);
  rev -> push_back(20);
  cout << "Print original " << *rev << endl;
  cout << "Test print reverse with two ints ";
  rev -> printReverse();
  cout << endl;
}