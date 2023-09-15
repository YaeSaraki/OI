#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
  int T; cin >> T; while (T--) {
    string s; cin >> s;
    s = s.substr(0, s.size() / 2);
    int k = unique(s.begin(), s.end()) - s.begin(); // new unique()函数的用法: 找某段字符串中是否存在其他字符 即 判断字符串是否存在
    cout << (k == 1 ? "NO" : "YES") << '\n';
  }
  return 0;
}