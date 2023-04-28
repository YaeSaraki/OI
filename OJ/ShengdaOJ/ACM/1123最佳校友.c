#include <stdio.h>

void sssPrint(int a[], int n, int max);

int main()
{
    int a[1000] = {0}, n, max = 0, sum = 0;
    while (scanf("%d", &n), n >= 0)
    {
        sum = (sum > n) ? sum : n;
        a[n]++;
        max = (max > a[n]) ? max : a[n];
    }
    sssPrint(a, sum, max);
}

void sssPrint(int a[], int n, int max)
{
    int flag = 0;
    for (int i = 0; i <= n; i++)
    {
        if (max == a[i])
        {
            if (flag == 0)
            {
                printf("%d", i);
                flag++;
            }
            else
                printf(" %d", i);
        }
    }
}