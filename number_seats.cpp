#include<bits/stdc++.h>
using namespace std;

int main() {
	int rows, columns;
	int tickets;

	cin >> rows >> columns;
	int seats = rows * columns;
	cin >> tickets;

	if(seats >= tickets){
		cout << tickets << " " <<  0 << endl;
	} else {
		cout << seats << " " << (tickets - seats) << endl;
	}
	return 0;
}