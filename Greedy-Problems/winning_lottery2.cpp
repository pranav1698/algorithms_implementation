// Important
#include<bits/stdc++.h>
using namespace std;
int main() {
	long s,d;
	cin >> s >> d;
	long arr[d];
	long smallSum=s-1;
	//cout << smallSum << endl;
	for(int i=d-1; i>=1; i--){
		if(smallSum<=9){
			if(smallSum==0){
				arr[i]=0;
			} else {
				arr[i]=smallSum;
				smallSum=0;
			}
		} else {
			arr[i]=9;
			smallSum=smallSum-9;
		}
		//cout << arr[i] << endl;
	}
	arr[0]=smallSum+1;
	for(int i=0; i<d; i++)
		cout << arr[i];
	cout << endl;
}
