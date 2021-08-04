#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

const static long unsigned int capacity = 4;
const static int MAX_FLOOR = 6;
const static int maxLobby = 10;
  vector<vector<int> > floorStatus;

int randbw (int a, int b)
{
  return (a+rand()%(b-a+1));
}


/*class Passenger{
public:
Passenger(){}
queue<int> * getPassenger(int flr)
{

  return passengers[flr];
}

void setPassengers(int flr,queue<int> *pd)
{
  passengers[flr]=pd;
}

private:
static int passengers[][];
};*/



class Lift
{
  int currentFloor;

  bool isRunning;
  bool direction;
  int userArray[capacity];
  int altCurrentCapacity;
  int identity;
public:
  int getIdentity ()
  {
    return identity;
  }
  Lift()
  {
    currentFloor = 0;
    isRunning = false;
    direction = true; //true means upwards
    for (long unsigned int i = 0; i < capacity; i++)
    {
      userArray[i] = -1;
    }
    altCurrentCapacity = 0;


  }

  Lift(int n)
  {
    identity = n;
    currentFloor = 0;
    isRunning = false;
    direction = true; //true means upwards
    for (long unsigned int i = 0; i < capacity; i++)
    {
      userArray[i] = -1;
    }
    altCurrentCapacity = 0;
    cout<<"Lift Object Created. Id:"<<n<<"\n";
  }

void update (vector<vector<int> > v)
{
  int upper = min(v[0].size(), capacity);
  for (int i = 0; i < upper; i++) {
    userArray[i] = v[0][i];
//  v[0][i] = -1;
    v[0].pop_back();

  }



}

int capacityChecker (int userArray[])
{
  int retval = 0;
  for(long unsigned int i = 0; i < capacity; i++)
  {
    if(userArray[i] == -1) retval++;
  }

  return (capacity-retval);

}

vector<vector<int> > doWork (vector<vector<int> > v){

  cout << "This is Lift " << identity << " :\n";
  if (v.size() == 0) exit(0);

  altCurrentCapacity = capacityChecker(userArray);
  while(altCurrentCapacity > 0){

    if(currentFloor < *max_element(userArray, userArray + capacity)){

      for(int j = 0; j < *max_element(userArray, userArray + capacity); j++){

        for(long unsigned int i = 0; i < capacity; i++){
          if(userArray[i] == -1) {
            int l = v[currentFloor].size();
            userArray[i] = v[currentFloor][l-1];
            v[currentFloor].pop_back();
            if(userArray[i] != -1){
            cout << "Passenger gets in at " << "floor " << currentFloor;
            cout << " and plans to depart on floor " << userArray[i] ;
            cout << "\n";}
            altCurrentCapacity = capacityChecker(userArray);
          }
        }

          isRunning = true;

          if (currentFloor != MAX_FLOOR) currentFloor++;
          else if (currentFloor == MAX_FLOOR) break;



          for(long unsigned int i = 0; i < capacity; i++){
            if(userArray[i] == currentFloor) {
              isRunning = false;

              cout << "Passenger gets out at " << "floor " << currentFloor << "\n";
              userArray[i] = -1;
              altCurrentCapacity = capacityChecker(userArray);
            }
          }


      }// for j ends








    }//if ends

    else if (currentFloor > *max_element(userArray, userArray + capacity))
    {
      for(int j = currentFloor; j >= max(0,*min_element(userArray, userArray + capacity)); j--){

        for(long unsigned int i = 0; i < capacity; i++){
          if(userArray[i] == -1) {
            int l = v[currentFloor].size();
            userArray[i] = v[currentFloor][l-1];
            v[currentFloor].pop_back();
            if(userArray[i] != -1){
            cout << "Passenger gets in at " << "floor " << currentFloor;
            cout << " and plans to depart on floor " << userArray[i] ;
            cout << "\n";}
            altCurrentCapacity = capacityChecker(userArray);
          }
        }

          isRunning = true;

          if (currentFloor != 0) currentFloor--;
          else if (currentFloor == 0) break;



          for(long unsigned int i = 0; i < capacity; i++){
            if(userArray[i] == currentFloor) {
              isRunning = false;

              cout << "Passenger gets out at " << "floor " << currentFloor << "\n";
              userArray[i] = -1;
              altCurrentCapacity = capacityChecker(userArray);
            }
          }


      }




    }



  }//while ends

  return v;

}




};



void vecInitialize () //vector<vector<int> > floorStatus
{
  //int l = floorStatus.size();
  cout<<"Inside vecInitialize ";
  for (int i = 0; i <= MAX_FLOOR; i++){
    vector<int> tempVec;
      for (int j = 0; j < maxLobby; j++){

      tempVec.push_back(randbw(-1,MAX_FLOOR));
      //  floorStatus[i].push_back(randbw(-1,MAX_FLOOR));
      }
      floorStatus.push_back(tempVec);
  }
/*cout<<"Testing vector\n ";//<<floorStatus[0][0];
for (unsigned int k = 0; k <floorStatus[0].size() ; k++)
     cout<<floorStatus[0][k]<<"\n";*/

}



int main (int argc, char* argv[])
{
cout<<"Inside main ";

  srand(time(NULL));



  Lift l1(1), l2(2);



  vecInitialize();//floorStatus

  l1.update(floorStatus);
//  vecInitialize(floorStatus);



  while(true){

  //l1.doWork(floorStatus);
  floorStatus = l2.doWork(l1.doWork(floorStatus));

}



  return 0;
}
