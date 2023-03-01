#include <stdio.h>
#define M 1001
#define N 11

int m, n;
double a[M][N];

int main()
{
    scanf("%d%d", &m, &n);

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%lf", &a[i][j]);
    for (int j = 0; j < n; j++)
    {
        double sum = 0;
        for (int i = 0; i < m; i++)
        {
            sum += a[i][j];
        }
        printf("%.2lf ", sum * 1.0 / m);
    }
    return 0;
}
