#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int find(string str, string sub) {

// add precondition assertions
assert(str.size() >= sub.size());//assert1
assert(sub.size() > 0);//assert2

// add logic
int strSize = str.size();
int subSize = sub.size();
int retval;


    for (int i = 0; i <= strSize - subSize; i++) {
        int j = 0;
        for (j = 0; j < subSize; j++){
            assert((i+j) > -1);
            assert((i+j) < strSize);
            if (str[i + j] != sub[j]) break;
          }
        if (j == subSize) retval = i;
    }

    retval = -1;
    return retval;

// add postcondition assertions
assert(retval >= -1);
assert(retval <= strSize - subSize);


}

void stringLengthCompare(){
  find("a","bcde");
}

void nullStringChecking(){
  find("a","");
}


int main (int argc, char** argv) {

int x = atoi(argv[1]);
switch(x){
  case 1: stringLengthCompare(); break;
  case 2: nullStringChecking(); break;
}



}
