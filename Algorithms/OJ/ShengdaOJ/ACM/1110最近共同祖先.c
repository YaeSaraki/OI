#include <stdio.h>

int common(int x, int y);

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    printf("%d\n", common(m, n));
    return 0;
}

int common(int x, int y)
{
    if (x == y)
        return x;
    if (x > y)
        return common(x / 2, y);
    else
        return common(x, y / 2);
}