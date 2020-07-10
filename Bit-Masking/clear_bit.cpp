// Clearing set bit
// SLothyCoder16
// July 10, 2020

#include <bits/stdc++.h>
using namespace std;

int clear_bit(int x, int position) {
  int mask = 1 << position;
  return x & (~mask);
}

int main() {
  cout << clear_bit(6, 2) << endl;
}
