#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int input[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> input[i][j];
        }
    }

    int dp[n][m];

    for(int j=0; j<m; j++)
        dp[n-1][j] = input[n-1][j];

    for(int i=n-2; i>=0; i--){
        for(int j=0; j<m; j++){
            int option1;
            if(j>0){
                option1 = dp[i+1][j-1];
            } else {
                option1 = INT_MAX;
            }
            int option2 = dp[i+1][j];
            int option3;
            if(j<m-1){
                option3 = dp[i+1][j+1];
            } else {
                option3 = INT_MAX;
            }

            dp[i][j] = input[i][j] + min(option1, min(option2,option3));
            //cout << dp[i][j] << endl;
        }
    }

    int ans=INT_MAX;
    for(int j=0; j<m; j++)
        ans=min(ans, dp[0][j]);

    cout << ans << endl;
    return 0;
}
