//code by Prof. R.K.Joshi, CSE, IIT Bombay
//part of CS 152/154 2021

#include <iostream>
using namespace std;


//--------------- section 1 ---- interface of the abstraction
//declarations give us the abstraction (interface)

void push (int elem); // add an element on top of stack
int pop ();  // note the value at the top, remove the top and return the value
int cardinality(); // cardinality, how many elements in stack

//-----------section 2 --- implementation of the abstraction--
// definitions give us the implementation of the abstraction (bodies)


int S[100]; // S[45] is 46th element!
int top=0; // current position in stack which is empty, position indicator
int card=0; // cardinality, no. of elements in the stack

void push(int element) {
  if (card == 100) cout << "The stack is full. You can no longer push elements." << "\n";
  else{
    card++;
    S[card-1] = element;
    top = element;

  }

}
int pop(){
  if (card == 0){
    cout << "The stack is empty. There is nothing left to pop and hence we're returning zero." << "\n";
    return 0;
  }
  else{
    card--;
    int retval = S[card];
    top = S[card-1];
    S[card] = 0;
    return retval;

  }


}

int cardinality(){
  return card;
}


//------------- section 3 ---- user of the abstraction ------

int main () { // is a user of the object, through its abstraction...
int e;
  push (10);
  push(12);
  push (14);
  e=pop();
  cout << e << endl;
  e=pop();
  cout << e << endl;
}
