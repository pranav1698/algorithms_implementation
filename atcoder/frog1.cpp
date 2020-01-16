#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];

    int costs[n+1];
    costs[1]=0;
    costs[0]=0;
    costs[2] = abs(arr[1] - arr[0]);

    for(int i=3; i<=n; i++){
        int option1= costs[i-1] + abs(arr[i-1] - arr[i-2]);
        int option2 = costs[i-2] + abs(arr[i-1] - arr[i-3]);
        //cout << option1 << ' ' << option2 << endl;
        costs[i] = min(option1, option2);
        //cout << costs[i] << endl;
    }

    cout << costs[n] << endl;
}
