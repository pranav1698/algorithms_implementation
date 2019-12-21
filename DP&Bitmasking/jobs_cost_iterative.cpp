    #include <bits/stdc++.h>
    using namespace std;

int main(){
    int cost[4][4] = {{10,2,6,5},{1,15,12,8},{7,8,9,3},{15,13,4,10}};
    int limit = (1<<4);
    int* dp = new int[limit];
    for(int i=0; i<limit; i++){
        dp[i] = INT_MAX;
    }

    dp[0]=0;

    for(int mask=0; mask<limit-1; mask++){
        int k=0;
        int temp=mask;
        while(temp > 0){
            if((temp%2) == 1){
                k=k+1;
            }
            temp=temp/2;
        }
        for(int j=0; j<4; j++){
            if(!(mask&(1<<j))){
                dp[(mask|(1<<j))] = min(dp[(mask|(1<<j))], cost[k][j] + dp[mask]);
            }
        }
    }
    cout << dp[limit-1] << endl;
}
