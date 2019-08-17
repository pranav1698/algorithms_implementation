//Important
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[n];
    
    for(int i=0; i<n; i++){
        arr[i] = 0;
        cin >> arr[i];
    }
    
    int profit = 0;
    for(int i=0; i<n; i++){
        int diff = 0;
        for(int j=i+1; j<n; j++){
            diff = arr[j] - arr[i];
            if(diff > profit){
                profit = diff;
            }
        }
    }
    cout << profit << endl;
    return 0;
}