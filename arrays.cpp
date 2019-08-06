#include<bits/stdc++.h>
using namespace std;

int main() {
	int size, queries;
	cin >> size >> queries;

	int arr[size];
	for(int i=0; i < size; i++){
		cin >> arr[i];
	}

	for(int i=0; i<queries; i++){
		int page_number;
		cin >> page_number;
		cout << arr[page_number - 1] << endl;
	}
	return 0;
}