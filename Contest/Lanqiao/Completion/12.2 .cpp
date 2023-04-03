#include <iostream>
using namespace std;
#define F(i) for (int i = 1; i < 10; ++i)

int main() {
  F(a) F(b) F(c) F(d) F(e) {
    for (int i = 2; i < 10; ++i) {
      if ((a * 10000 + b * 1000 + c * 100 + d * 10 + e) * i ==
          (e * 10000 + d * 1000 + c * 100 + b * 10 + a)) {
        cout << a << b << c << d << e << endl;
      }
    }
  }
  return 0;
}