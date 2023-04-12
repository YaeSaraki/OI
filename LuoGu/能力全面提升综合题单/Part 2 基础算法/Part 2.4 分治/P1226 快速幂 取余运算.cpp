#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

ll f(ll a, ll b, ll p) {
  ll ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % p;
    a = a * a % p;
    b >>= 1;
  }
  return ans;
} 

int main() {
  ll a, b , p; cin >> a >> b >> p;
  cout << a << "^" << b << " mod " << p << "=" << f(a, b, p) << endl;
  return 0;
}