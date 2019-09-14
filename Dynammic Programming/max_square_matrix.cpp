// Very Important
#include<bits/stdc++.h>
using namespace std;


int findMaxSquareWithAllZeros(int** arr, int row, int col){
      int** output = new int*[row];
      for(int i=0; i<row; i++)
        output[i] = new int[col];

      for(int i=0; i<row; i++){
        if(arr[i][0] == 0){
          output[i][0]=1;
        } else {
          output[i][0]=0;
        }
      }

      for(int j=0; j<col; j++){
        if(arr[0][j] == 0){
          output[0][j]=1;
        } else {
          output[0][j]=0;
        }
      }

      for(int i=1; i<row; i++){
        for(int j=1; j<col; j++){
          if(arr[i][j]==1){
            output[i][j]=0;
          } else {
            int k1 = output[i-1][j-1];
            int k2 = output[i][j-1];
            int k3 = output[i-1][j];
            output[i][j] = min(k1, min(k2,k3)) + 1;
          }
          //cout << output[i][j] << endl;
        }
      }

      int size=INT_MIN;
      for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
          //cout << output[i][j] << endl;
          size = max(size, output[i][j]);
        }
      }
      delete[] output;
      return size;
}
