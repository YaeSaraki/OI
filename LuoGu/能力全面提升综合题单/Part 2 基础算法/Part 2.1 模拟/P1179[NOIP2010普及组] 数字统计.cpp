#include <iostream>
using namespace std;

int main() {
  int a, b, c, sum = 0;
  cin >> a >> b;
  for (int i = a; i <= b; i++) {
    c = i;
    while (c) {
      if (c % 10 == 2) sum++;
      c /= 10;
    }
  }
  cout << sum;
  return 0;
}