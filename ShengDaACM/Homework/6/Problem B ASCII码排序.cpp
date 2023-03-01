#include <bits/stdc++.h>
using namespace std;

int main() {
  char a, b, c;
  while (~scanf("%c %c %c", &a, &b, &c)) {
    getchar();
    if (b < a) swap(a, b);
    if (c < a) swap(a, c);
    if (c < b) swap(c, b);

    printf("%c %c %c\n", a, b, c);
  }
  return 0;
}