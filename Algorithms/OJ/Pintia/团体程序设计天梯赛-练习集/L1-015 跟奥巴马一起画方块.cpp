#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  int x; cin >> x;
  char ch; cin >> ch;
  int y = ceil(((double)x / 2));
  for (int i = 0; i < y; ++i) {
    for (int j = 0; j < x; ++j) cout << ch;
    cout << '\n';
  }
  return 0;
}