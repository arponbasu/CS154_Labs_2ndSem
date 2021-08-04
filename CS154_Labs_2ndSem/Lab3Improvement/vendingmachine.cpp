#include <iostream>
using namespace std;
#define drinkNum 5

class VendingMachine {

  int drinkArray[drinkNum];//It's assumed that drinks have IDs from 0 to (drinkNum-1)
                          //and their prices are equal to 5*(drinkid+1)
  int moneyReceived;

 public:
void	insertcoin (int val);
bool selectdrink (int drinkid); // returns true if successful

};

void VendingMachine::insertcoin (int val){
  if (val > 0) moneyReceived = val;
  else cout << "Please pay some valid amount of money." << "\n";
}

bool VendingMachine::selectdrink (int drinkid){

bool retval;
cout << "Purchase receipt: \n";
if (drinkid >= 0 && drinkid < drinkNum){
if (moneyReceived >= 5*(drinkid+1)){
cout << "Drink number : " << drinkid << " dispensed."<< "\n";
cout << "Change worth " << (moneyReceived - 5*(drinkid+1)) << " rupees was paid back."<< "\n";
moneyReceived = 0;
retval = true;
}
else {
  cout << "Please pay the requisite amount of money (" << 5*(drinkid+1) << " rupees)." << "\n";
  retval = false;
}

}
else{
  cout << "The drink that you asked for doesn't exist." << "\n";
  retval = false;
}

if (retval == true) cout << "Purchase successful and necessary amount of change was paid back." << "\n";
if (retval == false) cout << "Purchase unsuccessful." << "\n";
return retval;
}

int main (int argc, char *argv[]) {
  VendingMachine v;
  v.insertcoin(atoi(argv[1]));
  v.selectdrink(atoi(argv[2]));





}
