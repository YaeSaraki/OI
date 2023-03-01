#include <stdio.h>

#define N 10

void PrintArr(int a[], int n);
void sort(int a[], int n);

int main()
{
    int n, a[N] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a, n);
    PrintArr(a, n);
    return 0;
}

void sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int ii = i + 1; ii < n; ii++)
        {
            if (a[i] > a[ii])
            {
                int t = a[i];
                a[i] = a[ii];
                a[ii] = t;
            }
        }
    }
}

void PrintArr(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            printf("%d", a[i]);
        else
            printf(" %d", a[i]);
    }
}
