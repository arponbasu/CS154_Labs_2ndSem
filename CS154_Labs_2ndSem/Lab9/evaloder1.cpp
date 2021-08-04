#include <iostream>
using namespace std;


int p=1;

int f(int i) { p=p+i; return p; }

int main () {


 cout << f(p) << " " << f(p) << " " << f(p) << " " << f(p++) << endl;//Here ++p in the original program
//was changed to p++ here to yield 17 as output instead of 18.

}
