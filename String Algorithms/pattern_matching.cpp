#include <bits/stdc++.h>
using namespace std;

bool isMatching(string s, string p){
    int n=s.length();
    int m=p.length();
    // if the pattern is found, then it will remain true otherwise it will change to false
    for(int i=0; i<=n-m; i++){
        // tranversing only when the characters are equal in both positions
        bool isFound=true;
        for(int j=0;j<m; j++){
            if(s[i+j] != p[j]){
                isFound=false;
                break;
            }
        }
        if(isFound == true){
            return true;
        }
    }
    return false;
}

int main(){
    string s,p;
    cin >> s;
    cin >> p;

    cout << isMatching(s, p) << endl;
     return 0;
}
