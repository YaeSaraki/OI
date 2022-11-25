#include <stdio.h>
int main()
{
    int year, month, day, m;
    scanf("%d-%d-%d", &year, &month, &day);
    m = 0;
    switch (month)
    {
    case 12:
        m += 30;
    case 11:
        m += 31;
    case 10:
        m += 30;
    case 9:
        m += 31;
    case 8:
        m += 31;
    case 7:
        m += 30;
    case 6:
        m += 31;
    case 5:
        m += 30;
    case 4:
        m += 31;
    case 3:
        m += 28;
    case 2:
        m += 31;
    case 1:
        m += day;
    }
    if (((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) && month > 2)
        m += 1;
    printf("%d", m);
    return 0;
}