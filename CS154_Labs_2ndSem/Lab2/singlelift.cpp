#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

const static int capacity = 4;
const static int MAX_FLOOR = 6;

int randbw (int a, int b)
{
  return (a+rand()%(b-a+1));
}

class Lift
{
  int currentFloor;

  bool isRunning;
  bool direction;
  int userArray[capacity];
  int currentCapacity;
public:

  Lift()
  {
    currentFloor = 0;
    isRunning = false;
    direction = true; //true means upwards
    for (int i = 0; i < capacity; i++)
    {
      userArray[i] = -1;
    }
    currentCapacity = 0;
  }

void update (int argc, char* argv[])
{
  int upper = min(argc - 1, capacity);
  for (int i = 1; i <= upper; i++) {
    userArray[i-1] = atoi(argv[i]);

  }

  //currentCapacity += upper;

}

int capacityChecker (int userArray[])
{
  int retval = 0;
  for(int i = 0; i < capacity; i++)
  {
    if(userArray[i] == -1) retval++;
  }

  return (capacity-retval);

}

void start ()
{

currentCapacity = capacityChecker(userArray);
while(currentCapacity > 0){

  if(currentFloor < *max_element(userArray, userArray + capacity)){

    for(int j = 0; j < *max_element(userArray, userArray + capacity); j++){

      for(int i = 0; i < capacity; i++){
        if(userArray[i] == -1) {
          cout << "Passenger gets in at " << "floor " << currentFloor;
          userArray[i] = randbw(0,MAX_FLOOR);
          if(userArray[i] != -1) cout << " and plans to depart on floor " << userArray[i] ;
          cout << "\n";
          currentCapacity = capacityChecker(userArray);
        }
      }

        isRunning = true;
        //sleep(1);
        if (currentFloor != MAX_FLOOR) currentFloor++;
        else if (currentFloor == MAX_FLOOR) break;



        for(int i = 0; i < capacity; i++){
          if(userArray[i] == currentFloor) {
            isRunning = false;
          //  sleep(2);
            cout << "Passenger gets out at " << "floor " << currentFloor << "\n";
            userArray[i] = -1;
            currentCapacity = capacityChecker(userArray);
          }
        }


    }// for j ends








  }//if ends

  else if (currentFloor > *max_element(userArray, userArray + capacity))
  {
    for(int j = currentFloor; j >= min(0,*min_element(userArray, userArray + capacity)); j--){

      for(int i = 0; i < capacity; i++){
        if(userArray[i] == -1) {
          cout << "Passenger gets in at " << "floor " << currentFloor;
          userArray[i] = randbw(0,MAX_FLOOR);
          if(userArray[i] != -1) cout << " and plans to depart on floor " << userArray[i];
          cout << "\n";
          currentCapacity = capacityChecker(userArray);
        }
      }

        isRunning = true;
        //sleep(1);
        if (currentFloor != 0) currentFloor--;
        else if (currentFloor == 0) break;



        for(int i = 0; i < capacity; i++){
          if(userArray[i] == currentFloor) {
            isRunning = false;
          //  sleep(2);
            cout << "Passenger gets out at " << "floor " << currentFloor << "\n";
            userArray[i] = -1;
            currentCapacity = capacityChecker(userArray);
          }
        }


    }




  }



}//while ends

return;

}//start() ends

};




int main (int argc, char* argv[])
{

  srand(time(NULL));
  Lift l;
  l.update(argc,argv);
  l.start();




  return 0;
}
