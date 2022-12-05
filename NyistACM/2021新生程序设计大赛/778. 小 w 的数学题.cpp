#include <bits/stdc++.h>

using namespace std;

int main() {
  int T, sum, a, t, n;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    sum = -1, a = 0, t = 1;
    while (t <= n) {
      a += 4;
      t += a;
      sum++;
    }
    printf("%d\n", sum);
  }
  return 0;
}

// bool book[MAXX];
// int T, sum = 0;
// int main() {
//   long long a, b, c = 0, n;
//   for (a = 1; a <= MAXX; a++)
//     for (b = a; b <= MAXX; b++) {
//       c = a * a - b;
//       if (c * c == b * b + a * a && c <= MAXX) book[c] = 1;
//     }
//   scanf("%d", &T);
//   while (T--) {
//     sum = 0;
//     scanf("%lld", &n);
//     for (int i = 1; i <= n; i++) sum += book[i];
//     printf("%d\n", sum);
//   }
//   return 0;
// }