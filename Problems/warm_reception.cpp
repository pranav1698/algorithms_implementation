#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int arrival[n];
	int departure[n];

	for(int i=0; i<n; i++){
		arrival[i]=0;
		cin >> arrival[i];
	}
	for(int i=0; i<n; i++){
		departure[i]=0;
		cin >> departure[i];
	}
	sort(arrival, arrival+n);
	sort(departure, departure+n);

	int max=0;
	int count=0;
    int j=0;
	for(int i=0; i<n; i++){
        while(j<n){
			if(arrival[i] > departure[j]){
				count= count - 1;
                j++;
			} else {
				break;
			}
		}
		count = count + 1;
        if(max < count)
			max=count;
	}

	cout << max << endl;
}