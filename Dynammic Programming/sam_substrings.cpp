#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

// Complete the substrings function below.
int substrings(string n) {
  int* output = new int[n.size()];
  for(int i=0; i<n.size(); i++)
      n[i] = n[i] - '0';

  output[0] = n[0];

  //cout << n.size() << endl;
  for(int i=1; i<n.size(); i++){
    output[i] = ((output[i-1]*10)%mod + (n[i]*(i+1))%mod)%mod;
  }

  int sum=0;
  for(int i=0; i<n.size(); i++){
    sum = (sum + output[i]) % mod;
  }

  return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n;
    getline(cin, n);

    int result = substrings(n);

    cout << result << "\n";

    fout.close();

    return 0;
}
