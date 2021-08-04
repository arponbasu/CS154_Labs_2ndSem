#include<iostream>
using namespace std;
class Super{
public:
  virtual void g() = 0;

};
class A: public Super {
  public:
	virtual void f() = 0;
};
class B {
 public:
	virtual void g() {cout << "C::g\n";}
};
class C : public B, public A {
 public:
	virtual void f(){cout << "C::f\n";}
         virtual void g() {cout << "C::g\n";}
};
int main (int argc, char *argv[]) {
   A* ap;
   ap = new C();
   ap->g();
}
