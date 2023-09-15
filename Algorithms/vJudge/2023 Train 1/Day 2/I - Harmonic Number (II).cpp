/**
 * \link: https://vjudge.csgrandeur.cn/problem/LightOJ-1245
 * \category: 数学定理
 * 
 * 
 * 
*/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
  long long t;
  long long T;
  scanf("%lld", &T);
  int j = 1;
  while (T--) {
    long long n;
    cin >> n;
    t = 0;
    int a = sqrt(n);
    for (long long i = 1; i <= a; i++) {
      t += n / i + (n / i - n / (i + 1)) * i;
    }
    if (n / a == a) t -= a;
    cout << "Case " << j++ << ": " << t << endl;
  }
  return 0;
}