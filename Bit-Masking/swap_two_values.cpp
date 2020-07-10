// Swap two variables
// SlothyCoder16
// July 10, 2020

#include <bits/stdc++.h>
using namespace std;

void swap(int a, int b) {
  a = a ^ b;
  b = b ^ a;
  a = a ^ b;

  cout << a << " " << b << endl;
}

int main() {
  swap(4,5);
}
