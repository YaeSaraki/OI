#include <stdio.h>

int main() {
  int year, n;
  scanf("%d", &n);
  while (n--) {
    scanf("%*6d%4d%*8d", &year);
    if (1922 <= year && year <= 1948) printf("新民主主义革命时期\n");
    else if (1950 <= year && year <= 1977) printf("社会主义革命和建设时期\n");
    else if (1979 <= year && year <= 2011) printf("改革开放和社会主义现代化建设新时期\n");
    else printf("中国特色社会主义新时代\n");
  }
  return 0;
}