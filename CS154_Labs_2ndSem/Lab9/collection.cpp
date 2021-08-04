//program by Prof. R.K.Joshi
//for CS152, IIT Bombay

#include <iostream>
using namespace std;

//observe definition of our own operator for use with objects,
// which means for use with values which are not primitive data types
// note the associativity from right to left

class Collection {
 int *array, card, maxsize; // storage and cardinality
 int getCard (Collection c){
   return c.card;
 }
 int getSize (Collection c){
   return c.maxsize;
 }

 void setSize (Collection c, int n){
   c.maxsize += n;
 }

 int* getArray (Collection c){
   return c.array;
 }
 public:
	 Collection (int sz) {
		array = new int [sz];
		card = 0;
		maxsize = sz;
	 }



	 Collection &operator << (int elem) {
		if (card < maxsize) array [card++] = elem;
		return *this;
	 }

   int &operator >> (int& elem) {
		if(card > 0) {
      elem = array[card-1];
      array[card-1] = 0;
      card--;
    }
    return elem;
	 }

   Collection &operator << (Collection c) {//bulk insertion operator
    maxsize += getSize(c);

    for(int i = 0; i < getSize(c); i++) {
      /*
      int* temp = getArray(c);
      int temporary = temp[i];
      *this<<temporary;
      */
      int* temp = getArray(c);
      int temporary = temp[i];
      array[card+i] = temporary;
    }
    card += getCard(c);
		return *this;
	 }




	 void print() {
		for (int i=0; i<card; i++)
			cout << array[i] << " ";
		cout << endl;
	}
};

int main () {

	Collection c1 (20);

		c1 << 1;
    c1 << 51;
    c1 << 51;
    c1 << 51;
		c1 << 2;
		c1 << 3;
		c1 << 4;
		c1 << 5;
		c1.print();

	Collection c2(3);

		c2 << 21 << 22 << 23;
		c2.print();

    int dummy = 0;
    for(int i = 0; i < 2; i++)  cout << (c1 >> dummy) << " ";
    cout << endl;
    c1.print();


   (c1 << c2).print();

}
