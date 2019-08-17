//Important
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,t;
    cin >> n >> t;
    int arr[n];

    for(int i=0; i<n; i++){
 	    arr[i] = 0;
 	    cin >> arr[i];
    }

    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n;j++){
            sum += arr[j];
            if(sum == t){
                cout << "true" << endl;
                for(int k=i; k<=j; k++){
                    cout << arr[k] << " ";
                }
                return 0;
            }
            if(sum >= t){
                break;
            }
        }
    }
    cout << "false" << endl;
    return 0;
}