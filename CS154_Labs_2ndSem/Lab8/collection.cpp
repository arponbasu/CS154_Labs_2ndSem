#include <iostream>
using namespace std;
#include <cassert>
// A program which is not correct
class Collection {
int* S;
int capacity, cardinality;

  public:
	Collection(int size) {
    assert(size > 0);
    S = new int [size];
		cardinality = 0;
    capacity = size;
  //... add assertion(s)...
  assert(cardinality >= 0);
  assert(cardinality <= capacity);
  assert(capacity == size);

	}

	void push_back(int element) {
  //... add assertion(s)...
  assert(cardinality < capacity);


  //... add logic
  cardinality++;
  S[cardinality-1] = element;

  //... add assertion(s)...
  assert(cardinality <= capacity);

	}

	int pop_back() {
  //... add assertion(s)...
  assert(cardinality > 0);


  //... add logic
  cardinality--;
  return S[cardinality];

  //... add assertion(s)...
  assert(cardinality >= 0);

	}
};

void ConstructorAssertTesting (){
  Collection err(-1);
}

void push_backAssertTesting (Collection c){
  while(true){
    c.push_back(1);
  }
}

void pop_backAssertTesting (Collection c){
  c.push_back(1);
  while(true){
    c.pop_back();
  }
}



int main (int argc, char** argv) {

  int x = atoi(argv[1]);
  Collection c(100);
  switch(x){
    case 0: ConstructorAssertTesting(); break;
    case 1: push_backAssertTesting(c); break;
    case 2: pop_backAssertTesting(c); break;
  }



   // add code that tests the class above and fails it, which gets caught by assertions

}
