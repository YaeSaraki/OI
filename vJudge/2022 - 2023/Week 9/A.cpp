#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string t[5] = { "Typically Otaku", "Eye-opener", "Young Traveller", "Excellent Traveller" , "Contemporary Xu Xiake"};
int a[5];

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		int cnt = 0;
		for (int j = 0; j < 4; ++j) {
			int m; cin >> m;
			if (m) ++cnt;
		}
		cout << t[cnt] << endl;
	}
	return 0;
}
