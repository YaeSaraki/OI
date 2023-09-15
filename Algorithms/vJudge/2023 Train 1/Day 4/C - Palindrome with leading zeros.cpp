/**
 * \link: https://vjudge.csgrandeur.cn/problem/AtCoder-abc198_b
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
	string str; cin >> str;
	while (str[str.size() - 1] == '0') str.pop_back(); // new: pop.back() -> string & vector
	if (str == string(str.rbegin(), str.rend())) cout << "Yes";
	else cout << "No";
	return 0;
}