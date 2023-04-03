#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;
typedef unsigned long long ull;
//#define cin fin
//#define cout fout
//ifstream fin("in.txt");
//ofstream fout("out.txt");

int data[5005];
int calendar[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
											 {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
int month_to_dayth[13] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
bool isLeapYear(int y) { return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0); } 

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; ++i) cin >> data[i];
	sort(data, data + n);
	int y1, m1, d1, h1, min1;
	int y2, m2, d2, h2, min2;
	scanf("%d-%d-%d-%d:%d", &y1, &m1, &d1, &h1, &min1);
	scanf("%d-%d-%d-%d:%d", &y2, &m2, &d2, &h2, &min2);
//cout << y1 << " " << m1 << " " << d1 << " " << h1 << endl;
	ull min_all = 0;
	int yy = y2 - y1;
	for (int i = 0; i < yy; ++i) {
		min_all += 365;
		if (isLeapYear(y1 + i)) ++min_all;
	}
	min_all *= 24 * 60;
//cout << min_all << endl;
	ull min_temp = 0;
	min_temp = min2 + 60 * (h2 + 24 * (d2 - 1 + month_to_dayth[m2]));
//cout << min_temp << endl;
	if (m2 > 2 && isLeapYear(y2)) min_temp += 24 * 60;
	min_all += min_temp;
	min_temp = min1 + 60 * (h1 + 24 * (d1 - 1 + month_to_dayth[m1]));
//cout << min_temp << endl;
	if (m1 > 2 && isLeapYear(y1)) min_temp += 24 * 60;
	min_all -= min_temp;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (data[i] <= min_all) ++ans, min_all -= data[i];
		else break;
	}
	cout << ans << endl;
	return 0;
}
