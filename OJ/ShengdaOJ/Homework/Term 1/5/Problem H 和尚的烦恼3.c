//宇龙小姐的手笔
#include <stdio.h>
int main() {
  int i, n, year, flag;
  scanf("%d", &n);
  while (n--) {
    flag = 0;
    scanf("%d", &year);
    for (i = year;; i++) {
      if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) flag++;
      if (flag == 15) {
        printf("%d\n", i);
        break;
      }
    }
  }
  return 0;
}