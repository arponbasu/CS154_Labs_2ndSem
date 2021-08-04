#include <iostream>
using namespace std;

int* leftShift (int* arr, int n){
  int first = arr[0];
  for(int i = 0; i < n - 1; i++){
    arr[i] = arr[i+1];
  }
arr[n-1] = first;
return arr;
}

void printArray (int* arr, int n){
  for(int i = 0; i < n; i++){
    cout << arr[i];
  }
  cout << "\n";
}

void initialize (int* arr1, int* arr2, int n){
  for(int i = 0; i < n; i++){
    arr1[i] = arr2[i];
  }
}

int main() {

  int array[] = {1,2,3,4};
  int size = sizeof(array)/sizeof(int);
  int permutation[size];
  initialize(permutation,array,size);
  int k = size;

  do{
    printArray(permutation,size);
    leftShift(permutation,k);
    if(permutation[k-1] != array[k-1]) {
      k = size;
      continue;}
    k = k - 1;
  }
  while (k > 1);

return 0;

}
