#include <stdio.h>
#include <math.h>

int result(int m, int n)
{
    return n ? result(n, m % n) : m;
}

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    int max = (m > n) ? m : n;
    int min = (m < n) ? m : n;
    printf("%d", result(max, min));
    return 0;
}