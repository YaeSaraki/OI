#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int a = 1, b = 1, c = 1, temp;
  for (int i = 4; i <= 20190324; ++i) {
    temp = (a + b + c) % 10000;
    a = b;
    b = c;
    c = temp;
  }
  cout << c;
  return 0;
}