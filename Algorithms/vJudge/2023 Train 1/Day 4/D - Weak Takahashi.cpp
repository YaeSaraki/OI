/**
 * https://vjudge.csgrandeur.cn/problem/AtCoder-abc232_d
 * \category: DFS
 * 
 * 
 * 
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int kN = 101;

int m, n;
char a[kN][kN];
bool ans[kN][kN];
int cnt = 0;
void DFS(int x, int y, int step) {
	if (ans[y][x]) return ;
	if (y > n || x > m) return ;
	if (a[y][x] == '#') return ;
	
	DFS(x + 1, y , step + 1), DFS(x, y + 1, step + 1);
	ans[y][x] = true;
	cnt = max(cnt, step);
	
	return ;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		getchar();
		for (int j = 1; j <= m; ++j) scanf("%c", &a[i][j]);
	}
	DFS(1, 1, 1);
	printf("%d\n", cnt);
	return 0;
}