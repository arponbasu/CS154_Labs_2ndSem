/*
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

const static int capacity = 4;

class Lift
{
  int currentFloor;
  const static int MAX_FLOOR = 6;
  bool isRunning;
  bool direction;
  int userArray[capacity];
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
  }

void update (int argc, char* argv[])
{
  for (int i = 1; i <= min(argc - 1, capacity); i++) {
    userArray[i-1] = atoi(argv[i]);

  }



}


void start (){
  while(true){
    isRunning = true;
    sleep(1);
    if (currentFloor != MAX_FLOOR) currentFloor++;
    else if (currentFloor == MAX_FLOOR) break;

  /*  if(find(begin(userArray), end(userArray), currentFloor)){
      isRunning = false;
      //sleep(2);
      cout << "Passenger(s) offloaded at " << currentFloor << "\n";
      for(int i = 0; i < capacity; i++){
        if(userArray[i] == currentFloor) userArray[i] = -1;
      }

    }*/
/*
    for(int i = 0; i < capacity; i++){
      if(userArray[i] == currentFloor) {
        isRunning = false;
        sleep(2);
        cout << "Passenger(s) offloaded at " << currentFloor << "\n";
        userArray[i] = -1;


      }

    }

}







}









};*/
/*
class Floor
{
  int n;
public:







};*/





/*

int main(int argc, char* argv[])
{
//  Floor f[7];
  Lift l;
  l.update(argc,argv);
  l.start();




  return 0;
}
*/
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

const static int capacity = 4;

int randbw (int a, int b)
{
  return (a+rand()%(b-a+1));
}

class Lift
{
  int currentFloor;
  const static int MAX_FLOOR = 6;
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
          cout << "Passenger(s) get in at " << "floor " << currentFloor << "\n";
          userArray[i] = randbw(-1,MAX_FLOOR);
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
          cout << "Passenger(s) get in at " << "floor " << currentFloor << "\n";
          userArray[i] = randbw(-1,MAX_FLOOR);
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
//  Floor f[7];
  srand(time(NULL));
  Lift l;
  l.update(argc,argv);
  l.start();




  return 0;
}
