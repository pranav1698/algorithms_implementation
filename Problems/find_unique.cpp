#include<bits/stdc++.h>
using namespace std;
// arr - input array
// size - size of array

int FindUnique(int arr[], int size){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    map<int, int> freqMap;
    for(int i=0; i<size; i++){
        freqMap[arr[i]] = freqMap[arr[i]] + 1;
    }
    
    map<int, int>::iterator it;
    for(it=freqMap.begin(); it!=freqMap.end(); it++){
        if(it->second == 1)
            return it->first;
    }
}