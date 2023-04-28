#include <stdio.h>
#include <string.h>

#define N 1000

int main()
{
    int n;
    char str[N];
    scanf("%d", &n);
    getchar();
    while (n--)
    {
        int sum = 0;
        gets(str);
        for (int i = 0; i < strlen(str); i++)
        {
            if ('0' <= str[i] && str[i] <= '9')
                sum++;
        }
        printf("%d\n", sum);
    }
    return 0;
}
