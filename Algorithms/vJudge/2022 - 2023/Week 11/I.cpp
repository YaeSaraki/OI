#include <iostream>
#include <algorithm>
#include <cmath>
#include <deque>
using namespace std;

int a[100100];
int b[100100];
int c[100100];

inline void solve() {
	int n; cin >> n;
	deque<int> q;
	q.push_back(0);
	int cnt = 0;
	for (int i = 1; i < n; ++i) {
		int num; scanf("%d", &num);
		cnt += num;
		q.push_back(cnt);
	}
	int sum = q.back();
	cout << "0 " << q.back();
	int k = 1;
	b[k++] = 0, b[k++] = q.back();
	c[2] = q.back();
	q.pop_back(), q.pop_front();
	
	for (int i = 1; i <= n - 2; ++i) {
		if (i & 1) {
			b[k++] = q.front();
			q.pop_front();
			c[k - 1] = c[k - 2] + b[k - 1];
			sum += fabs(b[k - 1] * (k - 1) - c[k - 1]);
			
		} else {
			b[k++] = q.back();
			q.pop_back();
			c[k - 1] = c[k] + b[k - 1];
			sum += fabs(b[k - 1] * (k - 1) - c[k - 1]);
		}
		printf(" %d", sum);
	}
}

bool rt = true;

int main() {
	cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	#endif
	if (rt) { int T; cin >> T; while (T--) solve(); }
	else solve;
	return 0;
}
