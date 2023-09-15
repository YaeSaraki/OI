#include <stdio.h>
#include <string.h>

void bc(char a[], char b[]);

int main() {
  char a[5], b[5];
  gets(a), gets(b);
  //  puts(a), puts(b);
  bc(a, b);
  return 0;
}

void bc(char a[], char b[]) {
  int bsum = 0, csum = 0;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++) {
      if (i == j) {
        if (a[i] == b[i]) {
          bsum++;
          a[i] = -1, b[i] = -2;
        }
        continue;
      }
      if (b[j] == a[i]) {
        a[i] = -1;
        csum++;
        break;
      }
    }
  printf("%d %d", bsum, csum);
}
