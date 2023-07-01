/**
 * \link: https://vjudge.csgrandeur.cn/problem/HDU-6575
 * \\category: 思维
 * 
 * 
 * 
 * 
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (~scanf("%d", &n)) {
    double sum = 0;
    for (int i = 1; i <= n; i++) {
      string s;
      cin >> s;
      if (s[s.size() - 1] <= '4') {
        sum -= s[s.size() - 1] - '0';

      } else
        sum += 10 - (s[s.size() - 1] - '0');
    }
    printf("%.3lf\n", sum / 1000);
  }

  return 0;
}
