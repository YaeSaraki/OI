#include <stdio.h>
#define N 1000

int main()
{
    int a[N], n, m, min1 = 999999, min2;
    scanf("%d", &n);
    for (int i = 0; i <= n - 1; i++)
    {
        scanf("%d", &m);
        a[i] = m;
        if (m < min1)
        {
            min1 = m;
            min2 = i;
        }
    }
    printf("%d %d", min1, min2);
    return 0;
}