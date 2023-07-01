#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

set<string> dates;
int md[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
								 {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

bool IsLeap(int y) { return (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0)); }

void F(int n1, int n2, int n3) {
	char str[20];
	string s;
  if (n1 >= 60) n1 += 1900;
	else n1 += 2000;
	if (1 > n2 || n2 > 12) return ;
	if (1 > n3 || n3 > md[IsLeap(n1)][n2]) return ;
	snprintf(str, 20, "%04d-%02d-%02d", n1, n2, n3);
  dates.insert(s = str);
}

int main() {
	int n1, n2, n3;
	scanf("%d/%d/%d", &n1, &n2, &n3);
	F(n1, n2, n3), F(n3, n1, n2), F(n3, n2, n1);
	for (auto it : dates) cout << it << endl;
	return 0;	
}