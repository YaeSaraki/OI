#include <stdio.h>

int FindMax(int p[][3], int m, int n, int *pRow, int *pCol);

int main()
{
    int p[2][3], row, col, max;
    int m = 2, n = 3;
    for (int i = 0; i < m; i++)
        for (int ii = 0; ii < n; ii++)
            scanf("%d", &p[i][ii]);
    max = FindMax(p, m, n, &row, &col);
    printf("%d %d %d", max, row, col);
    return 0;
}

int FindMax(int p[][3], int m, int n, int *pRow, int *pCol)
{
    int max = p[0][0];
    *pRow = 0;
    *pCol = 0;
    for (int i = 0; i < m; i++)
        for (int ii = 0; ii < n; ii++)
            if (p[i][ii] > max)
            {
                max = p[i][ii];
                *pRow = i;
                *pCol = ii;
            }
    return max;
}
