#include <stdio.h>

int main()
{
    int n, l = 0, time = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int m;
        scanf("%d", &m);
        if (m > l)
        {
            time += (m - l) * 6;
        }
        else if (m < l)
        {
            time += (l - m) * 4;
        }
        l = m;
        time += 5;
    }

    printf("%d", time);
    return 0;
}