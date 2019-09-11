//Important
#include <bits/stdc++.h>
using namespace std;

int min_cost2(int** input, int m, int n){
  int** output = new int*[m];
  for(int i=0; i<m; i++)
    output[i] = new int[n];

  output[m-1][n-1] = input[m-1][n-1];

  for(int i=m-2; i>=0; i--)
    output[i][n-1] = output[i+1][n-1] + input[i][n-1];

  for(int j=n-2; j>=0; j--)
    output[m-1][j] = output[m-1][j+1] + input[m-1][j];

  for(int i=m-2; i>=0; i--){
    for(int j=m-2; j>=0; j--){
      output[i][j] = input[i][j] + min(output[i+1][j], min(output[i+1][j+1], output[i][j+1]));
    }
  }

  return output[0][0];
}

// int min_cost(int** input, int si, int sj, int ei, int ej, int** output){
//   if(si==ei && sj==ej){
//     return input[ei][ej];
//   }
//   if(si > ei || sj > ej){
//     return INT_MAX;
//   }
//   if(output[si][sj] > -1)
//     return output[si][sj];
//
//   int option1 = min_cost(input, si+1, sj, ei, ej, output);
//   int option2 = min_cost(input, si, sj+1, ei, ej, output);
//   int option3 = min_cost(input, si+1, sj+1, ei, ej, output);
//
//   int ans= input[si][sj] + min(option1, min(option2, option3));
//   output[si][sj] = ans;
//   return ans;
// }


int main(){
  int** arr = new int*[3];

	for(int i=0; i < 3; i++){
		arr[i] = new int[3];
		for(int j=0; j < 3; j++){
			cin >> arr[i][j];
		}
	}

  int** output= new int*[3];
  for(int i=0; i < 3; i++){
		output[i] = new int[3];
		for(int j=0; j < 3; j++){
			output[i][j]=-1;
		}
	}
  cout << min_cost2(arr, 3,3) << endl;

}
