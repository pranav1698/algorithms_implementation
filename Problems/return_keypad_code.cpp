// Very Important
#include <bits/stdc++.h>
using namespace std;

int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    map<int, string> m;
    string s= "abc";
    m[2]=s;
    s="def";
    m[3]=s;
    s="ghi";
    m[4]=s;
    s="jkl";
    m[5]=s;
    s="mno";
    m[6]=s;
    s="pqrs";
    m[7]=s;
    s="tuv";
    m[8]=s;
    s="wxyz";
    m[9]=s;

	if(num == 0 || num==1){
		output[0]="";
		return 1;
	}

	int smallNum = num / 10;
	int newNum = num % 10;
	string s1[500];
	string s2 = m[newNum];


	int smallSize = keypad(smallNum, s1);
	int i=0; int j=0;
	int k=0;
	while(i<smallSize){
		j=0;
		while(j<m[newNum].size()){
			output[k++] = s1[i] + s2[j++];
		}	
		i++;
	}
	// for(int i=0; i<smallSize; i++){
	// 	cout << s1[i] << " ";
	// }
	// cout << endl;
    return k;
}

int main(){
	int num;
	cin >> num;
	string* output= new string[1000];
	int count=keypad(num, output);
	for(int i=0; i<count; i++){
		cout << output[i] << endl;
	}
}
