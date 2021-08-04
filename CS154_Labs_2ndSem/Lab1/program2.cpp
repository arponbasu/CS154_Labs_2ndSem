#include <bits/stdc++.h>
using namespace std;

class FreqAnalysis{
int freqChar[128];
public:
  FreqAnalysis(){
    for (int i = 0; i < 128; i++){
      freqChar[i] = 0;
    }
  }

void updateArray (char c){
  int n = c;
  freqChar[n]++;
}

int getFrequency (char c){
  int n = c;
  return freqChar[n];
}

void printFrequency (){
  for (int i = 32; i <= 126; i++){
    char c = i;
    cout << c << " : " << getFrequency(c) << "\n";
  }
}
};


string processArgument(int argc, char* argv[]){
  if (argc != 2)
  {
    cout << "\nImproper input. Usage [./executable][FILE NAME AS STRING]\n";
    exit(0);
  }
  else{
        return argv[1];
  }
}

int main(int argc, char* argv[])
{
// Create a text string, which is used to output the text file
  string fileLine;
  FreqAnalysis freq;

  // Read from the text file
  ifstream InputFile(processArgument(argc,argv));

  // Use a while loop together with the getline() function to read the file line by line
  while (getline (InputFile, fileLine)){
    // Output the text from the file
    for (long unsigned int i = 0; i < fileLine.length(); i ++){
      freq.updateArray(fileLine[i]);
    }
  }

  freq.printFrequency();

  InputFile.close();

  return 0;
}
