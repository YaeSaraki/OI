
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

bool isprime[100100100]; // 是否为素数
int p[100100]; // 素数表

void prime(int n) {
  int t = sqrt(n) + 1;
  for (int i = 2; i <= t; ++i) {
    if (isprime[i] == 0) {
      for (int j = i * 2; j <= n; j += i) isprime[j] = 1;
    }
  }
}

int main() {
  int n; cin >> n;
  prime(n);
  int j = 1;
  for (int i = 2; i < n; ++i) {
    if (isprime[i] == 0) p[j++] = i; 
  }
  int T; cin >> T; while(T--) {
    int m; scanf("%d", &m);
    printf("%d \n", p[m]);
  }
  return 0;
} 