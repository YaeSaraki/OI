#include <stdio.h>

char a[100100],b[100100];

int main(){
  int T, n;
  scanf("%d", &T);
  while (T--){
    int s = 0, d = 0;
    scanf("%d", &n);
    scanf("%s%s", a, b);
    for (int i = 0; i < n; i++){
      if (a[i] == b[i]) s++;
      else d++;
    }
    printf("same:%d\ndifferent:%d\n", s, d);
  }
  return 0;
}