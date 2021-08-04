#include <iostream>

using namespace std;

int main () {

int x = 10;

 //++x = x++;  // this is acceptable

 //x++ = x++;  // but this is not... why?!
 int temp = x++;// These two lines are added by me to rectify the error in line 13 and do what
 x = temp;//was probably intended to be done


 cout << x << endl;  // explain the output

}
