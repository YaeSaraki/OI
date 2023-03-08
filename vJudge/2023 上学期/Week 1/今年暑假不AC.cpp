#include <algorithm>
#include <iostream>
using namespace std;

const int MAXN = 1000;

struct ShowTime {
  int start, end;
};
ShowTime show_time[MAXN];

bool cmp(ShowTime x, ShowTime y) { return x.end < y.end; };

int main() {
  int n; while (cin >> n, n) {
    for (int i = 0; i < n; ++i) cin >> show_time[i].start >> show_time[i].end;
    sort(show_time, show_time + n, cmp);
    int now = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (show_time[i].start >= now) {
        ++cnt;
        now = show_time[i].end;
      }
    }
    cout << cnt << endl;
  }
  return 0;
}