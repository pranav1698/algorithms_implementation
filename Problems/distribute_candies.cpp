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
        map<int, int, greater<int>> m;
        for(int i=0; i<n; i++){
            m[arr[i]]++;
        }
        int count=0;
        map<int, int>::iterator it=m.begin();
        while(count<=k && it!=m.end()){
        	cout << it->first << endl;
        	count=count + it->second;
        	it++;
        }
        cout << it->first << endl;
    }
}