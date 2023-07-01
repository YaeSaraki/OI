#include <stdio.h>
#define N 233

int a[N][N], b[N][N], c[N][N], m, p, n;

int main()
{
    scanf("%d%d%d", &m, &p, &n);

    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++)
            scanf("%d", &a[i][j]);
    for (int i = 0; i < p; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &b[i][j]);

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < p; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
        
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}