// Also known as kadane's algorithm
#include<bits/stdc++.h>
using namespace std;

int kadane(int * arr, int n){
	int current_sum=0;
	int best_sum=0;
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

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	int ans = kadane(arr, n);
	cout << ans << endl;
	return 0;
}