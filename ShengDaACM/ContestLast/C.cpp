#include <bits/stdc++.h>
using namespace std;

string str;
string windows = "\\n\\r", linux = "\\n";

int main() {
  cin >> str;
  if (str.find(windows) <= str.length()) {
    cout << "windows" << endl;
    return 0;
  } else if (str.find(linux) <= str.length()) {
    cout << "linux" << endl;
    return 0;
  } else {
    cout << "mac" << endl;
    return 0;
  }
}