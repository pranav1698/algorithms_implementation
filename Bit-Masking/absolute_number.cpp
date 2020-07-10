// Absolute value of a number using bitwise operation
// SlothyCoder16
// July 10, 2020

#include <bits/stdc++.h>
using namespace std;

int absValue(int x) {
  const int bit31 =  x >> 31;
  return (x ^ bit31) - bit31;
}

int main() {
  cout << absValue(-32) << endl;
}
