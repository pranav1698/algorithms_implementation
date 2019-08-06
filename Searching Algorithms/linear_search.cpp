#include<bits/stdc++.h>
using namespace std;

int main(){
	int n = 1000000;
	int x = 99999;
	int arr[n];
	for(int i=0; i<n; i++){
		arr[i] = i;
	}

	for(int i=0; i<n; i++){
		if(arr[i] == x){
			cout << i+1 << endl;
		}
	}
}