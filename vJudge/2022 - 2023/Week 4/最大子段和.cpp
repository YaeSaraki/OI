#include<iostream>
#include<algorithm>
#include <limits.h>

using namespace std;
typedef long long ll;

int ans, sum, ans_max = INT_MIN;

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &sum);
		ans += sum;
		if (ans <= sum) ans = sum;
		ans_max = max(ans_max, ans);
	}
	cout << ans_max;
	return 0;
}
