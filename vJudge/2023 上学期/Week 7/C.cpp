#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
using namespace std;

bool check(string str) {
	int a, b, c, d, e;
	if(sscanf(str.data(), "%d.%d.%d.%d:%d", &a, &b, &c, &d, &e) != 5) return false;
  if (a < 0 || a > 255 || b < 0 || b > 255 || c < 0 || c > 255 || d < 0 ||
            d > 255 || e < 0 || e > 65535) return false;
	stringstream ss;
	ss << a << '.' << b << '.' << c << '.' << d << ':' << e;
	if (ss.str() != str) return false;
	return true;	
}

int main() {
	int n; cin >> n;
	map<string, int> data;
	string str;
	for (int i = 1; i <= n; ++i) {
		cin >> str;
		if (str == "Server") {
			cin >> str;
			if (check(str)) {
				if (data[str] != 0) cout << "FAIL" << endl;
				else {
					data[str] = i;
					cout << "OK" << endl;
				}
			} else cout << "ERR" << endl;
		} else {
			cin >>str;
			if (check(str)) {
				if (data[str] != 0) cout << data[str] << endl;
				else cout << "FAIL" << endl;
			} else cout << "ERR" << endl;
		}
	}
	return 0;
}

