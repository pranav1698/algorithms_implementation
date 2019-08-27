#include<bits/stdc++.h>
using namespace std;

int returnFirstSetBit(int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    n=n & (-1 * n);
    return n;
}

int main(){
    int n;
    cin >> n;
    cout << returnFirstSetBit(n) << endl;
}

