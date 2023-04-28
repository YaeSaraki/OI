#include <stdio.h>

int yearsDay(int year); //某年天数

int main()
{

    int year, month, day;
    int T, rt;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d-%d-%d", &year, &month, &day);

        if (month == 2 && day == 29)
            printf("-1\n");
        else
        {
            int sumDays = 0;
            if (month <= 2)
                for (int i = year; i <= year + 17; i++)
                    sumDays += yearsDay(i);
            else
                for (int i = year + 1; i <= year + 18; i++)
                    sumDays += yearsDay(i);
            printf("%d\n", sumDays);
        }
    }
    return 0;
}

int yearsDay(int year)
{
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
        return 366;
    else
        return 365;
}
