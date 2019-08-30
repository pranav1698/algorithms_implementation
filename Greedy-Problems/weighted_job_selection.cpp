// Very Important
#include<bits/stdc++.h>
using namespace std;


struct Job{
	int s, f, p;
};

int binarySearch(Job arr[], int curr, int lo, int hi){
	int ln = -1;
	while(lo <= hi){
		int mid = lo + (hi - lo) / 2;
		if(arr[mid].f <= arr[curr].s){
			if(arr[mid+1].f <= arr[curr].s){
				lo = mid+1;
			} else{
				return mid;	
			}
		} else {
			hi= mid-1;
		}
	}
	return ln;
}

bool compare(struct Job a, struct Job b){
	return a.f < b.f;
}

int maximumProfit(Job arr[], int n){
	sort(arr, arr+n, compare);
	int* dp = new int[n];
	dp[0]=arr[0].p;
	for(int i=1; i<n; i++){
		int including = arr[i].p;
		int lnConflict = binarySearch(arr, i, 0, i-1);


		if(lnConflict != -1){
			including += dp[lnConflict];
			//cout << including << endl;
		}
		dp[i] = max(including, dp[i-1]);
	}
	int ans = dp[n-1];
	delete[] dp;
	return ans;
}

int main(){
	int n;
	cin >> n;
	Job arr[n];
	for(int i=0; i<n; i++){
		int s, f, p;
		cin >> s >> f >> p;
		arr[i]={s,f,p};
	}
	cout << maximumProfit(arr, n) << endl;
}