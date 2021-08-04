#include <iostream>
using namespace std;
#define MAX_SIZE 100

class Stack{

  int S[MAX_SIZE];
  int top;
  int card;

public:
  Stack();
  void push (int element);
  int pop();
  int cardinality();

};



Stack::Stack(){
  top = 0;
  card = 0;
  for (int i = 0; i < MAX_SIZE; i++){
    S[i] = 0;
  }
}

void Stack::push(int element){
if (card == MAX_SIZE) cout << "The stack is full. You can no longer push elements." << "\n";
else{
  card++;
  S[card-1] = element;
  top = element;

}


}

int Stack::pop(){

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

int Stack::cardinality(){
  return card;
}
























int main(int argc, char *argv[]) {

  Stack s;
  /*
  s.push(10);
  s.push(12);
  s.push(13);
  s.push(25);
   cout << s.cardinality() << "\n";
   cout << s.pop() << "\n";
   cout << s.cardinality() << "\n";
   cout << s.pop() << "\n";*/

   for (int i = 0; i < 100; i++)
   {
     s.push(23);
   }

   s.push(45);

   cout << s.cardinality() << "\n";
   cout << s.pop() << "\n";
   cout << s.cardinality() << "\n";

   s.push(23);
   for (int i = 0; i < 100; i++)
   {
     s.pop();
   }

   s.pop();
   cout << s.cardinality() << "\n";


  return 0;
}
