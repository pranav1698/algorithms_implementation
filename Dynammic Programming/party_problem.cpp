#include <bits/stdc++.h>
using namespace std;

int main(){
  int P, n;
  cin >> P >> n;
  while(P!=0 && n!=0){
    int p[n];
    int v[n];
    for(int i=0; i<n; i++)
      cin >> p[i] >> v[i];

    int dp[n+1][P+1];
    for(int i=0; i<=n; i++)
      dp[i][0] = 0;

    for(int j=0; j<=P; j++)
      dp[0][j]=0;
    int weight=0;
    for(int i=1; i<=n; i++){
      for(int j=0; j<=P; j++){
        dp[i][j]=dp[i-1][j];
        if(j >= p[i-1]){
          dp[i][j] = max(dp[i-1][j], v[i-1] + dp[i-1][j-p[i-1]]);
        }
      }
    }
    int maxfun=dp[n][P];
	  int minmoney=0;
     for(int i=0;i<=P;i++){
		  if(dp[n][i]==maxfun){
			     minmoney=i;
           break;
      }
	  }
    cout << minmoney << " " << dp[n][P] << endl;

    cin >> P >> n;
  }
}
