#include <stdio.h>

void PrintLine(int n);

int main()
{
    int m;
    scanf("%d", &m);
    PrintLine(m);
    return 0;
}

void PrintLine(int n)
{
    int o = n - 1;
    static int site[17][17];
    for (int y = 0; y <= o; y++)
    {
        for (int x = 0; x <= o; x++)
        {
            site[o + x][o + y] = n - x - y;
            site[o - x][o - y] = n - x - y;
            site[o - x][o + y] = n - x - y;
            site[o + x][o - y] = n - x - y;
        }
    }
    for (int y = 2 * n - 2; y >= 0; y--)
    {
        for (int x = 0; x <= 2 * n - 2; x++)
        {

            if (site[x][y] <= 0)
                printf(" ");
            else
                printf("%d", site[x][y]);
        }
        printf("\n");
    }
}
