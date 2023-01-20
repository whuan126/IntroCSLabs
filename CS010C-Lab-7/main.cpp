#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int NUMBERS_SIZE = 50000;

int genRandInt(int low, int high) {
   return low + rand() % (high - low + 1);
}

void fillArrays(int arr1[], int arr2[],int arr3[]){
    for(int i = 0; i < NUMBERS_SIZE; ++i){
        arr1[i] = genRandInt(0, NUMBERS_SIZE);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
}

void Quicksort_Midpoint (int numbers[], int i, int k) {

  if (i + 1 == k) {
    if (numbers[i] > numbers[k]) {
      int temp = numbers[i];
      numbers[i] = numbers[k];
      numbers[k] = temp;
    }
    return;
  }
  if (i >= k) {
    return;
  }
  
  int pivot = numbers[i + (k - i)/2];   //provided by zyBooks
  int leftP = i - 1;
  int rightP = k + 1;
  while (leftP <= rightP) {
    do {
      leftP++;
    } 
    while (numbers[leftP] < pivot);

    do {
      rightP--;
    } 
    while (numbers[rightP] > pivot);

    if (leftP <= rightP) {
      int tempP = numbers[leftP];
      numbers[leftP] = numbers[rightP];
      numbers[rightP] = tempP;
    }
  }
  Quicksort_Midpoint(numbers, i, rightP);
  Quicksort_Midpoint(numbers, rightP + 1, k);
}

int part(int numbers[], int i, int k) {
  int mid = numbers[i + (k - i) / 2];
  int median;
  if (numbers[i] < numbers[mid] && numbers[mid] < numbers[k]) {
    median = mid;
  }
  else if(numbers[i] < numbers[mid] && numbers[i] > numbers[k]) {
    median = i;
  }
  else {
    median = k;
  }
  return median;
}

void Quicksort_MedianOfThree(int numbers[], int i, int k) {
  if (i + 1 == k) {
    if (numbers[i] > numbers[k]) {
      int tempM = numbers[i];
      numbers[i] = numbers[k];
      numbers[k] = tempM;
    }
    return;
  }
  if (i >= k) {
    return;
  }

  int partition = part(numbers, i, k);     //partition
  int leftM = i - 1;
  int rightM = k + 1;
  while (leftM <= rightM) {
    do {
      leftM++;
    }
    while (numbers[leftM] < partition);

    do {
      rightM--;
    }
    while (numbers[rightM] > partition);

    if (leftM <= rightM) {
      int tempM = numbers[leftM];
      numbers[leftM] = numbers[rightM];
      numbers[rightM] = tempM;
    }
  }
  Quicksort_Midpoint(numbers, i, rightM);
  Quicksort_Midpoint(numbers, rightM + 1, k);
}

void InsertionSort(int numbers[], int numbersSize) {
  int key;

  for (int i = 1; i < numbersSize; i++) {
    key = numbers[i];
    int y = i - 1;
    while (y >= 0 && numbers[y] > key) {
      numbers[y + 1] = numbers[y];
      y--;
    }
    numbers[y + 1] = key;
  }
}

int main() {
  int arr1[NUMBERS_SIZE];
  int arr2[NUMBERS_SIZE];
  int arr3[NUMBERS_SIZE];
  fillArrays(arr1, arr2, arr3);
  const int CLOCKS_PER_MS = CLOCKS_PER_SEC / 1000;

  clock_t Start1 = clock();
  Quicksort_Midpoint(arr1, 0, NUMBERS_SIZE - 1);//call sort function here
  clock_t End1 = clock();
  int elapsedTime1 = (End1 - Start1)/ CLOCKS_PER_MS; // converts elapsed time from  microseconds to milliseconds.
  cout << "Quicksort_Midpoint Time: " << elapsedTime1;
  cout << endl;

  clock_t Start2 = clock();
  Quicksort_MedianOfThree(arr2, 0, NUMBERS_SIZE);
  clock_t End2 = clock();
  int elapsedTime2 = (End2 - Start2) / CLOCKS_PER_MS;
  cout << "Quicksort_MedianOfThree Time: " << elapsedTime2;
  cout << endl;

  clock_t Start3 = clock();
  InsertionSort(arr3, NUMBERS_SIZE);
  clock_t End3 = clock();
  int elapsedTime3 = (End3 - Start3) / CLOCKS_PER_MS;
  cout << "InsertionSort Time: " << elapsedTime3;
  cout << endl;
}