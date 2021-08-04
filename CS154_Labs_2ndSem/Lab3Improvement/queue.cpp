/*
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
*/

#include <iostream>
using namespace std;
#define MAX_SIZE 100

class Queue
{
    int first_index, last_index;
    int Q[MAX_SIZE];
    int card;

  public:

    Queue();
    void insert (int i);
    int fetch();
    int cardinality();

};

Queue::Queue()
{
   first_index = last_index = -1;
   card = 0;
}


void Queue::insert(int value)
{
    if ((first_index == 0 && last_index == MAX_SIZE - 1) ||
            (last_index == (first_index - 1)%(MAX_SIZE - 1))){
        cout << "The queue is full. You can no longer insert elements." << "\n";
        return;
    }


    else if (first_index == -1) /* Insert First Element */
    {
        first_index = last_index = 0;
        Q[last_index] = value;
    }

    else if (last_index == MAX_SIZE - 1 && first_index != 0){
        last_index = 0;
        Q[last_index] = value;
    }

    else{
        last_index++;
        Q[last_index] = value;
    }
    card++;
}

int Queue::fetch()
{
    if (first_index == -1)
    {
      cout << "The queue is empty. There is nothing left to fetch and hence we're returning zero." << "\n";
      return 0;
    }

    int retval = Q[first_index];
    Q[first_index] = -1;
    if (first_index == last_index){
        first_index = -1;
        last_index = -1;
    }
    else if (first_index == MAX_SIZE - 1) first_index = 0;
    else first_index++;

    card--;
    return retval;
}

int Queue::cardinality(){
  return card;
}


int main()
{
    Queue q;

    q.insert(12);
    q.insert(14);
    q.insert(13);
    q.insert(25);

    cout << q.fetch() << "\n";
    cout << q.fetch() << "\n";
    cout << "Current size of queue is " << q.cardinality() << "\n";

    q.insert(15);
    q.insert(23);
    q.insert(5);

    cout << q.fetch() << "\n";
    cout << "Current size of queue is " <<  q.cardinality() << "\n";



    return 0;
}
