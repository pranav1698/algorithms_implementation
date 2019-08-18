// Important
#include<bits/stdc++.h>
using namespace std;


int timeTaken(vector<pair<int,int>> intervals, int current){
	
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n,m; //n intervals m current times
		cin >> n >> m;
		vector<pair<int, int>> intervals;
		for(int i=0; i<n; i++){
			int start, end;
			cin >> start >> end;
			intervals.push_back(make_pair(start, end));
		}
		sort(intervals.begin(), intervals.end());
		
		for(int i=0; i<m; i++){
			int current;
			cin >> current;
			int position = lower_bound(intervals.begin(), intervals.end(), make_pair(current,0)) - intervals.begin();
			if(position == 0){
				int ans=intervals[0].first - current;
				cout << ans << endl;
			} else {
				int ans=-1;
				if(intervals[position-1].second > current){
					ans=0;
				} else if(position < intervals.size()) {
					ans=intervals[position].first - current;
				}
				cout << ans << endl;
			}
		}
	}
}