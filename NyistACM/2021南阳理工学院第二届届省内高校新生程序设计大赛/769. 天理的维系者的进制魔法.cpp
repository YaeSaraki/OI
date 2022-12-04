#include <cstdio>
#include <iostream>

char a[50];

int main() {
  int m, out, len, t;
  scanf("%d", &m);
  getchar();
  while (m--) {
    out = 0, t = 1;
    scanf("%s", a);
    len = strlen(a);
    puts(a);
    printf("%d", len);
    for (int i = len; i <= 0; i--) {
      out += (a[i] - '0') * t;
      t *= 2;
    }
    printf("%d\n", out);
  }
  return 0;
}