#include <stdio.h>
#include <limits.h>

void LargestTow(int a[], int n, int *pfirst, int *psecond);

int main()
{
    int n;
    int a[100000], first, second;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    LargestTow(a, n, &first, &second);
    printf("%d %d", first, second);
    return 0;
}

void LargestTow(int a[], int n, int *pfirst, int *psecond)
{

    int i;
    *pfirst = INT_MIN;
    *psecond = INT_MIN;

    for (i = 0; i < n; i++)
    {
        if (a[i] > *psecond)
        {
            *psecond = a[i];
            if (*psecond > *pfirst && *psecond != *pfirst)
            {
                int t = *pfirst;
                *pfirst = *psecond;
                *psecond = t;
            }
        }
    }
}
