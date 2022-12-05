#include <math.h>
#include <stdio.h>
#include <string.h>

int main() {
  int n, m, flag = 1, k = 1;
  int a[100100], b[100100];
  scanf("%d%d", &n, &m);

  if (n > m) flag = 0;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
  for (int i = 1; i <= m; i++)
    if (a[k] == b[i]) k++;
  if (k < n) flag = 0;
  if (n == 1 && k != 2) flag = 0;
  if (flag) printf("Yes");
  if (!flag) printf("No");
  if (m == 0 && n == 0) flag = 0;
  return 0;
}