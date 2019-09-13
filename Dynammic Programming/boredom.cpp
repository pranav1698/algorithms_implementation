// Important Logic
#include<bits/stdc++.h>
using namespace std;


int solve(int n,vector<int>A){
  map<int, int> freq;
  for(int i=0; i<A.size(); i++)
    freq[A[i]] = freq[A[i]] + 1;

  int* output = new int[1001];
  output[0]=0;
  output[1]=freq[1];
  for(int i=2; i<=1000; i++){
      output[i] = max((i*freq[i] + output[i-2]), output[i-1]);
      //cout << output[i] << endl;
  }

  return output[1000];
}

int main(){
  int n;
  cin >> n;
  vector<int> A;
  for(int i=0; i<n; i++){
    int a;
    cin >> a;
    A.push_back(a);
  }
  solve(n, A);

}
