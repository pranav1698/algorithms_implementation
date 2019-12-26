#include <bits/stdc++.h>
using namespace std;

int* getlps(string pattern){
    int len = pattern.length();
    int* lps= new int[len];

    lps[0]=0;
    int i=1;
    int j=0;
    while(i<len){
        if(pattern[j] == pattern[i]){
            lps[i] = j+1;
            j++;
            i++;
        } else {
            if(j!=0){
                j = lps[j-1];
            } else {
                i++;
                lps[i]=0;
            }
        }
    }
    return lps;
}

bool kmpSearch(string text, string pattern){
    int lenText = text.length();
    int lenPat = pattern.length();

    int* lps= getlps(pattern);
    int i=0;
    int j=0;
    while(i<lenText && j<lenPat){
        if(text[i] == pattern[j]){
            i++;
            j++;
        } else {
            if(j!=0){
                j = lps[j-1];
            } else {
                i++;
            }
        }
    }
    if(j==lenPat){
        return true;
    } else {
        return false;
    }
}

int main(){
    string str = "abcxabcdabcdabcy";
    string substr = "abcdabcx";
    cout << kmpSearch(str, substr) << endl;
    return 0;
}
