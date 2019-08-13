#include<bits/stdc++.h>
#include<utility>
using namespace std;

int main(){
	pair<int, char> p;
	pair<int, char> p2(1,'a');
	p = make_pair(2, 'b');

	cout << p.first << " " << p.second << endl;
	cout << p2.first << " " << p2.second << endl;
	return 0;
}