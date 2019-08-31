#include<bits/stdc++.h>
using namespace std;
int main() {
	long n,k;
	cin >> n >> k;
	long arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	sort(arr, arr+n);
	//long smallestAns=arr[n-1] - arr[0];
	for(int i=0; i<n; i++){
		if(arr[i] < k){
			arr[i] = arr[i] + k;
		} else if(arr[i] > k) {
			arr[i] = arr[i] - k;
		}
	}
	sort(arr, arr+n);
	long answer = arr[n-1] - arr[0];
	cout << answer << endl;	
}