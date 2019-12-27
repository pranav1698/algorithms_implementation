#include<bits/stdc++.h>
using namespace std;

int mex(int a, int b, int c){
    map<int, int> freq;
    freq[a] = freq[a] + 1;
    freq[b] = freq[b] + 1;
    freq[c] = freq[c] + 1;
    int limit = max(a, max(b,c));
    for(int i=0; i<=limit; i++){
        if(freq[i] == 0)
            return i;
    }
    return limit+1;
}

int grundy(int n){
    if(n==0){
        return 0;
    }
    return mex(grundy(n/2), grundy(n/3), grundy(n/6));
}

int main() {
        int n;
        cin >> n;
        cout << grundy(n) << endl;
        //cout << mex(0, 1, 3) << endl;
        return 0;
}
