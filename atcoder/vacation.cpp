#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n][3];
    for(int i=0; i<n; i++)
        for(int j=0; j<3; j++)
            cin >> arr[i][j];

    int dp[n][3];
    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];

    for(int i=1; i<n; i++){
        for(int j=0; j<3; j++){
            int option=INT_MIN;
            for(int k=0; k<3; k++){
                if(j == k)
                    continue;
                option = max(option, dp[i-1][k] + arr[i][j]);
            }
            dp[i][j] = option;
        }
    }

    int ans=INT_MIN;
    for(int j=0; j<3; j++)
        ans = max(ans, dp[n-1][j]);

    cout << ans << endl;
}
