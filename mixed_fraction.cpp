#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, d;
	cin >> n >> d;

	int a = n / d;
	int b = n % d;

	if (b == 0) {
		cout << a << endl;
	} else {
		cout << a << " " << b << "/" << d << endl;
	}

	return 0;
}