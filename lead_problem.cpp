//Important
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int p1[n], p2[n];
	for(int i=0; i<n; i++){
		int cs1, cs2;
		cin >> cs1 >> cs2;
		p1[i] = cs1;
		p2[i] = cs2;
	}
	int s1[n], s2[n], lead[n];
	for(int i = 0; i < n; i++){
		s1[i] = 0;
		s2[i] = 0;
		for(int j = 0; j <= i; j++){
			s1[i] += (p1[j]);
			s2[i] += p2[j];
		}
		lead[i] = s1[i] - s2[i];
	}
	int max = 0, index;
	for(int i = 0; i < n; i++){
		if(abs(lead[i]) > max){
			max = abs(lead[i]);
			index = i;
		}
	}
	if(lead[index] > 0){
		cout << 1 << " " << max;
	} else {
		cout << 2 << " " << max;
	}
	return 0;
}