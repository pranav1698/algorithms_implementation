#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int num_codesi(int* input, int size){
  int* output = new int[size+1];
  output[0]=1;
  for(int i=1; i<=size; i++){
    if(input[i-1] != 0){
      output[i]=output[i-1];
    } else {
      output[i]=0;
    }
    if(i > 1){
      int x=input[i-2]*10 + input[i-1];
      if((x>=10 && x<=26) && i>2){
        output[i] += output[i-2];
      } else if(x>=10 && x<=26) {
        output[i]++;
      }
    }
    //cout << output[i] << endl;
  }
  //int mod=pow(10,9) + 7;
  int ans=(int)(output[size]%mod);
  delete [] output;
  return ans;
}


int main() {
  string input;
  cin >> input;
  while(input != "0"){
    int* arr = new int[input.size()];
    for(int i=0; i<input.size(); i++)
      arr[i]=input[i]-'0';

    cout << num_codesi(arr, input.size()) << endl;
    cin >> input;
  }
  return 0;
}
