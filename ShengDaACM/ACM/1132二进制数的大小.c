#include <stdio.h>
#include <string.h>

#define N 50

int bToD(char str[]);

int main()
{
    char str[N];
    int a[3], n;
    for (int i = 0; i < 3; i++)
    {
        scanf("%s", str);
        a[i] = bToD(str);
    }
    for (int i = 1; i < 3; i++)
    {
        for (int j = 1; j < 3; j++)
        {
            if (a[j] < a[j - 1])
            {
                n = a[j - 1];
                a[j - 1] = a[j];
                a[j] = n;
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", a[i]);
    }
        return 0;
}

int bToD(char str[])
{
    int sum = 0, len = strlen(str), t = 1;
    for (int i = len - 1; i >= 0; i--)
    {
        sum += ((str[i] - '0') * t);
        t *= 2;
    }
    return sum;
}