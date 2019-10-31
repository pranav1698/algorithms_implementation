#include <bits/stdc++.h>
using namespace std;

// bool subsetSum(int* val, int n, int sum){
//   bool** dp = new bool*[n+1];
//   for(int i=0; i<=n; i++)
//     dp[i]=new bool[sum+1];
//
//   dp[0][0]=true;
//   for(int i=1; i<=n; i++)
//     dp[i][0]=true;
//   for(int j=1; j<=sum; j++)
//     dp[0][j]=false;
//
//   for(int i=1; i<=n; i++){
//     for(int j=1; j<=sum; j++){
//       dp[i][j]=dp[i-1][j];
//       if(j >= val[i-1])
//         dp[i][j] = dp[i-1][j] || dp[i-1][j-val[i-1]];
//     }
//   }
//
//   bool ans = dp[n][sum];
//   return ans;
//
// }

bool subsetSum(int* val, int n, int sum){
  bool** dp = new bool*[2];
  for(int i=0; i<=n; i++)
    dp[i]=new bool[sum+1];

  dp[0][0]=true;
  for(int j=1; j<=sum; j++)
    dp[0][j]=false;

  int flag=1;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=sum; j++){
      dp[flag][j]=dp[flag^1][j];
      if(j >= val[i-1])
        dp[flag][j] = dp[flag^1][j] || dp[flag^1][j-val[i-1]];
    }
    flag=flag^1;
  }

  bool ans = dp[flag^1][sum];
  return ans;

}

int main(){
  int n;
  cin >> n;
  int val[n];
  for(int i=0; i<n; i++)
    cin >> val[i];
  int sum;
  cin >> sum;
  if(subsetSum(val, n, sum)){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
