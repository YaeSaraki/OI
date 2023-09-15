//https://vjudge.csgrandeur.cn/problem/UVA-213
#include <algorithm>
#include <bitset>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#define endl '\n'
using namespace std;
using ll = long long;

const int kN = 100100;
vector<string> bsv;
map<string, char> mp;

string DecToBin(int val, int width) { // 10 to 2 + front(len * '0')
  string ret;
  do { // Dec to Bin 
    ret.push_back((val % 2) + '0');
    val /= 2;
  } while (val);
  reverse(ret.begin(), ret.end());

  ret = string(width - ret.size(), '0') + ret;
  return ret;
}

int BinToDec(string str) { // 2 to 10
  int dec = 0;
  for (auto ch : str) dec = (dec << 1) + (ch - '0');
  return dec;
}

void init() {
  for (int i = 1; i < 8; ++i) {
    for (int j = 0; j < (1 << i) - 1; ++j) {
      bsv.push_back(DecToBin(j, i));
    }
  }
}

inline void solve() {
  init();
  string head; getline(cin, head);
  string code, t, s;
  while (true) {
    while (getline(cin, s) && (s[0] == '1' || s[0] == '0')) code += s;
  // cout << code << endl;
    if (code.empty()) break; // end
    for (int i = 0; i < head.size(); ++i) mp.insert({bsv[i], head[i]});
    int i = 0;
    while (i < code.size()) {
      t = code.substr(i, 3); i += 3;
      if (t == "000") break;
      int len = BinToDec(t);
    // cout << "len: " << len << endl; 
      while (i < code.size()) {
        t = code.substr(i, len); i += len;
        if (t == string(len, '1')) break; // len * '1' to indicate the end.
        cout << mp[t];
      }
    }
    cout << endl;
    head = s; code.clear(); mp.clear();
 }
 return ;
}

bool rt = false;

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { while(true) solve(); } 
  else solve();
  return 0; 
}