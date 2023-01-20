#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index) { //Passes in an index of type int and a vector of type T (T could be string, double or int).
  int minIndex = index;
  for (unsigned i = index + 1; i < vals.size(); i++) {
    if(vals.at(i) < vals.at(minIndex)) {
      minIndex = i;
    }
  }
  //The function returns the index of the min value starting from "index" to the end of the "vector".
  return minIndex;
}

template<typename T>
void selection_sort(vector<T> &vals) { //Passes in a vector of type T and sorts them based on the selection sort method.
  T temp;
  unsigned minIndex;

  for(unsigned i = 0; i < vals.size(); i++) { //This function should utilize the min_index function to find the index of the min value in the unsorted portion of the vector.
    minIndex = min_index(vals, i);
    temp = vals[minIndex];
    vals[minIndex] = vals[i];
    vals[i] = temp;
  }
}

template<typename T>
T getElement(vector<T> vals, int index) { //Passes in a vector of type T (T could be string, double or int) and an index of type int.
  if (index < 0) {
    throw runtime_error("std::outofrange");
  }
  return vals.at(index);
}

vector<char> createVector(){
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++) {
      vals.push_back(c);
      c++;
    }
    return vals;
}

int main() {
  vector<int> intTest {1, 2, 3, 4, 5, 6};
  selection_sort(intTest);
  for (unsigned int i = 0; i < intTest.size(); i++ ) {
    if (i == intTest.size() - 1) {
      cout << intTest.at(i) << endl;
    }
    else {
      cout << intTest.at(i) << " ";
    }
  }
  
  vector<double> doubleTest {1.33, 2.44, -4.99, 3.55, 4.66, -5.66, 5.77, 6.88};
  selection_sort(doubleTest);
  for(unsigned int i = 0; i < doubleTest.size(); i++) {
    if (i == doubleTest.size() - 1) {
      cout << doubleTest.at(i) << endl;
    }
    else {
      cout << doubleTest.at(i) << " ";
    }
  }

  vector<string> charTest {"bob", "ross", "steve", "irwin"};
  selection_sort(charTest);
  for (unsigned int i = 0; i < charTest.size(); i++) {
    if (i == charTest.size() - 1) {
      cout << charTest.at(i) << endl;
    }
    else {
      cout << charTest.at(i) << " ";
    }
  }

//Part B
  srand(time(0));
  vector<char> vals = createVector();
  char curChar;
  int index;
  int numOfRuns = 10;
  
  try {
    while(--numOfRuns >= 0){
        cout << "Enter a number: " << endl;
        cin >> index;
        curChar = getElement(vals,index);
        cout << "Element located at " << index << ": is " << curChar << endl;
    }
  }
    catch(runtime_error &excpt) {
      cout << excpt.what() << endl;
      cout << "Out of range exception" << endl;
    }

  return 0;
  }