// Solution for s < 50
#include<bits/stdc++.h>
using namespace std;
int main() {
	long s,d;
	cin >> s >> d;
	long max=pow(10,d)-1;
	for(int i=1; i<=9; i++){
		long start = i*pow(10,d-1);
		long end = max - ((9-i)*pow(10,d-1));
		while(start <= end){
			long sum=0;
			long curr=start;
			while(curr>0){
				sum = sum + (curr%10);
				curr = curr / 10;
			}
			if(sum == s){
				cout << start << endl;
				return 0;
			}
			start++;
		}
	}
}