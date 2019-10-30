#include<bits/stdc++.h>
using namespace std;
#define mod 10000000007

int gcd(int num1, int num2){
  int i=1;
  int gcd=1;
  while(i<=num1 && i<=num2){
    if(num1%i==0 && num2%i==0){
      gcd=i;
    }
    i++;
  }

  return gcd;
}

int gcd_subsequence(int* input, int n){
  int** output= new int*[n];
  for(int i=0; i<n; i++){
    output[i]= new int[101];
    for(int j=0; j<=100; j++){
      output[i][j]=0;
    }
  }

  output[0][input[0]]=1;
  for(int i=1; i<n; i++){
    for(int j=0; j<i; j++){
      if(input[j] < input[i]){
        int g= gcd(input[i], input[j]);
        if(input[j] != 1)
          output[i][g] = (output[i][g] + 1)%mod;
        for(int k=1; k<=100; k++){
          int ng = gcd(input[i], k);

          output[i][ng] = (output[i][ng] + output[j][k])%mod;
        }
      }
    }
  }
  int sum=0;
  for(int i=0; i<n; i++){
    sum = (sum + output[i][1])%mod;
  }

  return sum;
}

int main(){
  int n;
  cin >> n;
  int input[n];
  for(int i=0; i<n; i++)
    cin >> input[i];

  cout << gcd_subsequence(input, n) << endl;
}
