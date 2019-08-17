#include<bits/stdc++.h>
using namespace std;
// arr - input array
// size - size of array
// d - array to be rotated by d elements

void Rotate(int arr[], int d, int size) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * No need to print or return the output.
     * Taking input and printing the output is handled automatically.
     */
    int count=0;
    while(count<d){
        int temp=arr[0];
        for(int i=0; i<size-1; i++){
            arr[i]=arr[i+1];
        }
        arr[size-1]=temp;
        count++;
    }    
}   
