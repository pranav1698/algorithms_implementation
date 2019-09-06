#include<bits/stdc++.h>
using namespace std;


int countWaysToMakeChange(int denominations[], int numDenominations, int value){
  int output[numDenominations][value+1];

  for(int i=0; i<numDenominations; i++){
    for(int j=0; j<=value+1; j++){
      output[i][j]=-1;
    }
  }

  if(value==0)
    return 1;
  if(numDenominations==0)
    return 0;
  if(value<0)
    return 0;
  if(output[numDenominations-1][value] > -1)
    return output[numDenominations-1][value];

  int first = countWaysToMakeChange(denominations, numDenominations, value-denominations[0]);
  int second = countWaysToMakeChange(denominations+1, numDenominations-1, value);
  output[numDenominations][value] = first + second;
  return first+second;

}

//
// int coin_change(int n, int* d, int numD){
//   if(numD == 0)
//     return 0;
//   if(n<0)
//     return 0;
//   if(n == 0)
//     return 1;
//
//   int first =coin_change(n-d[0], d, numD);
//   int second=coin_change(n, d+1, numD-1);
//
//   return first + second;
// }

int main() {
  int numD;
  cin >> numD;
  int arr[numD];
  for(int i=0; i<numD; i++)
    cin >> arr[i];
  int n;
  cin >> n;
  //cout << n << " " << numD << endl;
  cout << countWaysToMakeChange(arr, numD, n) << endl;
  //countWaysToMakeChange(arr, numD, n);
  // cout << coin_change(n, arr, numD);
}
