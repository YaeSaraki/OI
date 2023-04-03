#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <algorithm>
#include <fstream>
using namespace std;

ifstream fin("test.in");
ofstream fout("test.out");
#define cin fin
#define cout fout

int main() { 
  int n; cin >> n;
  map<string, int> students;
  for (int i = 0; i < n; ++i) {
    int cnt; cin >> cnt;
    string name; cin >> name;
    students[name] = cnt;
  }
  for (int i = 0; i < n; ++i) {
    int cnt; cin >> cnt;
    string name; cin >> name;
    cout << students[name] - cnt << '\n';
  }
  return 0;
}

