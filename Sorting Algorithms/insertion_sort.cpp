#include<bits/stdc++.h>
using namespace std;

void swap(int* xp, int* yp){
	int temp= *xp;
	*xp = *yp;
	*yp = temp;
}

int main(){
	int n = 100;
	int arr[n];
	for(int i=0; i<n; i++){
		arr[i] = n - i;
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<i; j++){
			if(arr[j] > arr[j+1]){
				swap(&arr[j], &arr[j+1]);
			}
		}
	}

	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
}