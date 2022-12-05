#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int year, month, day;
    scanf("%*6d%4d%2d%2d%*4d", &year, &month, &day);
    printf("%d-%02d-%02d\n", year, month, day);
  }
  return 0;
}