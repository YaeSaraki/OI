#include <iostream>
#include <algorithm>
using namespace std;
int a[1001][1001];

int main() {
	int n, m; cin >> n >> m;
	int x_1, y_1, x_2, y_2;
	while (m--) {
		cin >> y_1 >> x_1 >> y_2 >> x_2;
		for (int i = y_1; i <= y_2; ++i) 
			for (int j = x_1; j <= x_2; ++j) ++a[i][j];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) printf("%d ", a[i][j]);
		cout << endl;
	}
	return 0;
}
