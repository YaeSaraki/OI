#include <stdio.h>
#include <math.h>

int disDigitSame(int a, int b, int c);

int main()
{
    int s[100], y, x, z = 0;

    for (int j = 0; j <= 9; j++)
        for (int i = 1; i <= 9; i++)
            for (int k = 1; k <= 9; k++)
            {
                if (i == j || i == k || j == k)
                    continue;
                y = k + j * 10 + i * 100;
                x = sqrt(y);
                if (x * x == y)
                    s[z++] = y;
            }

    for (int i = 0; i < z - 1; i++)
    {
        for (int ii = i + 1; ii < z; ii++)
        {
            if (s[i] > s[ii])
            {
                int t = s[i];
                s[i] = s[ii];
                s[ii] = t;
            }
        }
    }

    // printf("%d\n", z);
    for (int i = 0; i < z; i++)
        for (int j = i; j < z; j++)
            for (int k = j; k < z; k++)
            {
                if (disDigitSame(s[i], s[j], s[k]))
                {
                    printf("%d %d %d\n", s[i], s[j], s[k]);
                }
            }
    return 0;
}

int disDigitSame(int a, int b, int c)
{
    int digit[10] = {0}, i;
    while (a)
    {
        i = a % 10;
        digit[i]++;
        a /= 10;
    }
    while (b)
    {
        i = b % 10;
        digit[i]++;
        b /= 10;
    }
    while (c)
    {
        i = c % 10;
        digit[i]++;
        c /= 10;
    }
    for (i = 1; i <= 9; i++)
    {
        if (digit[i] != 1)
            return 0;
    }
    return 1;
}
