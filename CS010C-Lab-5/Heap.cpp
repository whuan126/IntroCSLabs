#include <algorithm>
#include <ostream>
#include <iostream>

#include "Heap.h"
#include "PrintJob.h"

using namespace std;

Heap::Heap() {
  numItems = 0;
}

void Heap::enqueue(PrintJob *toPrint) { 
  int temp;
  if (numItems < MAX_HEAP_SIZE) {
    if (numItems == 0) { //Checking to see if numItems violates MAX_HEAP.
      arr[numItems] = toPrint;
      numItems = numItems + 1;
    }
    else {
      temp = numItems;
      arr[numItems] = toPrint;
      numItems = numItems + 1;
      while ((temp != 0) && (toPrint -> getPriority() > arr[(temp-1)/2] -> getPriority())) {
        swap(arr[(temp-1)/2], arr[temp]);
        temp = (temp-1)/2;
      }
    }
    // while (temp != 0) {
    //   if (toPrint -> getPriority() > arr[tempVal] -> getPriority()) {
    //     swap(arr[tempVal], arr[temp]);
    //     temp = tempVal;
    //   }
    // }
  }
}

void Heap::print() {
  cout << "Priority: " << arr[0] -> getPriority() << ", Job Number: " << arr[0] -> getJobNumber() << ", Number of Pages: " << arr[0] -> getPages() << "\n";
}

void Heap::dequeue() { 
  if (numItems == 0) { //Empty heap
    return;
  }
  else if (numItems == 1) {
    arr[0] = 0;
    numItems = 0;
    return;
  }
  else {
    PrintJob *remove = arr[0];
    arr[0] = arr[numItems - 1];
    numItems = numItems - 1;
    delete (remove);
    trickleDown(0);
  }
}

PrintJob *Heap::highest() {
  if (numItems == 0) {
    return 0;
  }
  else {
    return arr[0];
  }
  return arr[0];
}

void Heap::trickleDown(int temp) {
  int root = temp;
  int left, right;
  right = 2*root+2;
  left = 2*root+1;
  if (left > numItems && right > numItems) {
    return;
  }
  else { 
    for (int i = 0; i < numItems; i++) {
      if (arr[root] -> getPriority() < arr[i] -> getPriority()) {
        PrintJob *val = arr[root];
        arr[root] = arr[i];
        arr[i] = val;
      }
    }
  }
}