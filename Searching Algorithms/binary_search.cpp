#include<bits/stdc++.h>
using namespace std;

int main(){
	int arr[] = { 2, 3, 4, 10, 40 };
	int n=5;
	int x=10;

	long start=0;
	long end= n-1;
	while(start<=end){
		long mid=start + (end-start)/2;
		if(arr[mid] == x){
			cout << mid+1 << endl;
			return 0;
		} else if(x > arr[mid]){
			start = mid+1;
		} else {
			end = mid-1;
		}
	}
}