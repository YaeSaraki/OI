#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <unordered_set>
#include <vector>

// #define ONLINE_JUDGE

using namespace std;
using ll = long long;
unordered_set<string> s;
inline void solve() {
  int n; cin >> n;
  while (n--) {
    string temp;
    char ch; cin >> ch;
    switch(ch) {
      case 'I' : {
        cin >> temp;
        s.insert(temp);
        break;
      }
      case 'Q': {
        cin >> temp;
        int cnt = 0;
        for (auto it = s.begin(); it != s.end(); ++it)
          if (it->find(temp) != -1) ++cnt;
        cout << cnt << '\n';
        break;
      }
      case 'D' : {
        cin >> temp;
          unordered_set<string>::iterator it;
          for (it = s.begin(); it !=s.end(); ) {
            if (it->find(temp) != -1) {
              auto itt = it;
              ++it;
              s.erase(itt);
            } else ++it;
        }
        break;
      }
    }
  }
}

bool rt = false;
signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if(rt) { int T; cin >> T; while(T--) solve(); }
  else solve();
  return 0;
}