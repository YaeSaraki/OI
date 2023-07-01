#include <iostream>
#include <algorithm>
using namespace std;

int a[100100];

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	int a_min = a[1], a_min_i = 1, time = 0;
	int flag = 1;
	while (flag) {
		flag = 0;
		a_min = 999999999;
//  cout << flag << endl;
		for (int i = 1; i <= n; ++i) {
			if (a[i] > 0) {
				flag = 1;
			//cout << a[i] << endl;
				if (a[i] < a_min) a_min = a[i], a_min_i = i;
			}
		}
		if (flag == 0) break;
		
		++time;
		for (int j = a_min_i + 1; j <= n; ++j) {
			if (a[j] == 0) break;
			--a[j];
		}
		for (int j = a_min_i; j >= 1; --j) {
			if (a[j] == 0) break;
			--a[j];
		}
	}
	cout << time << '\n';
	return 0;
}
