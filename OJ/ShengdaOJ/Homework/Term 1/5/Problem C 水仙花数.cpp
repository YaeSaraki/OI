#include <math.h>
#include <stdio.h>
#include <iostream>

int Flower(int n) {
  if (n == pow(n % 10, 3) + pow((n / 10) % 10, 3) + pow(n / 100, 3)) return 1;
  return 0;
}

int main() {  //题目所给
  int i, m, n, c;
  while (scanf("%d%d", &m, &n) != EOF) {
    c = 0;
    for (i = m; i <= n; i++) {
      if (Flower(i) == 1) {
        printf("%d ", i);
        c++;
      }
    }
    if (c == 0) printf("no");
    printf("\n");
  }

  return 0;
}
