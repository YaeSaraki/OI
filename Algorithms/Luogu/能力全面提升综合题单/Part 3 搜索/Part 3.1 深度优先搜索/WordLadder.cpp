/**
 * @problem: P1019 [NOIP2000 提高组] 单词接龙 
 * @link: https://www.luogu.com.cn/problem/P1019
 * @category: string DFS 
 * @date: Mon Jul 17 10:06:28 CST 2023
 * @author: YaeSaraki
 **/
// #pragma GCC optimize("O2")

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>

#define DBG(x) cout << #x << " = " << (x) << '\n'

using namespace std;

vector<string> words;
map<string, int> wordsMap;

int findTheLinkPoint(string a, string b) {
  int la = a.length(), lb = b.length();
  if (b.find(a) != -1 && la != lb) return -1;
  for (int i = 1; i < la; ++i) {
    if (a.substr(la - i, i) == b.substr(0, i)) return i;
  }
  return -1;
}

size_t maxLength = 2;
void DFS(string str) {
  for (int i = 0; i < words.size(); ++i) {
    int state = findTheLinkPoint(str, words.at(i));
    if (state == -1) continue;
    if (wordsMap[words.at(i)] < 2) {
      ++wordsMap[words.at(i)];
      string n = str + words.at(i).substr(state); 
      maxLength = max(maxLength, n.length());
      DFS(n);
      --wordsMap[words.at(i)];
    }
  }
}

inline void solve() {
  int n; cin >> n;
  words = vector<string> (n);
  for (auto &str : words) cin >> str;
  string str; cin >> str;
  str = "#" + str; // !  add a char # in start char to mark of avoiding be included.
  ++wordsMap[str];
  DFS(str);
  cout << maxLength - 1 << '\n'; // minus the # 's length.
}

bool rt = false;
signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif
  if (rt) { int T; cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}
