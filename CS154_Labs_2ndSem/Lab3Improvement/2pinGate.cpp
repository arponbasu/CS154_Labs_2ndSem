#include <iostream>

using namespace std;

class Gate {
  int mode;//Tells us whether Gate has to do AND(0), OR(1) or XOR(2)
  bool output;//Stores output
 public:
  Gate ();
  Gate (int n);
	bool fire (int i, int j);
  bool negate (int i);
	bool getoutput ();

};
Gate::Gate(){
  mode = 0;//The gate is by default "AND" unless specified otherwise (through the other constructor)
  output = true;//The gate is in the true state at the beginning
}

Gate::Gate(int n){
  mode = n;
  output = true;//The gate is in the true state at the beginning
}

bool Gate::fire(int i, int j){
  int input1 = i%2;
  int input2 = j%2;
  bool retval;

  if (mode == 0) retval = input1&input2;
  else if (mode == 1) retval = input1|input2;
  else if (mode == 2) retval = input1^input2;
  else if (mode == 3) retval = ~(input1&input2);

  output = retval;
  return retval;

}

bool Gate::negate (int i){//This method takes ONLY one input and returns not of that operator. This works in any mode.
  int input = i%2;
  bool retval = true;
  if(input == 1) retval = false;
  output = retval;
  return retval;


}

bool Gate::getoutput(){
  if (output == true) cout << "The output is 'TRUE'" << "\n";
  else cout << "The output is 'FALSE'" << "\n";
  return output;
}

int main (int argc, char *argv[]) {

Gate g, g0(0), g1(1), g2(2), g3(3);
g.negate(1);//Answer will be FALSE because the input is true and the gate is "not"
g.getoutput();
g0.fire(0,1);//Answer will be FALSE because one of the elements is false and the gate is "and"
g0.getoutput();
g1.fire(0,1);//Answer will be TRUE because one of the elements is true and the gate is "or"
g1.getoutput();
g2.fire(0,1);//Answer will be TRUE because the number of true inputs is odd and the gate is "xor"
g2.getoutput();
g3.fire(1,0);//Answer will be TRUE because atleast one input is false and the gate is "nand"
g3.getoutput();

}
