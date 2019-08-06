#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	int arr[1000];
	for(int i = 0; i < 1001; i++) {
		arr[i] = 0;
	}
	for(int i = 0; i < n; i++){
		int j,k;
		cin >> j >> k;
		arr[j]++;
		arr[k]++;
	}

	int max = 0;
	for(int i = 0; i < n; i++){
		if(arr[i] > max){
			max = arr[i];
		}
	}

	for(int i = 0; i < 1001; i++){
		if(arr[i] == max){
			cout << i << endl;
		}
	}
}