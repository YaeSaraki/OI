#include <iostream>
#define MAXN 1001001
using namespace std;

int a[MAXN];

int main() {
  int n, m;
  scanf("%d%d", &n,&m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    a[i] += a[i - 1];
  }
  int o, p;
  while (m--) {
    scanf("%d%d", &o, &p);
    printf("%d", a[p] - a[o - 1]);
  }
  return 0;
}