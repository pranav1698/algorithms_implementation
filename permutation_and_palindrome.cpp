// Important
#include<bits/stdc++.h>
using namespace std;

char getChar(int i){
	return (char)(i+97);
}

void printPalindromicString(string s){
	map<char, vector<int>> indexes;
	for(int i=0; i<s.length(); i++)
		indexes[s[i]].push_back(i);

	int odd_freq = 0;
	for(int i=0; i<26; i++){
		if((indexes[getChar(i)] % 2) != 0){
			odd_freq++;
		}
	}
	if(odd_freq >= 2){
		cout << "-1";
		return;
	}
	int ans[s.length()];
	int start=0;
	int end=n-1;
	for(int i=0; i<26; i++){
		char currentChar = getChar(i);
		for(int j=0; j< indexes[currentChar].size(); j+=2){
			if((indexes[currentChar].size() - j) == 1){
				ans[s.length() / 2] = indexes[currentChar][j];
				continue;
			}
			ans[start] = indexes[currentChar][j];
			ans[end] = indexes[currentChar][j];
			start++;
			end--;
		}
	}
	for(int i=0; i<s.length(); i++){
		cout << ans[i] + 1;
	}

	return;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		printPalindromicString(s);
		cout << endl;
	}
	return 0;
}