#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, x;
    cin >> n >> k >> x;

    // int start[n];
    // int change[n];
    // for(int i=0; i<n; i++){
    //   cin >> start[i];
    // }
    // sort(start, start+n);
    // for(int i=0; i<n; i++){
    //   change[i] = start[i];
    // }
    //
    //
    // for(int i=0; i<n; i=i+2){
    //   change[i]=start[i]^x;
    // }
    //
    //
    // sort(change, change+n);
    // k=k-1;
    // int flag=1;
    // while(k--){
    //   flag=flag^1;
    // }
    //
    // int min, max;
    // if(flag == 1){
    //   min=change[0];
    //   max=change[n-1];
    // } else {
    //   min=start[0];
    //   max=start[n-1];
    // }
    //
    // cout << max << " " << min << endl;

    int freq[1000];
    int xor[1000];
    int start[n];
    for(int i=0; i<n; i++)
      cin >> start[i];

    for(int i=0; i<1000; i++){
      freq[i]=0;
      xor[i]=0;
    }
    for(int i=0; i<n; i++){
      freq[start[i]] = freq[start[i]] + 1;
    }


    while(k--){
      int count=0;
      for(int i=0; i<1000; i++){
        int temp= i^x;
        if(count % 2 == 0){
          xor[i] = xor[i] + freq[i]/2;
          xor[temp] = xor[temp] + freq[i] - xor[i];
        } else {
          xor[temp] = xor[temp] +freq[i]/2;
          xor[i] = xor[i] + freq[i] - xor[temp];
        }
        count=count + freq[i];
        freq[i] = xor[i];
      }
    }


    return 0;
}
