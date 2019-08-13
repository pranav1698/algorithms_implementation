#include<bits/stdc++.h>
using namespace std;

int maxProductSubarray(int* arr, int n){
	int max_ending_here=1;
	int min_ending_here=1;
	int max_sum=1;
	for(int i=0; i<n; i++){
		if(arr[i] > 0){
			max_ending_here = arr[i] * max_ending_here;
			min_ending_here = min(1, (arr[i]*min_ending_here));
		} else if(arr[i] < 0){
			int temp=max_ending_here;
			max_ending_here = max(1, (arr[i]*min_ending_here));
			min_ending_here = temp*arr[i];
		} else {
			max_ending_here=1;
			min_ending_here=1;
		}
		if(max_sum < max_ending_here)
			max_sum = max_ending_here;
	}
	return max_sum;
}

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; i++){
		arr[i]=0;
		cin >> arr[i];
	}
	cout << maxProductSubarray(arr, n) << endl;

}