// Program by Prof. R. K. Joshi
// for CS 152
// unary operator overloading: the ++ operator

#include <iostream>
using namespace std;

class A {

    int v;
	public:
		A(int x) { v = x;}
		void operator ++() {
			cout << "suffix operator called \n";
      v++;
		}
		void operator ++(int) {
			cout << "postfix operator called \n";
      ++v;
		}
    void print(){cout << v << endl;}//Added by me
};

int main () {

 A a(10);
	++a; a.print();
	a++; a.print();
//New lines added by me
A *ap;
ap = &a;
++(*ap); ap->print();
(*ap)++; ap->print();
}
