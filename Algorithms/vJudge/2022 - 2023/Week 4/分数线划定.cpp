#include<iostream>
#include<algorithm>
#include<fstream>

using namespace std;

#define cin fin
#define cout fout
ifstream fin("in.txt");
ofstream fout("out.txt");

struct Node {
	int id, point;
}; 
Node data[5005];

bool cmp(Node a, Node b) {
	if (a.point > b.point) return true;
	if (a.point == b.point && a.id < b.id) return true;
	return false;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) 
		cin >> data[i].id >> data[i].point;
	sort(data, data + n, cmp);
	m *= 1.5;
	int point_line = data[m - 1].point;
	for (int i = 0; i < n; ++i) {
		if (data[i].point < point_line) {
			cout << point_line << " " << i << endl;
			break;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (data[i].point >= point_line) 
			cout << data[i].id << " " << data[i].point << endl;
	}
	return 0;
}

