#include<bits/stdc++.h>
using namespace std;

int main(){
  typedef long long ll;
  ll n;
  cin >> n;
  ll m;
  cin >> m;


  ll dp[2][n+1];
  for(ll i=0; i<=1; i++)
    for(ll j=0; j<=n; j++)
      dp[i][j]=0;

  int flag=1;
  for(ll i=1; i<=m; i++){
    ll l, r;
    cin >> l >> r;
    for(ll j=1; j<=n; j++){
      dp[flag][j]=dp[flag^1][j];
      if(j>=l && j<=r){
          dp[flag][j] = dp[flag^1][j] + 1;
      }
      //cout << dp[flag][j] << " ";
    }
    //cout << endl;
    flag = flag^1;
  }

  ll q;
  cin >> q;
  for(ll i=0; i<q; i++){
    ll x;
    cin >> x;
    ll count=0;
    for(ll j=1; j<=n; j++)
      if(dp[flag^1][j] >= x)
        count = count +1;

    cout << count << endl;
  }

}
