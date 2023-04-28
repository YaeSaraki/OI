#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

struct point { int x, y; } p[100];
bool cmp(point A, point B) {
  ll a = A.x * A.x + A.y * A.y;
  ll b = B.x * B.x + B.y * B.y;
  if (a != b) return a < b;
  return false; 
}

int main() {
  int n; cin >> n;
  for (int i = 0; i < n; ++i) cin >> p[i].x >> p[i].y;
  sort(p, p + n, cmp);
  for (int i = 0; i < n; ++i) cout << "(" << p[i].x << "," << p[i].y << ")" << " ";
  return 0;
}