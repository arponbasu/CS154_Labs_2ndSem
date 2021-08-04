                #include <bits/stdc++.h>
                using namespace std;

                char* int2charstar (int v) {
                 char *s = new char[sizeof(int)];
                 sprintf(s,"%d",v);
                 return s;
                }


                int getInvCount(vector<int> arr, int n)
                {
                    int inv_count = 0;
                    for (int i = 0; i < n - 1; i++)
                        for (int j = i + 1; j < n; j++)
                            if (arr[i] > arr[j])
                                inv_count++;

                    return inv_count;
                }

                // Driver Code
                int main()
                {
                    srand(time(NULL));
                    vector<int>  arr;
                    for(int i = 0; i < 15; i++){
                      arr.push_back(i+1);
                    }

                    while(true){
                      random_shuffle(arr.begin(), arr.end());
                      if(getInvCount(arr, 15)%2 == 0) break;}

                      vector<const char*>  textLabels;
                      for(int i = 0; i < arr.size(); i++){
                        textLabels.push_back(int2charstar(arr[i]));
                      }
                      textLabels.push_back("xx");



                    return 0;
                }
