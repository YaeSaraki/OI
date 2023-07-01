#include <stdio.h>
#define N 10

int find(int a[], int n, int x);
void del(int a[], int n, int i);
void PrintArr(int a[], int n);

int main()
{
    int n, a[N], x, f;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &x);
    f = find(a, n, x);
    if (f == -1)
    {
        printf("No Answer");
    }
    else
    {
        del(a, n, f);
        PrintArr(a, n);
    }
    return 0;
}

int find(int a[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            return i;
        }
    }
    return -1;
}

void del(int a[], int n, int x)
{
    for (int i = x; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }
}

void PrintArr(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        printf("%4d", a[i]);
    }
}
