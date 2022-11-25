#include <stdio.h>
#include <stdlib.h>
void swap(int *pa, int *pb);
int main()
{
    int i, j, a[4];
    for (i = 0; i < 4; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < 4; i++)
    {
        for (j = i + 1; j < 4; j++)
        {
            if (a[i] < a[j])
                swap(&a[i], &a[j]);
        }
    }
    for (i = 0; i < 4; i++)
    {
        if (i == 0)
            printf("%d", a[i]);
        else
            printf(" %d", a[i]);
    }
    return 0;
}
void swap(int *pa, int *pb)
{
    int t;
    t = *pa;
    *pa = *pb;
    *pb = t;
}