#include <math.h>
#include <string.h>

#include <cstdio>
#include <iostream>
using namespace std;

char a[50];

int main() {
  int T, len;
  long long n;
  scanf("%d", &T);
  while (T--) {
    n = 0;
    scanf("%s", a);
    len = strlen(a);
    for (int i = 0; i < len; i++) n = n * 2 + (a[i] - '0');
    printf("%lld\n", n);
  }

  return 0;
}