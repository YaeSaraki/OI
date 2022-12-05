#include <cstdio>
#include <iostream>
#include <cstring>

char a[200100];

int main() {
  int sum = 0;
  scanf("%s", a);
  int len = strlen(a);
  for (int i = 0; i < len - 6; i++) {
    if (a[i] == 'y' && a[i + 1] == 'l' && a[i + 2] == 'n' && a[i + 3] == 'y' &&
        a[i + 4] == 'w' && a[i + 5] == 'y' && a[i + 6] == 's')
      sum++;
  }
  printf("%d", sum);
  return 0;
}
