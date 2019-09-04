#include<bits/stdc++.h>
using namespace std;

// int num_codes(int* n, int size){
//   if(size == 1)
//     return 1;
//   if(size == 0)
//     return 1;
//   int output = num_codes(n, size-1);
//   if((output[size-2]*10 + output[size-1]) <= 26)
//     output += num_codes(n, size-2);
//   return output;
// }
//
// int num_codes2(int* n, int size, int* arr){
//   if(size == 1)
//     return 1;
//   if(size == 0)
//     return 1;
//   if(arr[size] > 0)
//     return arr[size];
//
//   int output = num_codes(n, size-1);
//   if((output[size-2]*10 + output[size-1]) <= 26)
//     output += num_codes(n, size-2);
//   arr[size]=output;
//   return output;
// }

int num_codesi(int* input, int size){
  int* output=new int[size+1];
  output[0]=1;
  if(input[0]!=0){
    output[1]=1;
  } else {
    output[1]=0;
  }

  for(int i=2; i<=size; i++){
    if(input[i-1] != 0){
      output[i] = output[i-1];
      if((input[i-2]*10 + input[i-1]) <= 26)
        output[i] += output[i-2];
    } else {
      output[i]=0;
    }
  }
  int mod=(int)(pow(10,9) + 7);
  int ans = (int)(output[size]) % mod;
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
