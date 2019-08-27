#include<bits/stdc++.h>
using namespace std;

void checkPowerOf2(int n){
	if((n & (n-1)) == 0){
		cout << "true" << endl;
	} else {
		cout << "false" << endl;
	}
}

int main(){
	checkPowerOf2(15);
}