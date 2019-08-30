// Important for memory overflow
#include<bits/stdc++.h>
using namespace std;
int main()
{
    //Write your code here
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
    	cin >> arr[i];
    sort(arr, arr+n, greater<int>());
    long long sum=0;
    for(int i=0; i<n; i++){
    	sum = sum + (arr[i] * (1LL << i));
    }
    cout << sum << endl;
    return 0;
}