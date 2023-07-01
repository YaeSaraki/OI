#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

struct point { int x, y; } p[100];
bool cmp1(point A, point B) {
  if (A.x != B.x) return A.x < B.x;
  if (A.y != B.y) return A.y < B.y;
  return false;
}
bool cmp2(point A, point B) {
  if (A.x != B.x) return A.x > B.x;
  if (A.y != B.y) return A.y > B.y;
  return false;
}

int main() {
  int n; cin >> n;
  for (int i = 0; i < n; ++i) cin >> p[i].x >> p[i].y;
  sort(p, p + n, cmp1);
  for (int i = 0; i < n; ++i) cout << "(" << p[i].x << "," << p[i].y << ")" << " ";
  sort(p, p + n, cmp2);
  cout << '\n';
  for (int i = 0; i < n; ++i) cout << "(" << p[i].x << "," << p[i].y << ")" << " ";
  return 0;
}