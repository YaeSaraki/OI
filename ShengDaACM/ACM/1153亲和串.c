#include <stdio.h>
#include <string.h>

int main()
{
    char a[2000002], b[1000001], c[1000001];
    while (scanf("%s%s", a, b) != EOF)
    {
        int len1 = strlen(a);
        int len2 = strlen(b);
        if (len1 < len2)
            printf("no\n");
        else
        {
            strcpy(c, a);
            strcat(a, c);
            if (strstr(a, b) != NULL)
                printf("yes\n");
            else
                printf("no\n");
        }
    }
    return 0;
}