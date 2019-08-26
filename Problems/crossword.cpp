#include<bits/stdc++.h>
using namespace std;

int main() {
	char grid[10][10];
	for(int i=0;i<10;i++){
		string s;
		cin >> s;
		for(int j=0; j<10;j++){
			grid[i][j]=s[j];
			//cout << grid[i][j] << endl;
		}
	}

	string str;
	cout << str << endl;
	getline(cin, str);
	cout << str << endl;
}