#include <bits/stdc++.h>
using namespace std;

int getMaxMoney(int arr[], int n){
  long* output=new long[n];

  output[n-1]=arr[n-1];
  if(n>1)
    output[n-2]=arr[n-2];
  if(n>2)
    output[n-3]=arr[n-3] + arr[n-1];



  for(int i=n-4; i>=0; i--){
    long max1 = LONG_MIN;
    for(int j=i+2; j<n; j++){
      long option1 = arr[i] + output[j];
      max1 = max(max1, option1);
    }
    output[i]=max(max1, output[i+1]);
  }

  long answer= output[0];
  delete[] output;

  return answer;
}
