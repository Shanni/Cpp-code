#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
using namespace std;

char ans[10000];


int main() {
  // Precompute all answers.
  ofstream myfile;
  myfile.open ("example.txt");
  

  // Process queries.
  int N;
  scanf(" %d", &N);
  for (int prob = 1; prob <= N; prob++) {
    int n, sum=0, m=0; 
    scanf(" %d %s", &n, ans);
    int num;
    for(int i=0;i<n+1;i++){
      num=ans[i]-'0';
      if(num>0 && sum<i){
        m+=i-sum;
        sum+=m;
      }
       sum+=num;

    }
    myfile<<"Case #"<< prob<< ": "<<m<<"\n";
   
  }
   myfile.close();

  return 0;
}