/**
 * \link: https://vjudge.csgrandeur.cn/problem/LightOJ-1236
 * \category: 数学 定理
 * 
 * 
 * \details: Attemped
*/
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;
const int kN = 1e7 + 1;
int n;

long long pairsFormLCM(int n, int lcd[kN][kN]) {
  long long res = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      if (lcd[i][j] == n)  // lcm表示最小公倍数
        res++;
    }
  }
  return res;
}

int main() {
  cin >> n;   
  int lcd[kN][kN]; 
  for (int i = 1; i < kN; ++i)
    for (int j = i; j < kN; ++j)
      lcd[kN][kN] = (i * j) / __gcd(i, j);
  for (int i = 0; i < n; i++) {
    int a; cin >> a;
    long long x = pairsFormLCM(a, lcd);
    cout << x << endl;
  }
  return 0;
}
