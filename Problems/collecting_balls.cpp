#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int get_k(ll n, int k){
	ll total_balls=n;
	ll sharma_balls=0;
	ll singh_balls=0;
	ll half_balls=n/2;
	int ans;
	while(sharma_balls < half_balls && singh_balls < half_balls && n > 0){
		sharma_balls = sharma_balls + k;
		n = n-k;
		singh_balls = singh_balls + (n/10);
		n = n-(n/10);
	}
	if(sharma_balls >= half_balls){
		return k;
	} else {
		ans = get_k(total_balls, k+1);
	}
	return ans;
}

int main()
{
 	ll n;
 	cin >> n;
 	cout << get_k(n, 1) << endl;   
	return 0;
}
