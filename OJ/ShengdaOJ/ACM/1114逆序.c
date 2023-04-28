#include <stdio.h>
#define N 10
int main()
{
    int i, n;
    int a[N];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = n - 1; i >= 0; i--)
        printf("%4d", a[i]);
    printf("\n");
    return 0;
}
