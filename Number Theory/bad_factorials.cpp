#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

ll power(ll x, ll y, ll p){
    ll res=1;
    x = x%p;
    while(y>0){
        if(y & 1)
            res = (res*x) % p;

        y = y>>1;
        x = (x*x)%p;
    }
    return res;
}

ll modInverse(ll a, ll p){
    return power(a, p-2, p);
}

ll modFact(ll n, ll p){
    if(p <= n)
        return 0;
        ll res=p-1;

    for(ll i=n+1; i<p; i++){
        res = (res * modInverse(i, p)) % p;
    }
    return res;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n, p;
        cin >> n >> p;
        cout << modFact(n, p) << endl;;
    }
}
