#include <bits/stdc++.h>
using namespace std;

int power(int x, int n){
    if(x == 0)
        return 0;
    if(n == 0)
        return 1;
    if(n == 1)
        return x;

    int value = power(x, n/2);
    if(n%2 == 0){
        return value*value;
    } else {
        return value*value*x;
    }
}

int main(){
    int x, n;
    cin >> x >> n;
    cout << power(x, n) << endl;
}
