#include <stdio.h>
#include <string.h>

#define N 1000
int main()
{
    char a[N], b[N];
    int n, len = 1000;
    scanf("%d", &n);
    getchar();
    while (n--)
    {
        memset(a, 0, sizeof(a));
        gets(a);
        if (strlen(a) < len)
        {
            len = strlen(a);
            strcpy(b, a);
        }
    }
    puts(b);
    return 0;
}