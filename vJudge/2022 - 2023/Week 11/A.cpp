#include <iostream>
#include <algorithm>
#include <deque>
#include <map>

using namespace std;

int a[2002002];
deque<int> d;

int main() {
	int n, k; cin >> n >> k;
	int x;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		d.push_back(i);
	}
	int now;
	now = d.front();
	d.pop_front();
	int time = 0;
	while (time < k) {
		if (a[now] >= a[d.front()]) {
			int temp = d.front();
			d.pop_front();
			d.push_back(temp);
			++time;
		} else {
			d.push_back(now);
			now = d.front();
			time = 0;
		}
	}
	cout << now << endl;
	return 0;
}
