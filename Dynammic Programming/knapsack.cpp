// Very Important
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

// int knapsack(int* weights, int* values, int n, int maxWeight){
//
//     // matrix to store final result
//     int mat[2][maxWeight+1];
//     memset(mat, 0, sizeof(mat));
//
//     // iterate through all items
//     int i = 0;
//     while (i < n) // one by one traverse each element
//     {
//         int j = 0; // traverse all weights j <= W
//
//         // if i is odd that mean till now we have odd
//         // number of elements so we store result in 1th
//         // indexed row
//         if (i%2!=0)
//         {
//             while (++j <= maxWeight) // check for each value
//             {
//                 if (weights[i] <= j) // include element
//                     mat[1][j] = max(values[i] + mat[0][j-weights[i]],
//                                     mat[0][j] );
//                 else           // exclude element
//                     mat[1][j] = mat[0][j];
//             }
//
//         }
//
//         // if i is even that mean till now we have even number
//         // of elements so we store result in 0th indexed row
//         else
//         {
//             while(++j <= maxWeight)
//             {
//                 if (weights[i] <= j)
//                     mat[0][j] = max(values[i] + mat[1][j-weights[i]],
//                                      mat[1][j]);
//                 else
//                     mat[0][j] = mat[1][j];
//             }
//         }
//         i++;
//     }
//
//     // Return mat[0][W] if n is odd, else mat[1][W]
//     return (n%2 != 0)? mat[0][maxWeight] : mat[1][maxWeight];
// }
