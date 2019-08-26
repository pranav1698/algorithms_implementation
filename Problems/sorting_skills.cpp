// Important
#include<bits/stdc++.h>
using namespace std;

void swap(int* x, int* y){
	int temp=*x;
	*x=*y;
	*y=temp;
}

bool merge (int* arr, int left, int mid, int right){
	if(arr[mid] < arr[mid-1]){
		if(abs((arr[mid-1]-arr[mid])) == 1){
			swap(&arr[mid-1], &arr[mid]);
			return true;
		} else {
			return false;
		}
	} else {
		return true;
	}
}

bool sort_skills(int* arr, int left, int right){
	if(left >= right)
		return true;
	int mid = left + (right-left)/2;
	bool flag1=sort_skills(arr, left, mid);
	bool flag2=sort_skills(arr, mid+1, right);

	return flag1 && flag2 && merge(arr, left, mid+1, right);
}

int main()
{
	int t;
	cin >> t;
	//cout << t << endl;
	while(t--){
		int n;
		cin >> n;
		int arr[n];
		//cout << n << endl;
		for(int i=0; i<n; i++)
			cin >> arr[i];
		bool result=sort_skills(arr, 0, n-1);
		//cout << result << endl;
		if(result){
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
    
	return 0;
}
