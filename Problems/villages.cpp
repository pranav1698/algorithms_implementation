#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int arr[n];

	for(int i=0; i <  n;i++){
		arr[i] = 0;
		cin >> arr[i];
	}

	int j = n-1;
	for(int i=0; i < (n/2); i++){
		int combined = arr[i] + arr[j];
		int groups = combined / 10;
		int count = combined % 10;
		cout << groups << " " << count << endl;
		j--;
	}
	return 0;
}