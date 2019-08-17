//Important
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool checkValidity(ll* stall, ll n, ll middle, ll c){
	ll count=1;
	ll curr=stall[0];
	for(ll i=1; i<n; i++){
		if((stall[i] - curr) >= middle){
			count=count+1;
			curr=stall[i];
        }
        if(count == c){
        	return true;
        }
	}
	return false;
}

int main() {
	int t;
	cin >> t;
	int s, c;
	cin >> s >> c;
	ll stall[s];
	while(t--){
		for(ll i=0; i<s; i++){
			stall[i]=0;
			cin >> stall[i];
		}
		sort(stall, stall+s);
		ll start=0;
		ll end=stall[s-1] - stall[0];
		ll ans=-1;
		while(start<=end){
			ll mid=(end + start)/2;
			if(checkValidity(stall, s, mid, c)){
				ans=mid;
				start=mid+1;
			} else {
				end=mid-1;
			}
		}
		cout << ans << endl;
	}
}