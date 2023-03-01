// 4 + 3
// 7 5 3 3
//  + * +

#include <algorithm>
#include <fstream>
#include <iostream>
#include <stack>
#include <map>

using namespace std;

map<char, int> priority;

int compare(char a, char b) {
	int cmp = 0;
	if (priority[a] <= priority[b]) cmp = -1;
	if (priority[a] > priority[b]) cmp = 1;
	return cmp;  
}

double cal(double a, double b, char op) {
	double ans;
	switch (op) {
		case '+' : ans = a + b; break;
		case '-' : ans = a - b; break;
		case '*' : ans = a * b; break;
		case '/' : ans = a / b; break;
	}
	return ans;
}

int main() {
	double n = 0;
	stack<double> num;
	stack<char> op;
	priority['0'] = -1, priority['+'] = 1, priority['-'] = 1,
	priority['*'] = 2, priority['/'] = 2;
 
}
