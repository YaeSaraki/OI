#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int n;
string str[21];
map<string, int> stringtime;
size_t ans = 0;

int maxTSubStr(string &A, string &B) {
  int cnt = 233;
  if ((B.find(A) != -1 && A != B) || B.size() == 1) return -1;

  int i;
  bool flag;
  for (i = 1; i < min(A.size(), B.size()); ++i) {
    flag = true;
    for (int j = 0; j < i; ++j) 
      if (A[A.size() - i + j] != B[j]) flag = false;
    if (flag) return i;
  }
  return -1;
}

void dfs(string s) {
  for (int i = 0; i < n; ++i) {
    if (stringtime[str[i]] >= 2) continue;

    int idx = maxTSubStr(s, str[i]);
    if (idx == -1) continue;

    string tempstr = s + str[i].substr(idx);
    ans = max(ans, tempstr.length());
  // cout << tempstr << " " << stringtime[str[i]] << endl;

    ++stringtime[str[i]];
    dfs(tempstr);
    --stringtime[str[i]];
  }
}

inline void solve() {
  cin >> n;
  for (int i = 0; i <= n; ++i) cin >> str[i];

  dfs(string(" ") + str[n]);
  cout << ans - 1 << endl;
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