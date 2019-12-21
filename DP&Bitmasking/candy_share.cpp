#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long long solve(int** input, int n){
    ll limit=(1<<n);
    int* dp=new int[limit];
    for(int i=0; i<limit; i++){
        dp[i]=0;
    }

    dp[0]=1;
    ll count=0;
    for(int mask=0; mask<(limit-1); mask++){
        int k=0;
        int temp=mask;
        while(temp > 0){
            if((temp%2) == 1){
                k=k+1;
            }
            temp=temp/2;
        }
        for(int j=0;j<n; j++){
            if(!(mask&(1<<j))){
                if(input[k][j] == 1){
                    dp[mask|(1<<j)] = dp[mask|(1<<j)] + dp[mask];
                }
            }
        }
    }
    return dp[limit - 1];
}

int main(){
    int n;
    cin >> n;
    int** input = new int*[n];
    for(int i=0; i<n; i++){
        input[i] = new int[n];
        for(int j=0; j<n; j++){
            cin >> input[i][j];
        }
    }
    cout << solve(input, n) << endl;
}
