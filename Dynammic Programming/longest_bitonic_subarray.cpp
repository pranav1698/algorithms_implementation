// Great DP Question
#include<bits/stdc++.h>
using namespace std;

int longestBitonicSubarray(int *input, int n) {
  int* output= new int[n];
  int* diff= new int[n];

  diff[0]=1;
  for(int i=1; i<n; i++){
    int length=1;
    for(int j=0; j<i; j++){
      if(input[j] < input[i]){
        int possibleLength = diff[j] + 1;
        length = max(length, possibleLength);
      }
    }
    diff[i] = length;
  }

  output[0]=1;
  for(int i=1; i<n; i++){
    int new_length=1;
    for(int j=0; j<i; j++){
      if(input[j] > input[i]){
        int new_possible_length=output[j] + 1;
        new_length = max(new_length, new_possible_length);
      } else if(input[j] < input[i]){
        int new_possible_length1 = diff[j] + 1;
        new_length = max(new_possible_length1, new_length);
      }
    }
    output[i] = new_length;
    //cout << output[i] << endl;
  }

  int best=0;
  for(int i=0; i<n; i++){
    best = max(best, output[i]);
  }

  return best;
}

int main(){
  int n;
  cin >> n;
  int arr[n];
  for(int i=0; i<n; i++)
    cin >> arr[i];
  cout << longestBitonicSubarray(arr,n) << endl;;
}
