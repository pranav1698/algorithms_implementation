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
		int key = arr[i];
		int j = i - 1;  

        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;
	}

	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
}