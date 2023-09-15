#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
int main() {
	ll n, l, r, ans = 0;
	cin >> n >> l >> r;
	if (r / n > l / n) cout << n - 1 << '\n';
	else cout << r % n << '\n';
	return 0;
}