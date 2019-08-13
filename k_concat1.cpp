#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll kadane(int * arr, int n){
	int current_sum=0;
	int best_sum=INT_MIN;
	for(int i=0; i<n; i++){
		current_sum += arr[i];
		if(current_sum < 0){
			current_sum = 0;
		}
		if(current_sum > best_sum){
			best_sum = current_sum;
		}
	}
	return best_sum;

}

ll maxSubArraySum(int * arr, int n, int k){
	ll kadanes_sum=kadane(arr,n);
	ll ans=0;
	if(k==1){
		return kadanes_sum;
	}
	ll current_prefix_sum=0, curent_suffix_sum=0;
	ll max_prefix_sum=INT_MIN, max_suffix_sum=INT_MIN;
	for(int i=0; i<n; i++){
		current_prefix_sum += arr[i];
		max_prefix_sum = max(current_prefix_sum, max_prefix_sum);
	}
	ll total_sum = current_prefix_sum;
	for(int i=n-1; i>=0; i--){
		curent_suffix_sum += arr[i];
		max_suffix_sum = max(curent_suffix_sum, max_suffix_sum); 
	}
	if(total_sum<0){
		ans = max(max_suffix_sum + max_prefix_sum, kadanes_sum);
	}else{
		ans = max(max_prefix_sum + max_suffix_sum + (total_sum*(k-2)), kadanes_sum);
	}

	return ans;
} 

int main(){
	int t;
	cin >> t;
	for(int i=0; i<t; i++){
		int n, k;
		cin >> n >> k;
		int arr[n];
		for(int i=0; i<n; i++){
			cin >> arr[i];
		}
		cout << maxSubArraySum(arr, n, k) << endl;
	}
	
}s