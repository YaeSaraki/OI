#include <stdio.h>
#include <string.h>
#define N 100

int main()
{
    int n, m, k, flag, c = 0;
    int a[N], b[N];

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);
    for (int i = 0; i < n; i++)
    {
        flag = 1;
        if (b[0] == a[i])
        {
            for (int j = 1; j < m; j++)
            {
                if (b[j] != a[i + j])
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
            {
                c = 1;
                printf("%d\n", i);
                break;
            }
        }
    }
    if (c == 0)
        printf("No Answer\n");
    return 0;
}
