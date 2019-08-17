//Important
#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int** arr = new int*[n];

	for(int i=0; i < n; i++){
		arr[i] = new int[n];
		for(int j=0; j < n; j++){
			cin >> arr[i][j];
		}
	}
	int sum =0;
	int j = (n-1);
	for(int i=0; i<n; i++){
		sum += arr[i][i];
		sum += arr[i][j];
		j--;
	}
	
	if(n % 2 != 0){
		sum -= arr[(n/2)][(n/2)];
	}
	for(int i=0; i < n; i += (n-1)){
		for(int j=1; j < n-1; j++){
			sum += arr[i][j];
		}
	}
	for(int j=0; j < n; j += (n-1)){
		for(int i=1; i < n-1; i++){
			sum += arr[i][j];
		}
	}
	cout << sum << endl;
}