#include <iostream>
#include <cstdio>

using namespace std;

int main() {
  int m, n, sum = 0;
  scanf("%d", &m);
  while (m--) {
    scanf("%d", &n);
    sum += n;
  }
  if (sum % 2 == 0)
    printf("bqp");
  else
    printf("ddd");
  return 0;
}