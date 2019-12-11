#include <iostream>
#include <cstdlib>
#include <fstream>
#include <chrono>
#include <ctime>

using namespace std;

void bubbleSort(double arr[], int size);
void selectionSort(double arr[], int size);
void insertSort(double arr[], int size);
void mergeSort(double arr[], int lowIdx, int highIdx);
void quickSort(double arr[], int lowIdx, int highIdx);

int main(int argc, char** argv){
  /*
  //---Generate Text File---
  int numsToGenerate = 750000;
  ofstream output;
  output.open("numbers.txt");
  for (int i=0; i < numsToGenerate; i++){
    output << rand()%numsToGenerate << "\n";
  }
  output.close();
  */

  ///*
  //---Create Arrays---
  //Create first array
  string file = argv[1];
  ifstream input(file);
  string temp;
  getline(input, temp);
  int num = stoi(temp);
  double arr[num];
  for(int i=0; i<num; i++){
    string temp;
    getline(input, temp);
    arr[i] = stod(temp);
  }
  double newArr[num];
  //*/

  //---Sorting algorithms---
  //bubbleSort(arr, num);
  //selectionSort(arr, num);
  //insertSort(arr, num);
  //mergeSort(arr, 0, num-1);

  ///---Run and Print---
  auto timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());
  /*
  for(int i=0; i<num; i++){
    newArr[i] = arr[i];
  }
  cout << "Start of Bubble: " << ctime(&timenow);
  bubbleSort(newArr, num);
  timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());
  cout << "End of Bubble: " << ctime(&timenow) << endl;

  for(int i=0; i<num; i++){
    newArr[i] = arr[i];
  }
  timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());
  cout << "Start of Selection: " << ctime(&timenow);
  selectionSort(newArr, num);
  timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());
  cout << "End of Selection: " << ctime(&timenow) << endl;

  for(int i=0; i<num; i++){
    newArr[i] = arr[i];
  }
  timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());
  cout << "Start of Insert: " << ctime(&timenow);
  insertSort(newArr, num);
  timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());
  cout << "End of Insert: " << ctime(&timenow) << endl;
  */

  /*
  for(int i=0; i<num; i++){ //CLUNKS OUT BETWEEN 330,000 and 350,000
    newArr[i] = arr[i];
  }
  timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());
  cout << "Start of Merge: " << ctime(&timenow);
  mergeSort(newArr, 0, num-1);
  timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());
  cout << "End of Merge: " << ctime(&timenow) << endl;
  */

  ///*
  for(int i=0; i<num; i++){ //CLUNKS OUT BETWEEN 500,000 and 750,000
    newArr[i] = arr[i];
  }
  timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());
  cout << "Start of Quick: " << ctime(&timenow);
  quickSort(newArr, 0, num-1);
  timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());
  cout << "End of Quick: " << ctime(&timenow) << endl;
  //*/

  /*
  //---Print Whole Array--- (For Debugging)
  for(int i=0; i < num; i++){
    cout << newArr[i] << endl;
  }
  */
}


void bubbleSort(double arr[], int size){
  for(int i=0; i<size; ++i){
    double temp = 0;
    for(int j=0; j<size-1; ++j){
      if(arr[j]>arr[j+1]){
        temp = arr[j+1];
        arr[j+1] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

void selectionSort(double arr[], int size){
  int i, j, minIndex;
  double temp;
  for (i=0; i<size-1; i++){
    minIndex = i;
    for(j=i+1; j<size; j++){
      if(arr[j] < arr[minIndex]){
        minIndex = j;
      }
    }
    if(minIndex != i){
      temp = arr[i];
      arr[i] = arr[minIndex];
      arr[minIndex] = temp;
    }
  }
}

void insertSort(double arr[], int size){
  for(int j=1; j<size; j++){ //marker
    double temp = arr[j]; //store marked item
    int k = j; //where to start shifting
    while (k>0 && arr[k-1] >= temp){ //while the thing to the left is larger, shift. USUSALLY SKIPPPED FOR PARTIALLY SORTED SETS, ALMOST LINEAR
      arr[k] = arr[k-1];
      --k;
    }
    arr[k] = temp; //put parked item in the right spot
  }
}

void mergeSort(double arr[], int lowIdx, int highIdx){
  int midIdx;
  if(lowIdx<highIdx){
    midIdx = (highIdx+lowIdx)/2;
    mergeSort(arr, lowIdx, midIdx);
    mergeSort(arr, midIdx+1, highIdx);
    double arrNew[highIdx-lowIdx+1];
    int i=lowIdx;
    int j=midIdx+1;
    int pos = 0;
    while(i<= midIdx && j<= highIdx){
      if(arr[i]<arr[j]){
        arrNew[pos] = arr[i];
        ++i;
        ++pos;
      }else{
        arrNew[pos] = arr[j];
        ++j;
        ++pos;
      }
    }
    while(i<=midIdx){
      arrNew[pos] = arr[i];
      ++i;
      ++pos;
    }
    while(j<=highIdx){
      arrNew[pos] = arr[j];
      ++j;
      ++pos;
    }
    for(int i=lowIdx; i<=highIdx; i++){
      arr[i] = arrNew[i-lowIdx];
    }
  }
}

void quickSort(double arr[], int lowIdx, int highIdx){
  if(lowIdx < highIdx){
    int pivot = arr[highIdx];
    int i = (lowIdx-1);
    for(int j=lowIdx; j<=highIdx-1; ++j){
      if(arr[j]<=pivot){
        ++i;
        double temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
    double temp = arr[i+1];
    arr[i+1] = arr[highIdx];
    arr[highIdx] = temp;
    int pi = i+1;
    quickSort(arr, lowIdx, pi-1);
    quickSort(arr, pi+1, highIdx);
  }
}
