/**
 * https://vjudge.csgrandeur.cn/problem/AtCoder-abc232_b
 * \category: 字符串
 * 
 * 
 * 
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string str1, str2; cin >> str1 >> str2;
	int k = (str1[0] - str2[0] + 26) % 26;
	if (str1.size() != str2.size()) return cout << "No\n", 0;
	for (int i = 0; i < str1.size(); ++i) {
		if ((str1[i] - str2[i] + 26) % 26 != k) return cout << "No\n", 0;
	}
	return cout << "Yes\n", 0;
}