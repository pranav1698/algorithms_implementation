#include <bits/stdc++.h>
using namespace std;

int getIndices(int* input, int size, int x, int* output, int count, int length){
    if(size == 0){
        return count;
    }
    if(input[0] == x){
        output[count]=length-size;
        count=count+1;
    }
    getIndices(input+1, size-1, x, output, count, length);

}


int allIndexes(int input[], int size, int x, int output[]) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Save all the indexes in the output array passed and return the size of output array.
     Taking input and printing output is handled automatically.
  */
  int count = getIndices(input, size, x, output,0,size);
  return count;
}

int main(){

}
