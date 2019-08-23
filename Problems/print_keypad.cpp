// Very Important
#include <bits/stdc++.h>
#include <string>
using namespace std;

void keypad(int num, string output, string* options){
	if(num == 0 || num==1){
		cout << output << endl;
		return;
	}

	int smallNum = num/10;
	int newNum = num % 10;
	string smallString = options[newNum];
	
	for(int i=0; i<smallString.size(); i++){
		keypad(smallNum, string(1, smallString[i]) + output, options);
		// cout << string(1, smallString[i]) + output[0] << endl;
	}
}

void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
	string options[]={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	string output="";
	keypad(num, output, options);
    
}
int main(){
	int n;
	cin >> n;
	printKeypad(n);
}