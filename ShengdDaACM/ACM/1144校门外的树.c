#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    while (N--)
    {
        int L, M;
        scanf("%d%d", &L, &M);
        int l1, l2, a[100000] = {0};
        while (M--)
        {
            scanf("%d%d", &l1, &l2);
            for (int i = l1; i <= l2; i++)
                a[i] = 1;
        }
        int num = 0;
        for (int i = 0; i <= L; i++)
        {
            if (a[i] == 0)
            {
                num++;
            }
        }
        printf("%d\n", num);
    }

    return 0;
}