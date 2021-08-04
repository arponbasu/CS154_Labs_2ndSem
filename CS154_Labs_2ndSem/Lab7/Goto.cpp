#include <iostream>
using namespace std;

int main() {

  int array[] = {1,2,3,4};
  int size = sizeof(array)/sizeof(int);
  int permutation[size];
  for(int i = 0; i < size; i++){
      permutation[i] = array[i];
    }
  int k;
  Setk:
    k = size;
  Generatepermutation:
    for(int i = 0; i < size; i++){
      cout << permutation[i];
    }
    cout << "\n";
    int first = permutation[0];
    for(int i = 0; i < k - 1; i++){
      permutation[i] = permutation[i+1];
    }
    permutation[k-1] = first;
    if(permutation[k-1] != array[k-1]) goto Setk;
  Decreasek:
    k = k - 1;
    if (k > 1) goto Generatepermutation;

return 0;

}
