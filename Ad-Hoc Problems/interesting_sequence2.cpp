// Great Adhoc approach Very Important
#include<bits/stdc++.h>
using namespace std;

int cost_each(int* arr, int n, int pivot, int k, int l){
  int inc=0;
  int decr=0;
  for(int i=0; i<n; i++){
    if(arr[i] < pivot){
      inc = inc + (pivot - arr[i]);
    } else {
      decr = decr + (arr[i] - pivot);
    }
  }
  //cout << inc << " " << decr << endl;
  int cost=0;
  if(inc >= decr){
    cost += decr * k;
    cost += (inc - decr) * l;
  } else {
    cost = INT_MAX;
  }
  return cost;
}

int main() {
  int n,k,l;
  cin >> n >> k >> l;
  int arr[n];
  for(int i=0; i<n; i++)
    cin >> arr[i];

  sort(arr,arr+n);
  int res=INT_MAX;
  //cout << arr[0] << " " << arr[n-1] << endl;
  for(int i=arr[0]; i<=arr[n-1]; i++){
    int cost= cost_each(arr, n, i, k, l);
    res = min(cost, res);
  }

  cout << res << endl;
}
