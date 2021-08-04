#include<iostream>
using namespace std;

class A
{
public:
    void show() { cout<< "In A \n"; }
    virtual void vshow() { cout<< "Virtual In A \n"; }
};

class B: public A
{
public:
    void show() { cout<< "In B \n"; }
    virtual void vshow() { cout<< "Virtual In B \n"; }
};

int main()
{
    A *bp = new B();
    bp->show();
    bp->vshow();

    return 0;
}
