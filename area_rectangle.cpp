#include<bits/stdc++.h>
using namespace std;

int main() {

	int x1,y1,x2,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int x3,y3,x4,y4;
	cin >> x3 >> y3 >> x4 >> y4;

	int arr1 = (y2 - y1) * (x2 - x1);
	int arr2 = (y4 - y3) * (x4 - x3);

	int left_inter = std::max(x3, x1);
	int right_inter = std::min(x2, x4);
	int botom_inter = std::max(y1, y3);
	int top_inter = std::min(y2, y4);

	if ((botom_inter < top_inter) && (left_inter < right_inter)) {
		int Ain = (right_inter - left_inter) * (top_inter - botom_inter);
		int ans = (arr1 + arr2 - Ain);
		cout << ans << endl;
	} else {
		int ans = (arr1 + arr2);
		cout << ans << endl;
	}

	return 0;
}	