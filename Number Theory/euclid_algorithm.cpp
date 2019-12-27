#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    //cout << a << " " << b << endl;
    if(a<b){
        return gcd(b,a);
    }
    if(b==0){
        return a;
    }
    return gcd(b, a%b);
}

int main(){
    int a, b;
    cin >> a;
    cin >> b;
    cout << gcd(a,b) << endl;
    return 0;
}
