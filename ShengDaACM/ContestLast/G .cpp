#include <stdio.h>

int OrderedNumber(int n) {
  int g = n % 10;
  int s = n / 10 % 10;
  int b = n / 100;
  if (g > s && s > b) return 1;
  if (b > s && s > g) return 1;
  return 0;

}

int main(void) {
  int m, n, i;
  scanf("%d", &m);
  while (m--) {
    scanf("%d", &n);
    if (OrderedNumber(n) == 1)
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}