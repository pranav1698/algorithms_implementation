#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int s[n];
	int t[n];
	string s1;
	cin >> s1;
	for(int i=0;i<n;i++){
		s[i] = s1[i] - '0';
	}
	string s2;
	cin >> s2;
	for(int i=0; i<n;i++){
		t[i] = s2[i] - '0';
	}
	int count=0;
	int cost=0;
	while(count < n){
		if(s[count] == t[count]){
			count++;
			continue;
		} else {
			// cout << s[count] << " " << t[count] << endl;
			if((count+1) < n){
				if(s[count] != s[count+1] && s[count+1] != t[count+1]){
					cost++;
					count = count+2;
				} else {
					cost++;
					count = count+1;
				}
			} else {
				cost++;
				count = count+1;
			}
		}
	}
	cout << cost << endl;
	return 0;
}
