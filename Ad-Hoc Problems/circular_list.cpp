#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while(t--){
      int i,p;
      cin >> i >> p;
      int start;
      if(i == 11){
        start=0;
      } else {
        start=i+1;
      }
      int count=1;
      while(count < p){
        if(start==11){
          start=0;
          count++;
        } else{
          start++;
          count++;
        }
      }
      cout << start << endl;
  }
	return 0;
}
