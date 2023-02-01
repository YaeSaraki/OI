#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;

const int MOD = 998244353;

ll pow(ll p, ll x);

int main() {
  ll n, p;
  cin >> n >> p;
  int ans = 1;
  for (int i = 1; i <= n; ++i) {
    ll m;
    cin >> m;
    ans = (ans * (pow(p, m) + 1)) % MOD;
  }
  cout << ans << endl;
  return 0;
}

ll pow(ll p, ll x) {
  int ans = 1;
  while (x) {
    if (x & 1) ans = (ans * p) % MOD;
    p = (p * p) % MOD;
    x >>= 1;
  }
  return ans;
}