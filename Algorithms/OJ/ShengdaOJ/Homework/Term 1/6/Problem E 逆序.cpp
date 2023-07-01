#include <bits/stdc++.h>

using namespace std;

int s[11];

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) scanf("%d", &s[i]);
  for (int i = T - 1; i >= 0; i--) printf("%4d", s[i]);
  return 0;
}