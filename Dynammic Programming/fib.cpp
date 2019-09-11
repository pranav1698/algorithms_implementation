#include <bits/stdc++.h>
using namespace std;

// int fib2(int n, int* arr){
//   if(n==0 || n==1){
//     return 1;
//   }
//   if(arr[n] > 0){
//     return arr[n];
//   }
//   int output = fib2(n-1, arr) + fib2(n-2, arr);
//   arr[n] = output;
//   return output;
// }

int fibi(int n){
  int* arr = new int[n+1];
  arr[0]=1;
  arr[1]=1;
  for(int i=2; i<=n; i++){
    arr[i]=arr[i-1] + arr[i-2];
  }
  int output = arr[n];
  delete [] arr;
  return output;
}

int main(){
  int n;
  cin >> n;
  int arr[n+1];
  for(int i=0;i<=n;i++){
    arr[i]=0;
  }
  cout << fibi(n) << endl;
}
