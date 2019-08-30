//Important
#include<bits/stdc++.h>
using namespace std;

int main(){
	long n;
	cin >> n;
	long arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	long energy=0;
	long i=0;
	long j=1;
	while(j<n-1){
		//cout << arr[j] << endl;
		if(abs(arr[i]) >= abs(arr[j])){
			if(abs(arr[i]) == abs(arr[j])){
				if(arr[i] > 0){
					energy += ((j-i) * arr[i]) + (((j*j)-(i*i))*(arr[i]*arr[i]));
					i=j;
				}
			} else {
				energy += ((j-i) * arr[i]) + (((j*j)-(i*i))*(arr[i]*arr[i]));
				i=j;
			}
		}
		j++;
	}
	energy += (((n-1)-i) * arr[i]) + ((((n-1)*(n-1))-(i*i))*(arr[i]*arr[i]));
	cout << energy << endl;
}