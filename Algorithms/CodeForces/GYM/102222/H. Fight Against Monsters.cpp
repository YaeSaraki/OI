/**
 * \link: https://codeforces.com/gym/102222/problem/H
 * \category: 贪心
 * 
 * 
 * 
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

//#define ONLINE_JUDGE

using namespace std;
using ll = long long;
const int kN = 1e5 + 233;
int rod = 1;

struct Node {
	int atk, hp, t;
	double k;
	void GetK() {
		int temphp = hp;
		for (int i = 1;; ++i) {
			temphp -= i;
			if (temphp <= 0) { k = atk * 1.0 / i; t = i; return; }
		}
		return;
	}
	bool operator <(const Node &A) const {
		if (k != A.k) return k > A.k;
		if (t != A.t) return t < A.t;
		return false;
	}
};

//void init() {
//	for (int i = 1; allatk[i] < 1e5 + 233; ++i) allatk[i] = allatk[i - 1] + i;
//	return ; 
//}


void inline solve() {
	int n; scanf("%d", &n);
	Node a[n + 1];
	ll at = 0;
	for (int i = 0; i < n; ++i) { 
		scanf("%d%d", &a[i].hp , &a[i].atk);
		at += a[i].atk;
		a[i].GetK();
	}
	
	sort(a, a + n);
	
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		int hp = a[i].hp;
//		while (hp > 0) {
//		 	ans += at;
//			hp -= t++;
//		}
//		int t = lower_bound(allatk, allatk + kN, hp) - allatk;
//	cout << t << endl;
		ans += at * a[i].t;
		at -= a[i].atk;
	}
	return printf("Case #%d: %lld\n", rod++, ans), void();
}

bool rt = true;
signed main() {
	#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	#endif
//	init();
//	cout << "1";
	if (rt) { int T; cin >> T; while (T--) solve() ;}
	else solve();
	return 0;
}