#include <bits/stdc++.h>
using namespace std;

int lps(string s){
    int max_l=0;
    int n=s.length();
    for(int i=0; i<n; i++){
        int l=i;
        int r=i;
        while(l>=0 && r<n && s[l]==s[r]){
            int curr_l=r-l+1;
            max_l=max(curr_l, max_l);
            l--;
            r++;
        }
        l=i;
        r=i+1;
        while(l>=0 && r<n && s[l]==s[r]){
            int curr_l=r-l+1;
            max_l=max(curr_l, max_l);
            l--;
            r++;
        }
    }
    return max_l;
}

int main(){
    string s;
    cin >> s;
    cout << lps(s) << endl;
    return 0;
}
