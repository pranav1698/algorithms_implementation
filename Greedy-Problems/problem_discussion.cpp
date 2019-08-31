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
	long diff=arr[n-1] - arr[0];
	long small=arr[0] + k;
	long big=arr[n-1] - k;
	for(int i=0; i<n-1; i++){
		long add=arr[i]+k;
		long subs=arr[i]-k;
		if(subs>=small || add<=big){
			continue;
		} else {
			if((big-subs)<=(add-small)){
				small=subs;
			} else {
				big=add;
			}	
		}
		
	}
	long answer=min(diff, (big-small));
	cout << answer << endl;
}