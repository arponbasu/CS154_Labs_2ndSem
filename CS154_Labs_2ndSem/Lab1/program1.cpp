#include <bits/stdc++.h>
using namespace std;



class Dice
{

  static const unsigned int MAX_NUM = 6;
  int freqArr[MAX_NUM];

public:
  Dice(){

    for (unsigned int i = 0; i < getMaxNum(); i++){
      freqArr[i] = 0;
    }
  }

unsigned int getMaxNum() const {return MAX_NUM;}

int getNumberCount (int num)
{
  return freqArr[num-1];
}
void dieToss (int n)
{
  freqArr[n-1] = freqArr[n-1] + 1;
}


};


int processArgument(int argc, char* argv[])
{

  if (argc != 2)
  {
    cout << "\nImproper input. Usage [./executable][NATURAL NUMBER]\n";
    exit(0);
  }
  else{
        return atoi(argv[1]);
  }


}



int randbw (int lower, int upper){
  return (lower + rand()%(upper-lower+1));
}




int main(int argc, char* argv[])
{
  srand(time(NULL));
  int N = processArgument(argc, argv);



Dice d;
for (int i = 0; i < N; i++)
{
  d.dieToss(randbw(1,d.getMaxNum()));
}

for (unsigned int i = 1; i <= d.getMaxNum(); i++)
{
  double num = N;
  cout << "The probability of " << i << " is: " << d.getNumberCount(i)/num << "\n";
}


  return 0;
}
