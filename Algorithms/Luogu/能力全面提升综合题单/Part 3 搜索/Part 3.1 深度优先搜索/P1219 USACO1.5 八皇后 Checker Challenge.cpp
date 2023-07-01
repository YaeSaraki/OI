#include <algorithm>
#include <iostream>
#define endl '\n'
using namespace std;

int n;
int a[14];
bool r[14], xy[233], yx[233];

int total = 0;
void Print() {
  if (total <= 3) {
    for (int i = 1; i <= n; ++i) cout << a[i] << " ";
    cout << endl;
  }
}

void dfs(int step) {
  if (step == n + 1) { ++total; Print(); return; }
  for (int i = 1; i <= n; ++i) {
    if (!r[i] && !xy[step - i + n] && !yx[step + i + n]) {
      r[i] = xy[step - i + n] = yx[step + i + n] = true;
      a[step] = i;
      dfs(step + 1);
      r[i] = xy[step - i + n] = yx[step + i + n] = false;
    }
  }
}

inline void solve() {
  cin >> n;
  dfs(1);
  cout << total << endl;
  return ;
}

bool rt = false;
int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while (T--) solve(); } 
  else solve();
  return 0;
}