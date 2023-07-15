#include <algorithm>
#include <fstream>
#include <iostream>
#define endl '\n'
using namespace std;
using ll = long long;

inline void solve() {
	int n; cin >> n;
	int a[n];
	int ev = 0, odd = 0;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] & 1) ev += a[i];
		else odd += a[i];
	}

	if (odd > ev) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int tc = 1;

int main() {
	ios:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	#endif
	if (tc) {int T; cin >> T; while (T--) solve();}
	else solve();
	return 0;
}
