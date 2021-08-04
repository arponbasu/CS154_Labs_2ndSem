#include <bits/stdc++.h>



int processArgument(int argc, char* argv[]){
  if (argc != 2)
  {
    printf("%s", "\nImproper input. Usage [./executable][NATURAL NUMBER]\n");
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
  static const unsigned int MAX_NUM = 6;
  int freqArr[MAX_NUM];


for (unsigned int i = 0; i < MAX_NUM; i++){
    freqArr[i] = 0;
}

for (int i = 0; i < N; i++){
  freqArr[randbw(1,MAX_NUM)-1]++;
}

for (unsigned int i = 1; i <= MAX_NUM; i++){
  double num = N;
  printf("The probability of %u is: %f\n",i,freqArr[i-1]/num);
}


  return 0;
}
