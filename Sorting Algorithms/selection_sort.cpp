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
		int min_index = i;
		for(int j=i+1; j<n; j++){
			if(arr[j] < arr[min_index]){
				min_index = j;
			}
		}
		swap(&arr[i], &arr[min_index]);
	}

	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
}