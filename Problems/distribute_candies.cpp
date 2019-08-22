// Very Important
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n; int k;
        cin >> n;
        cin >> k;
        //cout << n << " " << k << endl; 
        int arr[n];
      	for(int i=0; i<n; i++){
      		arr[i]=0;
      		cin >> arr[i];
      	//	cout << arr[i] << endl;
      	}
      	sort(arr, arr+n, greater<int>());
        // map<int, int, greater<int>> m;
        // for(int i=0; i<n; i++){
        //     m[arr[i]]++;
        // }
        // int count=0;
        // map<int, int>::iterator it=m.begin();
        // while(count<=k && it!=m.end()){
        // 	cout << it->first << endl;
        // 	count=count + it->second;
        // 	it++;
        // }
        // cout << it->first << endl;

        int count=0;
        int curr=0;
        int j=1;
        if(k == 1){
          cout << arr[0] << endl;
        } else {
          while(count < k){
            if(arr[j] < arr[curr]){
              count = 0;
              curr++;
              j=0;
            } else {
              j++;
              count++;
            }
          }
          int max=arr[curr];
          for(int i=2; i<=k; i++){
            int value=arr[0]/i;
            if(value > max){
              int c=i;
              int j=1;
              while(j<n){
                if(arr[j] >= value && c<k){
                  c++;
                  j++;
                } else {
                  break;
                }
              }
              if(c == k){
                max=value;
                break;
              }
            }
          }
        cout << max << endl;

      }
    }
        
}