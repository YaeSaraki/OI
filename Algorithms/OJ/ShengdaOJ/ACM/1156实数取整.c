#include <stdio.h>
#include <string.h>

char out[100000] = {0};

char *rounding(char *p);

int main()
{
    char str[100000];
    gets(str);
    puts(rounding(str));
    return 0;
}

char *rounding(char *p)
{
    int flag = 0, k = 0;
    int len = strlen(p);
    for (int i = 0; i < len; i++)
    {
        if (flag == 0 && p[i] == '0')
            continue;
        else if (p[i] == '.')
            break;
        else
            flag = 1;
        if (flag == 1)
            out[k++] = p[i];
    }
    out[k] = '\0';
    return out;
}