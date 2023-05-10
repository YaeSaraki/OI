#include <iostream>
#include <algorithm>
using namespace std;
int a[100100];

int main() {

	int T; cin >> T;
	while (T--) {
		int flag = 0, f = 0;
		int temp = 0;
		int x, t, k, n, d; cin >> x >> t >> k >> n >> d;
		int temp_x = x;
		int time = 0;
		for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
		for (int i = 1; i <= n * 2 - 1; ++i) {
			if (a[i % (n + 1)] <= d) --temp, --temp_x;
			else ++temp, ++temp_x;
			
			if (i == n && temp < 0) { f = 1; break; }
			
			if (temp_x <= k) ++time;
			else time = 0;
			if (time == t) flag = 1;
			if (flag) { f = 1; break; }
		}
		if (f) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
