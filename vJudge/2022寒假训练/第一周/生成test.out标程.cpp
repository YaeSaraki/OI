#include <ctype.h>

#include <algorithm>
#include <iostream>

typedef long long ll;
using namespace std;
ll f(int m, int n);


int main(void) {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
	int inT = 100; while (inT--) {

		int T; cin >> T; while (T--) {
			int m, n;
			cin >> m >> n;
			cout << f(m, n) << endl;
		}

	}
  fclose(stdin);
  fclose(stdout);
  return 0;
}

ll f(int m, int n) {
  if (n == 0) return 0;
  if (m == 0) return 1;
  if (n > m) return f(m, m);
  else return f(m, n - 1) + f(m - n, n);
}
