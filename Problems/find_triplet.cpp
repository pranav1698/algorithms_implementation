#include<bits/stdc++.h>
using namespace std;
// arr - input array
// size - size of array
// x - sum of triplets

void FindTriplet(int arr[], int size, int x) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output and don't return it.
     * Taking input is handled automatically.
     */
    sort(arr, arr+size);
    for(int i=0; i<size; i++){
        int sum = arr[i];
        for(int j=i+1; j<size; j++){
            sum=sum+arr[j];
            for(int k=j+1; k<size; k++){
                sum=sum+arr[k];
                if(sum == x)
                    cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
                sum=arr[i] + arr[j];
            }
            sum=arr[i];
        }
    }

}
