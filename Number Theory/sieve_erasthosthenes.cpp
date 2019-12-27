#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    cin >> n;
    bool* arr = new bool[n+1];
    for(int i=0; i<=n; i++)
        arr[i]=true;

    arr[0]=false;
    arr[1]=false;
    for(int i=2; i*i<=n; i++){
        if(arr[i]){
            for(int j=i*i; j<=n; j+=i){
                arr[j]=false;
            }
        }
    }

    int count=0;
    for(ll i=0; i<=n; i++){
        if(arr[i]){
            count = count + 1;
        }
    }
    cout << count << endl;

    return 0;
}
