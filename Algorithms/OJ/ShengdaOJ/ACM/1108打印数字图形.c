#include <stdio.h>
void PrintLine(int n) {
  int i, j;
  for (i = 1; i < 2 * n; i++) {
    if (i <= n) {
      for (j = 1; j <= n - i; j++)
        printf(" ");  //先处理空格的问题，这是输出空格的操作
      for (j = 1; j <= i; j++)
        printf("%d", j);  //这些是第 i 行第 i 个数前面的数，正常输出就行咧
      for (j = i - 1; j > 0; j--)
        printf("%d", j);  //这些就是第 i +1个数的输出情况，倒着输出这些数就行咧
    } else {
      for (j = 1; j <= i - n; j++) printf(" ");  //处理空格的操作
      for (j = 1; j <= 2 * n - i; j++)
        printf("%d", j);  //这些是第n+1行以后的数的操作
      for (j = (2 * n - i - 1); j > 0; j--) printf("%d", j);
    }
    printf("\n");  //每输完一行，都要进行换行
  }
}
int main() {
  int n;
  scanf("%d", &n);
  PrintLine(n);
  return 0;
}