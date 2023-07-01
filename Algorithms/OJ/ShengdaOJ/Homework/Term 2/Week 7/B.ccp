#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int h1, m1, s1; 
	int h2, m2, s2;
	scanf("%d:%d:%d", &h1, &m1, &s1);
	scanf("%d:%d:%d", &h2, &m2, &s2);
	int s = 0;
	s += h1 * 3600 + m1 * 60 + s1;
	s -= h2 * 3600 + m2 * 60 + s2;
	if (s < 0) s *= -1;
	printf("%02d:%02d:%02d\n", s / 3600, s % 3600 / 60, s % 60);
	return 0;
}