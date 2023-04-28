#include <stdio.h>
#include <stdlib.h>

void ringShift(int *a, int n, int k);

int main()
{
    int n;
    scanf("%d", &n);
    int *s = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &s[i]);
    int k;
    scanf("%d", &k);
    ringShift(s, n, k);
}

void ringShift(int *a, int n, int k)
{
    int *b = NULL;
    b = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        if (i < k)
            *(b + i) = *(a + i + n - k);
        else
            *(b + i) = *(a + i - k);
    }
    for (int i = 0; i < n; i++)
        printf("%d ", *(b + i));
}