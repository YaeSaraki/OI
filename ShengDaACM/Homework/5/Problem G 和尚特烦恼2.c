//宇龙小姐的手笔
#include <math.h>
#include <stdio.h>
int F(int n) {
  int k = sqrt(n);
  for (int i = 2; i <= k; i++) {
    if (n % i == 0) return 1;
  }
  return 0;
}
int main() {
  int n, m;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int flat = 0;
    scanf("%d", &m);
    for (int i = 2;; i++) {
      if (F(i) == 0) flat++;
      if (flat == m) {
        printf("%d\n", i);
        break;
      }
    }
  }
  return 0;
}