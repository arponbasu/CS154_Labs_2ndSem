#include <iostream>

using namespace std;

void f(int x, int y) {

 cout << x << " " << y << endl;
}

void g(int& x, int& y) {

 cout << x << " " << y << endl;
}

int main () {
int i=10;

 f(i, i++);

//i = 100;

 f(++i, i++);

 g(i, i++);//New lines added by me
 g(i++, i);
 g(++i, i++);//New lines added by me
 g(i++, ++i);
cout << i << endl;


}
