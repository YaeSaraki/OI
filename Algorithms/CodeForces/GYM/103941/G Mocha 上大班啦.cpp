#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

char a[4001][4001];

int main() {
	int n, m; cin >> n >> m;
	long long ans = 0;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < m; ++i) {
		int cnt = 1;
		for (int j = 0; j < n; ++j) {
			if (a[j][i] == '0') cnt = 0;
		}
		ans += cnt;
	}

	cout << ans << '\n';
	return 0;	
}
