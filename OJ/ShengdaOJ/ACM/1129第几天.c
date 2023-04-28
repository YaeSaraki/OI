#include <stdio.h>
#include <stdlib.h>

//声明函数原型
int GetYearDay(int year, int month, int day);
int IsLeap(int year);

//第几天
int main()
{
	int year, month, day;
	scanf("%d-%d-%d", &year, &month, &day);
	printf("%d", GetYearDay(year, month, day));
	return 0;
}

//输出这一天是该年的第几天
int GetYearDay(int year, int month, int day)
{
	int k, leap;
	int tab[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
					  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
	leap = IsLeap(year);
	for (k = 1; k < month; k++)
		//按leap行计算
		day = day + tab[leap][k];
	return day;
}

//判断是否是瑞年，如果是返回1，否则返回0
int IsLeap(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return 1;
	else
		return 0;
}