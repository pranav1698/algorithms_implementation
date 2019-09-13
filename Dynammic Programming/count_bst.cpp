//Important
#include<bits/stdc++.h>
using namespace std;

int countBST( int n)
{
  int* output= new int[n+1];
  output[0]=1;
  output[1]=1;

  for(int i=2; i<=n; i++){
    for(int j=1; j<=i; j++){
      output[i] = output[i] + output[j-1] + output[i-j];
    }
  }
  return output[n];
}

int main(){
  int n;
  cin >> n;
  cout << countBST(n) << endl;
}
