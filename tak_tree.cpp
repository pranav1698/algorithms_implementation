#include<bits/stdc++.h>
using namespace std;

bool canDistributeEqually(int fruits){
	if (fruits % 11 != 1){
		return false;
	} else {
		return true;
	}
}

int main() {
	int fruits;
	cin >> fruits;

	int days = 0;

	while(!canDistributeEqually(fruits)){
		days++;
		fruits = 2*fruits;
	}

	cout << days << " " << fruits << endl;
	return 0;
}