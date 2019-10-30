#include <bits/stdc++.h>
using namespace std;

int editDistance(string s1, string s2){
  int m=s1.size();
  int n=s2.size();

  int** dp= new int*[m+1];
  for(int i=0; i<=m; i++){
    dp[i] = new int[n+1];
  }

  for(int i=0; i<=m; i++)
    dp[i][0]=i;

  for(int j=0; j<=n; j++)
    dp[0][j]=j;

  for(int i=1; i<=m; i++){
    for(int j=1; j<=n; j++){
      if(s1[m-i] == s2[n-j]){
        dp[i][j] = dp[i-1][j-1];
      } else {
        int option1 = 1 + dp[i-1][j-1];
        int option2 = 1 + dp[i-1][j];
        int option3 = 1 + dp[i][j-1];
        dp[i][j] = min(option1, min(option2, option3));
      }
      //cout << dp[i][j] << endl;
    }
  }

  int ans = dp[m][n];
  //delete[][] output;
  return ans;
}

int main(){
  char a[100];
  char b[100];
  cin >> a;
  cin >> b;
  cout << editDistance(a,b) << endl;
  //cout << lcs2(a,b) << endl;
  //cout << lcs(a,b) << endl;
}
