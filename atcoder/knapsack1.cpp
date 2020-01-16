#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, w;
    cin >> n >> w;
    ll weights[n];
    ll values[n];
    for(ll i=0; i<n; i++)
        cin >> weights[i] >> values[i];

    ll dp[2][w+1];
    for(ll i=0; i<2; i++)
        dp[i][0] = 0;
    for(int )

    for(ll i=1; i<=n; i++){
        for(ll j=0; j<=w; j++){
            dp[i][j] = dp[i-1][j];
            if(weights[i-1] <= j && (dp[i][j] < dp[i-1][j-weights[i-1]] + values[i-1])){
              dp[i][j] = max(dp[i-1][j], values[i-1] + dp[i-1][j-weights[i-1]]);
            }
        }
    }

    cout << dp[n][w] << endl;
}
