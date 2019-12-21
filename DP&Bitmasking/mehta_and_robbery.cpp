// Very Very Important
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long long knapsack(int N,int W, pair<ll, ll>* arr, int* primes){
    long long *** dp = new long long ** [2];
    for(int i=0;i<2; i++){
        dp[i] = new long long*[N+1];
        for(int j=0; j<=N; j++){
            dp[i][j] = new long long[W+1];
            for(int k=0; k<=W; k++){
                dp[i][j][k]=0;
            }
        }
    }

    //base case for iterative dp
    for(int i=1; i<=N; i++){
        for(int j=1; j<=W; j++){
            dp[0][i][j] = dp[0][i-1][j];
            if(j>=arr[i-1].second){
                dp[0][i][j] = max(dp[0][i][j], (dp[0][i-1][j-arr[i-1].second] + arr[i-1].first));
            }
        }
    }

    for(int prime=1; prime<=10; prime++){
        int p=prime%2;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=W; j++){
                dp[p][i][j] = dp[p][i-1][j];
                if(j>=arr[i-1].second){
                    dp[p][i][j] = max(dp[p][i][j], max(dp[p][i-1][j-arr[i-1].second] + arr[i-1].first, dp[p^1][i-1][j-arr[i-1].second] + ((arr[i-1].first)*primes[prime])));
                }
            }
        }
    }

    return dp[0][N][W];
}

int main(){
    int N, W;
    cin >> N >> W;

    pair<long, long>* arr=new pair<long, long>[N];
    for(int i=0; i<N; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr, arr+n);
    int primes[11]={1,2,3,5,7,11,13,17,19,23,29};
    cout << knapsack(N, W, arr, primes) << endl;

}
