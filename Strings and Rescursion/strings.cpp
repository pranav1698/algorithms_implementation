#include <bits/stdc++.h>
using namespace std;

void remove_x(char* s){
	if(s[0] == '\0')
		return;
	if(s[0] == 'x'){
		int i=1;
		for(; s[i]!='\0'; i++)
			s[i-1] = s[i];
		s[i-1] = s[i];
		remove_x(s);
	} else {
		remove_x(s+1);	
	}
	
}

int length(char s[]){
	if(s[0] == '\0')
		return 0;
	int shortString=length(s+1);
	return 1  + shortString;
}

int main(){
	char str[100];
	cin >> str;

	int l = length(str);
	cout << l << endl;

	remove_x(str);
	cout << str << endl;
	cout << length(str) << endl; 
}