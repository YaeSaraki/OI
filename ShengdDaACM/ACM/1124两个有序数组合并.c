#include <stdio.h>
#define N 1000000

void sssPrintArr(int c[], int n);

int main()
{
    int a[N], b[N];
    int m, n;

    scanf("%d", &m);
    for (int i = m - 1; i >= 0; i--)
        scanf("%d", &a[i]);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);

    int c[m + n];
    int i = 0, j = 0, k = 0;

    while (i < m && j < n)
    {
        if (a[i] <= b[j])
        {
            c[k++] = b[j++];
        }
        else
        {
            c[k++] = a[i++];
        }
    }
    while (i < m) // . ==  while (j = n)
    {
        c[k++] = a[i++];
    }
    while (j < n)
    {
        c[k++] = b[j++];
    }
    sssPrintArr(c, k);
    return 0;
}

void sssPrintArr(int c[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            printf("%d", c[i]);
        else
            printf(" %d", c[i]);
    }
}