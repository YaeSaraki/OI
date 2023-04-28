#include <stdio.h>
#define N 1001

int insert(int a[], int n, int num);
void PrintArr(int a[], int n);

int main()
{
    int n, m, a[N], num;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &num);
    m = insert(a, n, num);
    PrintArr(a, m);
    return 0;
}

int insert(int a[], int n, int num)
{
    for (int i = n - 1; i >= 0; i--)
    {
        if (num < a[i])
        {
            a[i + 1] = a[i];
            if (i == 0)
                a[i] = num;
        }
        else if (num >= a[i])
        {
            a[i + 1] = num;
            break; 
        }
    }
    return n + 1;
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