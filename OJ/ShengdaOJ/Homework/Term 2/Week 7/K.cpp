#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> peo;

bool cmp (const pair<string, int> &A, const pair<string, int> &B) {
  if (A.second != B.second) return A.second > B.second;
  return false;
}

int main() {
  string name;
  while (cin >> name, name != "#") ++peo[name];
  auto it = min_element(peo.begin(), peo.end(), cmp);
  cout << it->first << '\n';
  return 0;
}