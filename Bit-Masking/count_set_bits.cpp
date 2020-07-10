// Counting set bits in a number
// SlothyCoder16
// July 10, 2020

#include <bits/stdc++.h>
using namespace std;

// Kerninghan's Algorithm to count set bits
// Steps:
//   First - Create a count and set it to zero
//   Second - Bitwise AND x and x-1 and store the result in x
//   Third - Increase the count by 1
//   Fourth - Goto Second step until value of x is not equal to 0

int countSetBits(int x) {
  int count =0;
  while(x!=0) {
    count += 1;
    x = x & (x-1);
  }

  return count;
}

int main() {
  int x;
  cin >> x;
  cout << countSetBits(x) << endl;
}
