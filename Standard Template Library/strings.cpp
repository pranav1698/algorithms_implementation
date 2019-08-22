#include<bits/stdc++.h>
#include<string>
using namespace std;

int main(){
	// string* sp= new string;
	// *sp="def";
	// cout << sp << " " << *sp << endl;

	string s = "Pranav";

	// string s1(s, 2, 4);
	// cout << s << endl;
	// cout << s1 << endl;

	string s2 = s.substr(1,4);
	string s4 = s.substr(3);
	cout << s2 << " " << s4 << endl;
	cout << s2[0] << endl;
	string s3;
	getline(cin, s3);
	cout << s3 << endl;

	// string s4=s+s1;
	// cout << s4 << endl;

	// if(s1.compare(s2) == 0){
	// 	cout << s1 <<" is equal to " << s2 << endl;
	// } else {
	// 	cout << s1 <<" is not equal to " << s2 << endl;
	// }
	// return 0;

	cout << s3.size() << endl;
	cout << s3.length() << endl;

	cout << s.find("def") << endl;

}