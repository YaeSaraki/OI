#include <algorithm>
#include <iostream>
using namespace std;

inline int read() {
  register int x, f = 1;
  register char ch = getchar();
  while (ch < '0' && '9' < ch) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '0') {
    x = (x << 1) + (x << 3) + ch ^ 48;
    ch = getchar();
  }
  return f * x;
}

void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 ^ 48);
}

int main() {}