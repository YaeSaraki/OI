#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 10000

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    char a[1000][1000];
    memset(a, '.', sizeof a);
    int Ox = n / 2 + m / 2;
    int Oy = n / 2;
    int max = (Ox > Oy) ? Ox : Oy;
    for (int i = -m / 2; i <= -m / 2 + m - 1; i++)
        for (int y = 0; y <= max; y++)
            for (int x = 0; x <= max; x++)
            {
                if (x == y)
                {
                    a[Oy + y][Ox + x + i] = '*';
                    a[Oy + y][Ox - x + i] = '*';
                    a[Oy - y][Ox + x + i] = '*';
                    a[Oy - y][Ox - x + i] = '*';
                }
            }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + m - 1; j++)
        {
            printf("%c", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}