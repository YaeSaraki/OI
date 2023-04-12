#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10010;
int a[N], l[N], h[N];

int main() {
  int n = 0;
  while (cin >> a[n++]); n--;
  int r1 = 0;
  l[0] = a[0];
  for (int i = 1; i < n; ++i) {
    if (l[r1] >= a[i]) l[++r1] = a[i];
    else *upper_bound(l, l + r1, a[i], greater<int>()) = a[i];
  }
  int r2 = 0;
  h[0] = a[0];
  for (int i = 1; i < n; ++i) {
    if (h[r2] < a[i]) h[++r2] = a[i];
    else *lower_bound(h, h + r2, a[i]) = a[i]; 
  }
  
  cout << r1 + 1 << " " << r2 + 1 << '\n'; 
  return 0;
}