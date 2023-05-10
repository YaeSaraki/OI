#include <iostream>
#include <algorithm>
using namespace std;

const int kN = 100;
int l[kN], r[kN], w[kN], idx, root;
int n;

void insert(int &u, int x) {
  if (!u) u = ++idx, w[u] = x;
  else if (x > w[u]) insert(r[u], x);
  else if (x < w[u]) insert(l[u], x);
}

void dfs(int u, int t) {
  if (!u) return;
  if (t == 0) cout << w[u] << ' ';
  dfs(l[u], t);
  if (t == 1) cout << w[u] << ' ';
  dfs(r[u], t);
  if (t == 2) cout << w[u] << ' ';
}

int main() {
  cin >> n;
  while (n--) {
    int x; cin >> x;
    insert(root, x);
  }
  for (int i = 0; i < 3; ++i) { dfs(root, i); cout << endl; }
  return 0;
}