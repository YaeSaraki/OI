#include <stdio.h>

int disDigitSame(int a, int b, int c);

int main()
{
    int a, b, c;
    for (int a = 1; a <= 333; a++)
    {
        b = 2 * a;
        c = 3 * a;
        int t = disDigitSame(a, b, c);
        if (t == 1)
            printf("%d %d %d\n", a, b, c);
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