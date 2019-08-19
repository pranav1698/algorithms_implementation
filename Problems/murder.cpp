#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int arr[n];
		for(int i=0; i<n; i++){
			arr[i]=0;
			cin >> arr[i];
		}
		long ans=0;
		for(int i=1; i<n; i++){
			sort(arr, arr+i);
			int left=0;
			int right=i-1;
			// cout << arr[i] << endl;
			while(left<=right && left<i){
				cout << left << " " << right << endl;
				int mid=left + (right - left) / 2;
				if(arr[i] <= arr[mid])
					right=mid-1;
				if(arr[i] > arr[mid]){
					int j=left;
					while(j<=mid){
						ans = ans + arr[j];
						j++;
					}
					left=mid+1;
				}
			}
			// cout << ans << endl;
		}
	cout << ans << endl;
	}
}