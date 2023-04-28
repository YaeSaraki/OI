#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;

const int N = 2E5+10;
int a[N];
ll sum[N];

inline void solve() {
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];	
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 1; i <= q; ++i) {
		int l, r, x; cin >> l >> r >> x;
		int ans = sum[n] - (sum[r] - sum[l - 1]) + (r - l + 1) * x;
		if (ans & 1) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}

bool tc = true;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	#endif
	if (tc)	{int T; cin >> T; while (T--) solve(); }
	else solve();
	return 0;
}
