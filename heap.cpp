//Completed By: Vedant Shah
// heap.cpp
// Diba Mirza

#include "heap.h"
#include <iostream>
using namespace std;

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
  vdata.push_back(value);
  int current = vdata.size()-1;
  while(current > 0 && vdata[current] > vdata[(current-1)/2]){
    int temp = vdata[(current-1)/2];
    vdata[(current-1)/2] = vdata[current];
    vdata[current] = temp;
  }
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
  if(vdata.size() == 0){
    return;
  }
  vdata[0] = vdata[vdata.size()-1];
  vdata.pop_back();

  int current = 0;
  while(current*2+1 < vdata.size() && (vdata[current] > vdata[current*2+1] || vdata[current] > vdata[current*2+2])){
    if(vdata[current*2+1] < vdata[current*2+2]){
      int temp = vdata[current];
      vdata[current] = vdata[current*2+1];
      vdata[current*2+1] = temp;
      current = current*2+1;
    }
    else{
      int temp = vdata[current];
      vdata[current] = vdata[current*2+2];
      vdata[current*2+2] = temp;
      current = current*2+2;
    }

    if(current*2+1 < vdata.size()){
      return;
    }
  }
}

// Returns the minimum element in the heap
int Heap::top(){
  cout << vdata[0] << endl;
  return vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  if(vdata.size()>0) return false;
  return true;
}
    