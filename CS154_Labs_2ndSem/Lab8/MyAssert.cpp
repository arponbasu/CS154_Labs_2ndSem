#include <iostream>
#include <string>
#include "MyAssert.h"
#define INT_MAX 2147483647
//#define NDEBUG  // uncomment to turn off Assertions


using namespace std;




int str2int (string s) {
unsigned long long retval = 0;
 // define your other needed variables
 int iterator = 0;

    // add assertions here first
		codeassert(s.size() > 0);
		codeassert(s.size() < 20);// ULLONG_MAX is of 20 digits

    // the logic, which does not check for any condition, can be buggy
    while(s[iterator] >= '0' && s[iterator] <= '9'){

				retval = retval*10 + (s[iterator] - '0');
        iterator++;
				if(iterator >= s.size()) break;
    }



   // add assertios for postcondition

	 codeassert(iterator == s.size());
	 codeassert(retval <= INT_MAX);

	return (int)retval;
};

void nullStringChecking(){
	str2int("");
}

void properStringChecking1(){
	str2int("12a+3@4");
}

void properStringChecking2(){
	str2int("+12345");
}

void inputOverflow(){
	str2int("12345678912341111111111111111111111111111111111111111111111111111111111111111111111111");
}

void outputOverflow(){
	str2int("1234567891234");
}

int main(int argc, char** argv) {

// develop main which catches errors through assertions
// report bugs
int x = atoi(argv[1]);
switch(x){
  case 1: nullStringChecking(); break;
	case 2: properStringChecking1(); break;
	case 3: properStringChecking2(); break;
	case 4: inputOverflow(); break;
	case 5: outputOverflow(); break;
}


}
