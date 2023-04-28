#include <iostream>
#include <map>

using namespace std;
using ll = long long;
using PI = pair<ll, int>;
map<int, PI> PII;

int main() {
  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    ll num;
    int a, b;
    cin >> num >> a >> b;
    PII[a] = {num, b};
  }
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a; cin >> a;
    cout << PII[a].first << " " << PII[a].second << '\n';
  }
  return 0;
}

