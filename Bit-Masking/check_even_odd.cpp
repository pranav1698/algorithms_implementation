#include <bits/stdc++.h>
using namespace std;

void checkOddEven(int n){
	int Z=1 << 0;
	if((n & Z) == 0){
		cout << "even" << endl;
	} else {
		cout << "odd" << endl;
	}
}

int main(){
	checkOddEven(2);
}