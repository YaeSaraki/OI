#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int n; cin >> n;
	string str;
	for (int i = 0; i < n; ++i) {
		int m; cin >> m;
		cin >> str;
		int flag = 1;
		for (int i = 0; i < str.length(); ++i) {
			for (int j = i + 1; j < str.length(); j += 2) {
				if (str[i] == str[j]) {
					flag = 0;
					break;
				}
			}
			if (!flag) break;
		}
		if (flag) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}
