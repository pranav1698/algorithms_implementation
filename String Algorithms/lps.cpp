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
