/*
#include <iostream>
using namespace std;
#define MAX_SIZE 100

class Queue {
  int Q[MAX_SIZE];
  int top;
  int card;


 public:
  Queue();
  void insert (int i);
	int fetch ();

};
Queue::Queue(){
  top = 0;
  card = 0;
  for (int i = 0; i < MAX_SIZE; i++){
    Q[i] = 0;
  }
}

void Queue::insert(int element){
if (card == MAX_SIZE) cout << "The queue is full. You can no longer insert elements." << "\n";
else{
  card++;
  Q[card-1] = element;
}


}

int Queue::fetch (){
  if (card == 0){
    cout << "The queue is empty. There is nothing left to fetch and hence we're returning zero." << "\n";
    return 0;
  }
  else{
    card--;

    Q[card] = 0;
    return Q[0];

  }



}




int main (int argc, char *argv[]) {





}
*/



#include <iostream>
using namespace std;
#define MAX_SIZE 100

class Queue {

  int Q[MAX_SIZE];
  //int firstIndex;
  //int lastIndex;
  int card;


 public:
  Queue();
	void insert (int i);
	int fetch ();
  int cardinality();

};

Queue::Queue(){
  card = 0;
  for (int i = 0; i < MAX_SIZE; i++){
    Q[i] = 0;
  }
}

void Queue::insert (int i){

  if (card == MAX_SIZE) cout << "The queue is full. You can no longer insert elements." << "\n";
  else{
    card++;
    Q[card-1] = i;
  }


}

int Queue::fetch (){

  if (card == 0){
    cout << "The queue is empty. There is nothing left to fetch and hence we're returning zero." << "\n";
    return 0;
  }

  else{
    int retval = Q[0];
    for(int i = 0; i <= card - 2; i++){
      Q[i] = Q[i+1];
    }
    card--;

    return retval;
  }





}
int Queue::cardinality(){
return card;

}

int main (int argc, char *argv[]) {


Queue q;


q.insert(10);
q.insert(12);
q.insert(13);
q.insert(25);
 cout << q.cardinality() << "\n";
 cout << q.fetch() << "\n";
 cout << q.cardinality() << "\n";
 cout << q.fetch() << "\n";


}
