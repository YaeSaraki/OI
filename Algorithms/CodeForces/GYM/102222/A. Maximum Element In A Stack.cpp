/**
 * \link: https://codeforces.com/gym/102222/problem/A
 * \category: 模拟堆栈
 * 
 * 
 * 
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
const int kN = 5e6 + 233;
int skt[kN];
int top;

int rod = 1;
ll ans = 0;

int n, p, q, m;
unsigned int SA, SB, SC;

unsigned int rng61() {
	SA ^= SA << 16;
	SA ^= SA >> 5;
	SA ^= SA << 1;
	unsigned int t = SA;
	SA = SB;
	SB = SC;
	SC ^= t ^ SA;
	return SC;
}

void PUSH(int x) { skt[++top] = x; skt[top] = max(skt[top], skt[top - 1]);}
void POP() { top = max(top - 1, 0); }

void gen() {
// scanf("%d%d%d%d%u%u%u", &n, &p, &q, &m, &SA, &SB, &SC);
	cin >> n >> p >> q >> m >> SA >> SB >> SC;
// cout << n << endl;
  top = (ans = 0);
  for (int i = 1; i <= n; i++) {
    if (rng61() % (p + q) < p) PUSH(rng61() % m + 1);
    else POP();
    ans ^= 1LL * i * skt[top]; // ! 注意需要乘上 1LL 将式子转换为 long long
  // cout << ans << endl;
  }
}
void inline solve() {
	gen();
// return printf("Case #%d: %lld\n", rod++, ans), void();
	return cout << "Case #" << rod++ << ": " << ans << '\n', void();
}

bool rt = true;
signed main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	#endif
	if (rt) { int T; cin >> T; while (T--) solve() ;}
	else solve();
	return 0;
}