#include<bits/stdc++.h>
using namespace std;

int minAbsoluteDiff(int arr[], int n) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
	sort(arr, arr+n);
	int ans=INT_MAX;
	for(int i=0; i<n-1; i++){
		int diff=abs(arr[i], arr[i+1]);
		ans = min(diff, min);
	}
	return ans;
}