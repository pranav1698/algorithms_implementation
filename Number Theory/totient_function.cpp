#include <bits/stdc++.h>
using namespace std;

int eulerPhi(int n){
    int* phi= new int[n+1];

    for(int i=1; i<=n; i++){
        phi[i] = i;
    }

    for(int i=2; i<=n; i++){
        if(phi[i] == i){
            for(int j=2*i; j<=n; j+=i){
                phi[j] = (phi[j]*(i-1))/i;
            }
            phi[i]=i-1;
        }
    }
    return phi[n];
}

int main(){
        int n;
        cin >> n;
        cout << eulerPhi(n) << endl;
}
