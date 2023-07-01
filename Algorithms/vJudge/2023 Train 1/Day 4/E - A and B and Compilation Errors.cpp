/**
 * \link: https://codeforces.com/problemset/problem/519/B
 * \category: 数据结构 排序 模拟
 * 
 * 
 * 
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	int n, x;
	cin >> n;
	vector<int> s, s1, s2;
	for (int i = 0; i < n; ++i) { cin >> x; s.push_back(x); }
	for (int i = 0; i < n - 1; ++i) { cin >> x; s1.push_back(x); }
	for (int i = 0; i < n - 2; ++i) { cin >> x; s2.push_back(x); }
	sort(s.begin(), s.end());
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	for (int i = 0; i < s.size(); ++i) {
		if (i == s.size() - 1) {
			cout << s[i] << '\n';
			break;
		}
		if (s1[i] != s[i]) {
			cout << s[i] << '\n';
			break;			
		}
	}
	for (int i = 0; i < s1.size(); ++i) {
		if (i == s1.size() - 1) {
			cout << s1[i] << '\n';
			break;
		}
		if (s1[i] != s2[i]) {
			cout << s1[i] << '\n';
			break;
		}
	}
	return 0;
}