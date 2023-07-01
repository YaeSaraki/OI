#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int a[100100] = {0};
	int v_max; cin >> v_max;
	int n; cin >> n;
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	sort(a, a + n);
	int l = 0, r = n - 1, mid = n - 1 >> 1;
	while (l < r) {
		int v = a[l] + a[r];
		if (v <= v_max)  ++l, --r;
		else 	--r;
	}
	cout << n - l << endl; 
	return 0;
}
