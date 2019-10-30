#include <bits/stdc++.h>
using namespace std;

// int knapsack(int* weights, int* values, int n, int maxWeight){
//
//   /* Don't write main().
//    *  Don't read input, it is passed as function argument.
//    *  Return output and don't print it.
//    *  Taking input and printing output is handled automatically.
//   */
//   if(n == 0)
//     return 0;
//   if(maxWeight <= 0)
//     return 0;
//
//     if(weights[n-1] <= maxWeight){
//       int option1 = values[n-1] + knapsack(weights, values, n-1, maxWeight-weights[n-1]);
//       int option2 = knapsack(weights, values, n-1, maxWeight);
//
//       return max(option1, option2);
//     } else {
//       return knapsack(weights, values, n-1, maxWeight);
//     }
//
// }

int knapsack(int* weights, int* values, int n, int maxWeight){
  int** dp = new int*[n+1];
  for(int i=0; i<=n; i++){
    dp[i]=new int[maxWeight+1];
  }

  for(int i=0; i<=n; i++)
    dp[i][0]=0;

  for(int j=0; j<=maxWeight; j++)
    dp[0][j]=0;

  for(int i=1; i<=n; i++){
    for(int j=1; j<=maxWeight; j++){
      dp[i][j] = dp[i-1][j];
      if(weights[i-1] <= j && (dp[i][j] < dp[i-1][j-weights[i-1]] + values[i-1])){
        dp[i][j] = max(dp[i-1][j], values[i-1] + dp[i-1][j-weights[i-1]]);
      }
    }
  }
  return dp[n][maxWeight];
}
