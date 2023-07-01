#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

void check(int x) {
  for (int i = 20; i >= 0; --i) {
    if (pow(2,i) <= x) {
      if (i == 1) {
        cout << 2;
      } else if (i == 0) {
        cout << "2(0)";
      } else {
        cout << "2(";
        check(i);
        cout << ")";
      }
      x -= pow(2, i);
      if (x) cout << "+";
    }
  }
  return ;
}

int main() {
  int x; cin >> x;
  check(x);
  return 0;
}