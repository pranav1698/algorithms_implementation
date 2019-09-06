#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int main() {
  string input;
  cin >> input;
  long long int A[5001];
  while(input != "0"){
    int* arr = new int[input.size()];
    int n=input.size();
    for(int i=0; i<input.size(); i++)
      arr[i]=input[i]-'0';

    //cout << num_codesi(arr, input.size()) << endl;
      for(int i=0; i<5000; i++)
        A[i]=0;
      A[0]=1;
      for(int i=1; i<n; i++){
        int x=arr[i-1]*10 + arr[i];
        if(arr[i]!=0)
          A[i]=A[i-1];
        if(x>=10 && x<=26 && i>1){
          A[i]+=A[i-2];
        } else if(x>=10 && x<=26){
          A[i]++;
        }
        A[i]=A[i]%mod;
      }
    cout << A[n-1] << endl;
    cin >> input;
  }
  return 0;
}
