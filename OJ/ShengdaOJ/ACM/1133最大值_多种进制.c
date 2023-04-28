#include <stdio.h>
#include <string.h>
#define N 233

int kToD(char str[], int n);

int main()
{
    int n, m, k, max = -1;
    char str[N];
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%s%d", str, &n);
        k = kToD(str, n);
        max = (max > k) ? max : k;
    }
    printf("%d", max);
    return 0;
}

int kToD(char str[], int n)
{
    int sum = 0, len = strlen(str), t = 1;
    for (int i = len - 1; i >= 0; i--)
    {
        sum += ((str[i] - '0') * t);
        t *= n;
    }
    return sum;
}