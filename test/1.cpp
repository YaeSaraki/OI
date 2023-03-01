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
bool isnum(char ch);
bool isoperator(char ch);
int compare(char a, char b);
double cal(double a, double b, char op);


int main() {
	
}

bool isnum(char ch) {
  if ('0' <= ch || ch <= '9') return true;
  return false;
}

bool isoperator(char ch) {
  if (ch == '+' || ch == '-' || ch == '*' || ch =='/') return true;
  return false;
}

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

