#include <stdio.h>

int FacSum(int n);

int main() {
  int n;
  scanf("%d", &n);
  printf("%d", FacSum(n));
  return 0;
}

int FacSum(int n) {
  int sum = 0;
  for (int i = 1; i < n; i++) {
    if (n % i == 0) sum += i;
  }
  return sum;
}