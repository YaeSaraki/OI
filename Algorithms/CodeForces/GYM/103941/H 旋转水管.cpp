#include <iostream>
#include <algorithm>

using namespace std;

const int kN = 100001;

char state[5][100100];
int m;
bool flag = 0;
void DFS(int x, int y, char f) {
  if (state[y][x] == 0) return;
  if (state[y][x] == 'e') flag = 1;
  if (flag == 1) return;
  if (1 >= y || y >= 4 || x < 1 || x > m) return;

  if (state[y][x] == 'L') {
    state[y][x] = 0;
    if (f == 'd' || f == 'u')
      DFS(x - 1, y, 'l'), DFS(x + 1, y, 'r');
    else if (f == 'l' || f == 'r')
      DFS(x, y + 1, 'd'), DFS(x, y - 1, 'u');
    state[y][x] = 'L';
	}
	
	if (state[y][x] == 'I') {
		state[y][x] = 0;
		if (f == 'u') DFS(x, y - 1, 'u');
		else if (f == 'd') DFS(x, y + 1, 'd');
		else if (f == 'l') DFS(x - 1, y, 'l');
		else if (f == 'r') DFS(x + 1, y, 'r');
		state[y][x] = 'I';
	}
}

inline void solve() {
//	int x, y; cin >> m >> x >> y;
	int x, y; scanf("%d%d%d", &m, &x, &y);
	state[4][y] = 'e';
//	cin >> state[2] >> state[3];
	getchar();
	for (int i = 2; i <= 3; ++i) {
		for (int j = 1; j <= m; ++j) scanf("%c", &state[i][j]);
		getchar();
	}
	flag = 0;
	DFS(x, 2, 'd');
	if (flag) printf("YES\n");
	else printf("NO\n");
	state[4][y] = 0;
	return ;
	
}


int rt = 1;
signed main() {

	#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	#endif
	if (rt == 1) {int T; cin >> T; while(T--) solve(); }
	else solve(); 
	return 0;
}
