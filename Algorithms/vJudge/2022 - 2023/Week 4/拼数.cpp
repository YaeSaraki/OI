#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;
//#define cin fin
//#define cout fout
ifstream fin("in.txt");
ofstream fout("out.txt");

bool cmp (string a, string b) {
	if (a + b > b + a) return 1;
	return 0;
} 

string str[21];
int main() {
	int n; cin >> n; 
	for (int i = 0; i < n; ++i) cin >> str[i];
	sort(str, str + n, cmp);
	for (int i = 0; i < n; ++i) cout << str[i];
	return 0;
}
