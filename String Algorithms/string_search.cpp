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

int findString(char S[], char T[]) {
    string text(S);
    string pattern(T);
    int lens= text.length();
    int lent= pattern.length();

    int* lps=getlps(T);
    int i=0;
    int j=0;
    int last;
    while(i<lens && j<lent){
        if(S[i] == T[j]){
            i++;
            j++;
        } else {
            if(j!=0){
                j=lps[j-1];
            } else {
                i++;
            }
        }
        if(j==lent-1){
            last=i;
            //cout << last << endl;
        }
    }
    if(j==lent){
        return (last-lent)+1;
    } else {
        return -1;
    }
}
