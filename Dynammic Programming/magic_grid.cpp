#include<bits/stdc++.h>
using namespace std;

int magic_grid(int** input, int m, int n){
  int** output= new int*[m];
  for(int i=0; i<m; i++)
    output[i]= new int[n];

  output[m-1][n-1]= 1;
  output[m-1][n-2]=1;
  output[m-2][n-1]=1;

  for(int i=m-3; i>=0; i--){
    int option = output[i+1][n-1] - input[i+1][n-1];
    if(option <= 0){
      output[i][n-1] = 1;
    } else {
      output[i][n-1] = option;
    }
  }

  for(int j=n-3; j>=0; j--){
    int option = output[m-1][j+1] - input[m-1][j+1];
    if(option <= 0){
      output[m-1][j] = 1;
    } else {
      output[m-1][j] = option;
    }
  }

  for(int i=m-2; i>=0; i--){
    for(int j=n-2; j>=0; j--){
      int option1 = output[i][j+1] - input[i][j+1];
      if(option1<=0)
        option1=1;
      int option2 = output[i+1][j] - input[i+1][j];
      if(option2<=0)
        option2=1;

      output[i][j] = min(option1, option2);
    }
  }

  return output[0][0];
}

// int magic_grid(int** input, int si, int sj, int m, int n){
//
//   if(si == m-1 && sj==n)
//     return 1;
//   if(si == m && sj==n-1)
//     return 1;
//   if(si > m || sj > n)
//     return INT_MAX;
//
//   int option1, option2;
//   if(si+1 <= m){
//     option1 = magic_grid(input, si+1, sj, m, n) - input[si+1][sj];
//   } else {
//     option1 = magic_grid(input, si+1, sj, m, n);
//   }
//   if(sj+1 <= n){
//     option2 = magic_grid(input, si, sj+1, m, n) - input[si][sj+1];
//   } else {
//     option2 = magic_grid(input, si, sj+1, m, n);
//   }
//
//   if(option1 <=0)
//     option1 = 1;
//   if(option2 <= 0)
//     option2 = 1;
//
//   return min(option1, option2);
// }



int main(){
  int t;
  cin >> t;
  while(t--){
    int r,c;
    cin >> r >> c;

    int** arr = new int*[r];
  	for(int i=0; i < r; i++){
  		arr[i] = new int[c];
  		for(int j=0; j < c; j++){
  			cin >> arr[i][j];
  		}
  	}
  	cout << magic_grid(arr,r,c) << endl;
  }
}
