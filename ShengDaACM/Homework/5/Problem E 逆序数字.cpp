#include <stdio.h>

int inverse(int n);

int main() {
  int n;
  scanf("%d", &n);
  printf("%d", n + inverse(n));
  return 0;
}

int inverse(int n)  // NEW!!!!
{
  int isum = 0;
  while (n != 0) {
    isum = isum * 10 + n % 10;
    n /= 10;
  }
  return isum;
}