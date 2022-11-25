#include <stdio.h>

int removeDuplicates(int a[], int n);
void sort(int a[], int n);
void sssPrintArr(int a[], int m, int n);

int main()
{
    int a[1000], n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    m = removeDuplicates(a, n);
    //   printf("%d", m);
    sort(a, n);
    printf("%d\n", n - m);
    sssPrintArr(a, m, n);
    return 0;
}

int removeDuplicates(int a[], int n)
{
    int k = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int ii = i + 1; ii < n; ii++)
        {
            if (a[i] == a[ii] && a[i] != -1)
            {
                a[ii] = -1;
                k++;
            }
        }
    }
    return k;
}

void sort(int a[], int n)
{
    int t;
    for (int i = 0; i < n - 1; i++)
    {
        for (int ii = i + 1; ii < n; ii++)
        {
            if (a[i] > a[ii])
            {
                t = a[ii];
                a[ii] = a[i];
                a[i] = t;
            }
        }
    }
}

void sssPrintArr(int a[], int m, int n)
{
    for (int i = m; i < n; i++)
    {
        if (i == m)
            printf("%d", a[i]);
        else
            printf(" %d", a[i]);
    }
}