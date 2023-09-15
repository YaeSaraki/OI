#include <stdio.h>
#include <string.h>

int main()
{
    int t = 1, len, sum = 0;
    char str[50];
    scanf("%s", str);
    len = strlen(str);
    for (int i = len - 1; i >= 0; i--)
    {
        if (str[i] > '4')
            str[i]--;
        sum += (str[i] - '0') * t;
        t *= 9;
    }
    printf("%d", sum);
    return 0;
}