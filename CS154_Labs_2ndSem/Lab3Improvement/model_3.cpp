//code by Prof. R.K.Joshi, CSE, IIT Bombay
//part of CS 152/154 2021


#include <iostream>
using namespace std;

//third solution: structure the body elements... neater and safer,, encapsulating elements in one structure
//second solution: allows two instaces of the abstraction in main
// first solution does not permit that..


struct Stack {
int S[100]; // S[45] is 46th element!
int top=0; // current position in stack which is empty, position indicator
int card=0; // cardinality, no. of elements in the stack
};

 //void push (int element) ;// add an element on top of stack
 //int pop ();  // note the value at the top, remove the top and return the value
 //int cardinality (); // cardinality, how many elements in stack



void push(int element, struct Stack *s) {
  if (s->card == 100) cout << "The stack is full. You can no longer push elements." << "\n";
  else{
    s->card = s->card + 1;
    s->S[s->card-1] = element;
    s->top = element;

  }


}

int pop (struct Stack *s){

  if (s->card == 0){
    cout << "The stack is empty. There is nothing left to pop and hence we're returning zero." << "\n";
    return 0;
  }
  else{
    s->card = s->card - 1;
    int retval = s->S[s->card];
    s->top = s->S[s->card-1];
    s->S[s->card] = 0;
    return retval;

  }


}

int cardinality (struct Stack *s){
  return s->card;
}



//------------- section 3 ---- user of the abstraction ------

int main () { // is a user of the object, through its abstraction...

struct Stack s1, s2;
int e;

  push (10,&s1);
  push (12,&s1);
  push (14,&s1);
  e = pop(&s1);
  cout << e << endl;
  e = pop(&s1);
  cout << e << endl;

  push (10,&s1);
  push (12,&s1);
  push (14,&s1);
  e = pop(&s1);
  cout << e << endl;
  e = pop(&s1);
  cout << e << endl;


}
