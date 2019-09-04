// Partially correct answer
#include<bits/stdc++.h>
using namespace std;

int get_count(int* arr, int n){
  int count=0;
  for(int i=0; i<n; i++){
    while(i<n-1 && arr[i]==arr[i+1])
      i++;
    count++;
  }
  return count-1;
}

int main() {
  int n,k,l;
  cin >> n >> k >> l;
  int arr[n];
  for(int i=0; i<n; i++)
    cin >> arr[i];

  int cost1 = 0;
  int cost2 = 0;

  sort(arr, arr+n);
  int max = arr[n-1];
  for(int i=0;i<n-1;i++){
    int num=arr[i];
    while(num<max){
      num++;
      cost2 = cost2 + l;
    }
  }

  int count=get_count(arr, n);


  while(count!=0){
    if(count == 1){
      int equalize=arr[n-1];
      for(int i=0; i<n && arr[i]!=equalize; i++){
          while(arr[i] < equalize){
            arr[i]++;
            cost1 = cost1 + l;
          }
      }
      count = get_count(arr,n);
    } else {
      arr[0] = arr[0] + 1;
      arr[n-1] = arr[n-1] - 1;
      sort(arr, arr+n);
      cost1 = cost1 + k;
      count = get_count(arr, n);
    }
  }

  int cost = min(cost1, cost2);
  cout << cost1 << " " << cost2 << endl;
  cout << cost << endl;
}
