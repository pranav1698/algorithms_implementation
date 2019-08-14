#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m,p;
	cin >> n >> m >> p;

	vector<int> input;
	for(int i=0; i<n; i++){
		int a;
		cin >> a;
		input.push_back(a);
	}
	for(int i=0; i<m; i++){
		int a;
		cin >> a;
		input.push_back(a);
	}
	for(int i=0; i<p; i++){
		int a;
		cin >> a;
		input.push_back(a);
	}

	map<int, int> voters_map;
	for(int i=0; i<input.size(); i++)
		voters_map[input[i]]=voters_map[input[i]]+1;

	map<int, int>::iterator it;
	vector<int> result;
	for(it=voters_map.begin();it!=voters_map.end();it++){
		if(it->second >= 2){
			result.push_back(it->first);
		}
	}	
	cout << results.size() << endl;
	for(int i=0; i<result.size(); i++)
		cout << result[i] << endl;
	return 0;
}