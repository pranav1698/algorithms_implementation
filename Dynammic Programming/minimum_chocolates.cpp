#include<bits/stdc++.h>
using namespace std;

int getMin(int *input, int n){
  int* output= new int[n];
  output[0]=1;
  for(int i=1; i<n; i++){
    output[i]=1;
    if(input[i]>input[i-1]){
      output[i] = output[i-1]+1;
    }
    if(input[i]<input[i-1]){
      for(int j=i; j>0; j--){
        if(output[j] == output[j-1]){
          output[j-1] = output[j-1] + 1;
        } else {
            break;
        }
      }
    }
  }
  long sum=0;
  for(int i=0; i<n; i++){
    sum = sum + output[i];
  }
  delete[] output;
  return sum;
}

int main(){
  int n;
  cin >> n;
  int input[n];
  for(int i=0; i<n; i++)
    cin >> input[i];

  cout << getMin(input, n) << endl;
}
