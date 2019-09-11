// Very Important
#include <bits/stdc++.h>
using namespace std;

#define inf 100000000000000LL;

long long M[101][101];
long long kadane(vector<long long> v){
  int n=v.size();
  int i,j;
  long long ret=0, me=-inf;
  long long csum=0;
  for(int i=0; i<n; i++){
    csum+=v[i];
    if(csum<0)csum=0;
    ret= max(ret, csum);
    me=max(me, v[i]);
  }
  if(me<0) return me;
  else return ret;
}

// int maximum_sum(int** input, int r, int c){
//   int** output = new int*[r];
//   for(int i=0; i<r; i++)
//     output[i] = new int[c];
//
//   for(int i=0; i<r; i++){
//     for(int j=0; j<c; j++){
//       int sum=0;
//       for(int k=i; k<r; k++){
//         for(int l=j; l<c; l++){
//           sum = sum + input[k][l];
//         }
//       }
//       output[i][j] = sum;
//
//     }
//   }
// }

// int main()
// {
//     int r,c;
//     cin >> r >> c;
//     int** input=new int*[r];
//     for(int i=0;i<r;i++){
//       input[i] = new int[c];
//       for(int j=0; j<c; j++){
//         cin >> input[i][j];
//       }
//     }
//
//     for(int l=0; l<)
//
//     cout << maximum_sum(input, r, c) << endl;
//     return 0;
// }

int main(){
  long long mxsum =-inf;
  long long sum, i, j, k, n, m;
  cin >> n >> m;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> M[i][j];
    }
  }
  for(int l=0; l<m; l++){
    vector<long long> v(n,0);
    for(int r=l; r<m; r++){
      for(i=0;i<n;i++)
        v[i]+=M[i][r];
      mxsum=max(kadane(v), mxsum);
      //cout << mxsum << endl;
    }
  }
  cout << mxsum << endl;

}
