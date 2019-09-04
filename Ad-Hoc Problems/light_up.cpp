#include<bits/stdc++.h>
using namespace std;
int main()
{
  long n, x, y;
  cin >> n >> x >> y;
  string s;
  cin >> s;
  int arr[s.size()];
  for(int i=0; i<s.size(); i++){
    arr[i]= s[i] - '0';
  }


  int count=0;
  if(arr[0] == 0){
    count++;
  }
  for(int i=0; i<n-1; i++){
    if(arr[i]==1 && arr[i+1]==0){
        count++;
    }
  }
  long cost=0;
  if(count>0)
    cost = ((count-1)*min(x,y)) + y;

  cout << count << endl;
  cout << cost << endl;
	return 0;
}
