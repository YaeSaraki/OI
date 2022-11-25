#include <stdio.h>

int main()
{
    char a[10000];
    int m, n, sum = 0;
    fgets(a, 10000, stdin);
    for (int i = 0; a[i] != '\0'; i++)
    {
        if (('0' <= a[i] && a[i] <= '9') && ('0' > a[i + 1] || a[i + 1] > '9'))
            sum++;
        if (a[i] == '0' && ('0' > a[i - 1] || a[i - 1] > '9' || i == 0))
            sum++;
    }
    printf("%d", sum);
    return 0;
}