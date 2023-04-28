#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
bool isnprime[100100100];
void Prime(int n) {
  int t = sqrt(n) + 2;
  for (int i = 2; i < t; ++i) {
    if (!isnprime[i]) {
      for (int j = i * 2; j < n; j += i) isnprime[j] = true;
    }
  }
  return ;
}

bool IsPalindromes(int n) {
  int t = 0;
  for (int i = n; i != 0; i /= 10) {
    t = t * 10 + i % 10;
  }
  if (t == n) return true;
  return false;
}

int main() {
  int a, b;
  cin >> a >> b;
  if (b > 10010010) b = 10010010;
  Prime(b);
  for (int i = a; i <= b; ++i) {
    if (!isnprime[i] && IsPalindromes(i)) cout << i << endl;
  }
  return 0;
}


