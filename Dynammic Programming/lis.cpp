#include<bits/stdc++.h>
using namespace std;

int lis(int* input, int n){
  int* output=new int[n];
  output[0]=1;
  for(int i=1; i<n; i++){
    int length=1;
    for(int j=0; j<i; j++){
      if(input[j] < input[i]){
        int possibleLength = output[j]+1;
        length=max(length, possibleLength);
      }
    }
    output[i] = length;
  }
  int best=0;
  for(int i=0; i<n; i++){
    best = max(best, output[i]);
  }
  delete [] output;
  return best;
}


int main(){
  int n;
  cin >> n;
  int* arr = new int[n];
  for(int i=0; i<n; i++)
    cin >> arr[i];

  int res=lis(arr, n);
  cout << res << endl;
  return 0;
}
