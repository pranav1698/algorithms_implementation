#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
  int t[n];
  int s[n];
  for(int i=0; i<n; i++){
    s[i] = i+1;
    cin >> t[i];
  }
  int cost=0;
  for(int i=0;i<n;i++){
    if(t[i] > s[i]){
      if((t[i]-s[i]) > 2){
        cout << "NO" << endl;
        return 0;
      }
      cost = cost + (t[i]-s[i]);
    } else {
      if((s[i] - t[i]) > 2){
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;
  cout << cost << endl;

  return 0;
}
