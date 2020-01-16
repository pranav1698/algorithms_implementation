#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];

    int costs[n+1];
    costs[0]=0;
    costs[1]=0;

    for(int i=2; i<=n; i++){
        int option=INT_MAX;
        for(int j=1; j<=k; j++){
            if(j>=i){
                continue;
            }
            option = min(option, costs[i-j] + abs(arr[i-1] - arr[i-j-1]));
        }
        costs[i] = option;
    }

    cout << costs[n] << endl;
}
