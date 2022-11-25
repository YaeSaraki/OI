#include <stdio.h>
#include <limits.h>

#define N 999999

void convert(char c[], int n);

int main()
{
    int n;
    char c[N];
    scanf("%d", &n);
    convert(c, n);
    return 0;
}

void convert(char c[], int n)
{
    int i = 1;
    if (n == 0)//注意n为0的情况!!!!
    {
        printf("0");
    }
    while (n)
    {
        c[i++] = n % 2;
        n /= 2;
    }

    for (int j = i - 1; j >= 1; j--)
        printf("%d", c[j]);
}
