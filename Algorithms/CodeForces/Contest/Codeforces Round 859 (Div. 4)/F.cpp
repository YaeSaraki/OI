#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
using ll = long long;

const int MAXN = 1001001;

ll a[1001001], b[1001001];

int main() {
	int T; cin >> T; while (T--) {
		int n; cin >> n;
		for (int i = 0; i < n; ++i) cin >> a[i];
		sort(a, a + n);
		int flag = 0;
		if (a[0] != 1) {
			flag = 1;
			cout << "NO" <<'\n';
		}
		b[0] = a[0];
		for (int i = 1; i < n; ++i) {
			if (a[i] > b[i - 1]) {
				flag = 1;
				cout << "NO" << '\n';
				break;
			}
			b[i] = b[i - 1] + a[i];
		}
		if (!flag) cout << "YES" << '\n';
	}
	return 0;
}
