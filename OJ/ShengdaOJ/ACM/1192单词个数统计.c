#include <stdio.h>
#include <string.h>

#define N 1000

int main()
{
    int sum = 0;
    char str[N];
    gets(str);
    if (str[0] != ' ')
        sum = 1;
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] == ' ' && str[i + 1] != ' ' && str[i + 1] != '\0')
            sum++;
    }
    printf("%d", sum);
    return 0;
}