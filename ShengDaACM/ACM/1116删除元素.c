#include <stdio.h>
#define N 10
void del(int a[], int n, int i);

void PrintArr(int a[], int n);

int main()
{
    int m, n, a[N], i;
    scanf("%d", &n);
    for (i = 0; i <= n - 1; i++)
    {
        scanf("%d", &m);
        a[i] = m;
    }
    scanf("%d", &i);
    del(a, n, i);
    PrintArr(a, n);
    return 0;
}

void del(int a[], int n, int i)
{
    a[i] = 114514;
}

void PrintArr(int a[], int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        if (a[i] != 114514)
        {
            if (i == 0)
                printf("%d", a[i]);
            else
                printf(" %d", a[i]);
        }
    }
}
