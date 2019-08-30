// Good Greedy Problem
#include<bits/stdc++.h>
using namespace std;

int getNoOfActivities(vector<pair<int,int>> pairs){
	int start=pairs[0].first;
	int finish=pairs[0].second;
	int count=1;
	for(int i=0; i<pairs.size(); i++){
		//cout << finish << endl;
		if(finish <= pairs[i+1].first){
			count++;
			finish=pairs[i+1].second;
		}
	}
	return count;
}

bool cmp(pair<int, int> p1, pair<int, int> p2){
	return p1.second < p2.second;
}

int main()
{
    //Write your code here
	int n;
	cin >> n;
	vector<pair<int, int>> pairs;
	for(int i=0; i<n; i++){
		int start, end;
		cin >> start >> end;
		pair<int, int> p=make_pair(start, end);
		pairs.push_back(p);
	}
	sort(pairs.begin(), pairs.end(), cmp);
	int count = getNoOfActivities(pairs);
    cout << count << endl;
    return 0;
}