#include <bits/stdc++.h>
using namespace std;

string processArgument(int argc, char* argv[]){
  if (argc != 2){
    cout << "\nImproper input. Usage [./executable][FILE NAME AS STRING]\n";
    exit(0);
  }
  else return argv[1];
}

int main(int argc, char* argv[])
{
// Create a text string, which is used to output the text file
  string fileLine;

  int freqChar[128];
  for (int i = 0; i < 128; i++){
    freqChar[i] = 0;
  }

  // Read from the text file
  ifstream InputFile(processArgument(argc,argv));

  // Use a while loop together with the getline() function to read the file line by line
  while (getline (InputFile, fileLine)){
    // Output the text from the file
    for (long unsigned int i = 0; i < fileLine.length(); i ++){
      freqChar[(int)(fileLine[i])]++;
    }
  }

  for (int i = 32; i <= 126; i++){
    char c = i;
    cout << c << " : " << freqChar[i] << "\n";
  }

  InputFile.close();

  return 0;
}
