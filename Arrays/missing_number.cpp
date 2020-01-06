#include <bits/stdc++.h>
using namespace std;

int findMissing(int* a, int n){
    map<int, int> m;
    if(n == 1)
        return 2;
    for(int i=0; i<n-1; i++){
        m[a[i]] = 1;
    }

    for(int i=1; i<=n; i++){
        if(m[i] != 1)
            return i;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0; i<n-1; i++){
            cin >> arr[i];
        }
        cout << findMissing(arr, n) << endl;
    }
}
