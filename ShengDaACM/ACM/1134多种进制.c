#include <stdio.h>
#include <string.h>

#define N 233
void kToD(int n, int k);

int main()
{
    int n;
    scanf("%d", &n);
    kToD(n, 2);
    kToD(n, 3);
    kToD(n, 7);
    kToD(n, 8);
    return 0;
}
void kToD(int n, int k)
{
    int len = 0;
    char str[N];
    while (n != 0)
    {
        str[len++] = (n % k) + '0';
        n /= k;
    }
    for (int i = len - 1; i >= 0; i--)
        printf("%c", str[i]);
    printf("\n");
}