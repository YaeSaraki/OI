#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int a[10] = {0};
  for (auto &it : a) it = 2021;
  for (int i = 1;; ++i) {
    int t = i;
    while (t) {
      --a[t % 10];
      if (!a[t % 10]) { cout << i; return 0; }
      t /= 10;
    }
  }
  return 0;
}