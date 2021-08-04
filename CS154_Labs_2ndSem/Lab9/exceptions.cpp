#include <iostream>
using namespace std;

class OutofBound {
 int e;
 public:
	OutofBound (int e) {
		this->e = e;
	}

	void msg() {
		switch(e) {
			case 0: cout << "array underflow access\n"; break;
			case 1: cout << "array overflow access\n"; break;
		}
	}

};

class Collection {

 int array[10];

  public:
    //OutofBound &operator throw (int i){
      //throw OutofBound(i);
    //}
    Collection(){//Added by me
      for (int i = 0; i < 10; i++){
        array[i] = -100;
      }
    }
    Collection &operator << (int elem) {//Added by me, taken from sir's code in collection.cpp
    for(int i = 0; i < 10; i++){
      if(array[i] == -100) {
        array[i] = elem;
        break;
      }
    }
    if(array[9] != -100) throw OutofBound(1);
     return *this;
}



	int &operator [] (int i) {

		if (i>=10) throw OutofBound(1);
		if (i<0) throw OutofBound(0);
		return (array[i]);
	}

	void print() {
		for (int i=0; i<10; i++)
			cout << array[i] << " ";
		cout << endl;
	}
};

int main () {

 Collection c;

 for (int i = -5; i < 15; i++)  {
	try {c << i;}
	catch (OutofBound e) {e.msg();}
 }
 c.print();


}
