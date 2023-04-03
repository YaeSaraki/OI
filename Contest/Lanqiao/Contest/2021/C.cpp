#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define F(i, n) for (ll i = 0; i < n; ++i)


const ll N = 2021041820210418;

int main() {
  int ans = 0;
  vector<ll> v;
  for (ll i = 1; i * i <= N; ++i) {
    if (N % i == 0) {
      v.push_back(i);
      if (i != N / i) v.push_back(N / i);
    }
  }
  int len = v.size();
  F(a, len) F(b, len) F(c, len) {
    if (v[a] * v[b] * v[c] == N) ++ans;
  }
  cout << ans << endl;
  return 0;
}
