// Very Important
#include<bits/stdc++.h>
using namespace std;

int countWaysToMakeChange(int denominations[], int numDenominations, int value){
  int output[value+1][numDenominations+1];

  output[0][0]=0;
  for(int i=1; i<=value; i++)
      output[i][0]=0;
  for(int j=1; j<=numDenominations; j++)
    output[0][j] = 1;
  int first, second;
  for(int i=1; i<=value; i++){
    for(int j=1; j<=numDenominations; j++){
      first= output[i][j-1];
      if((i - denominations[j-1]) < 0){
        second = 0;
      } else {
        second = output[(i-denominations[j-1])][j];
      }
      //cout << i << " " << j << endl;
      //cout << first << " " << second << endl;
      output[i][j]=first + second;
      //cout << output[i][j] << endl;
    }
  }

  int ans=output[value][numDenominations];
  return ans;
}

//
// int countWaysToMakeChange(int denominations[], int numDenominations, int value){
//   int output[numDenominations+1][value+1];
//
//   for(int i=0; i<=numDenominations; i++){
//     for(int j=0; j<=value; j++){
//       output[i][j]=-1;
//     }
//   }
//
//   if(value==0)
//   return 1;
//   if(numDenominations==0)
//   return 0;
//   if(value<0)
//   return 0;
//   if(output[numDenominations-1][value] > -1)
//   return output[numDenominations-1][value];
//
//   int first = countWaysToMakeChange(denominations, numDenominations, value-denominations[0]);
//   int second = countWaysToMakeChange(denominations+1, numDenominations-1, value);
//   output[numDenominations][value] = first + second;
//   return first+second;
//
// }


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
