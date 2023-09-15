#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#define endl '\n'
#define int long long
using namespace std;
using ll = long long;

int gcd(int a, int b) { return a % b == 0 ? b : gcd(b, a % b); }

void sim(int &numerator, int &denominator) {
  int num = gcd(numerator, denominator);
  if (num) numerator /= num, denominator /= num;
// cout << endl << numerator << " " << denominator << endl;
  return ; 
}

inline void solve() {
  int numerator = 0, denominator = 0;
  int n; scanf("%lld", &n);
  int num_t = 0, den_t = 0;
  for (int i = 0; i < n; ++i) {
    if (scanf("%lld/%lld", &num_t, &den_t) != EOF);
    if (den_t == 0 || num_t == 0) continue;
    if (denominator == 0) numerator = num_t, denominator = den_t;
    else {
      numerator = numerator * den_t + denominator * num_t;
      denominator *= den_t;
      sim(numerator, denominator);
    }
  }
  bool flag = 0;
  if (!denominator || !numerator) cout << "0" << endl, void();
  else if (abs(numerator) >= abs(denominator)) cout << numerator / denominator, flag = 1;
  if (numerator % denominator) {
    if (flag) cout << " ";
    cout << numerator % denominator << "/" << denominator << endl;
  }
// cout << endl << numerator << " " << denominator << endl;
  return ;
}


int tc = false;

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (tc) { int T; cin >> T; while(T--) solve(); }
  else solve();
  return 0;
}
