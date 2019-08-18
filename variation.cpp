//Important
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	int arr[n];

	for(int i=0; i<n; i++){
		arr[i]=0;
		cin >> arr[i];
	}
	sort(arr, arr+n);

	int i=0;
	int j=1;
	long ans=0;
	
	while(j<n){
		if((arr[j]-arr[i]) >= k){
			ans = ans + (n-j);
			i++;
			if(i==j){
				j++;	
			}
		} else {
			j++;

		}
	}
	cout << ans << endl;
	return 0;
}