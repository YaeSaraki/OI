#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;



inline void solve() {

	int n; cin >> n;
	string str; cin >> str;
	if (str.size() < 17) return cout << "none\n", void();
	string ans;
	map<char, int> m;
	int flag = 1;
	for (int i = 0; i < str.size(); ++i) {
		char it = str[i];
		++m[it];
		if (flag == 1 && m[it] == 5) { 
			for (int i = 0; i < 5; ++i) ans += it;
			m.clear();
			flag = 2;
		}
		if (flag == 2 && m[it] == 7) {
			for (int i = 0; i < 7; ++i) ans += it;
			m.clear();
			flag = 3;
		}
		if (flag == 3 && m[it] == 5) {
			for (int i = 0; i < 5; ++i) ans += it;
			m.clear();
			flag = 4;
		}
		if (flag == 4) return cout << ans << '\n', void();
	}
	return cout << "none\n", void();
}

bool rt = true;
signed main() {
	#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	#endif
	if (rt) { int T; cin >> T; while(T--) solve(); }
	else solve(); 
	return 0;
}

