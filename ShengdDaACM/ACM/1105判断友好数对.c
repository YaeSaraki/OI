#include <stdio.h>

int FacSum(int n);

int main() {
  int m, n, flag = 0;
  scanf("%d%d", &m, &n);
  for (int i = m; i <= n; i++) {
    int a = FacSum(i);
    if (i == FacSum(a) && i < a)  // i不能等于a
    {
      printf("%d %d\n", i, a);
      flag = 1;
    }
  }
  if (flag == 0) printf("No answer");
  return 0;
}

int FacSum(int n) {
  int sum = 0;
  for (int i = 1; i < n; i++) {
    if (n % i == 0) sum += i;
  }
  return sum;
}