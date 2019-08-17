#include<bits/stdc++.h>
using namespace std;

int main() {
    long t;
    cin >> t;
    for(long i=0;i<t; i++){
        long sum=0;
        long number;
        cin >> number;
        while(number > 0){
            sum=sum + (number%10);
            number = number / 10;
        }
        cout << sum << endl;
    }
	// Write your code here
}