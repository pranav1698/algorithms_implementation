// Finding if bit set
// SLothyCoder16
// July 10, 2020

#include <bits/stdc++.h>
using namespace std;

int isBitSet(int x, int position) {
  int shifted = x >> position;
  return shifted & 1;
}


int main() {
  cout << isBitSet(2, 2) << endl;
}
