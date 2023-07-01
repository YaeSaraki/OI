#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
using ll = long long;
int a[100100];
int main() {
	ll ans = 0;
	a[0] = 0;
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	sort(a, a + n + 1);
	int l = 0, r = n;
	int up = 1;
	while (l < r) {
		if (up) {
			up = 0;
			ans += pow(a[r] - a[l++], 2);
		} else {
			up = 1;
			ans += pow(a[r--] - a[l], 2); 
		}
	}
	cout << ans;
	return 0;
}
