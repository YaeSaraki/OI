#include <stdio.h>
#include <string.h>

int main()
{
    int len, len1, len2, T, k;
    char a[1000], b[1000];
    int num1[1000] = {0}, num2[1000] = {0};
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s%s", a, b);
        len1 = strlen(a);
        len2 = strlen(b);
        len = (len1 > len2) ? len1 : len2;

        memset(num1, 0, sizeof(int) * (len + 1));
        memset(num2, 0, sizeof(int) * (len + 1));

        for (int i = len1 - 1, k = 0; i >= 0; i--)
        {
            num1[k++] = a[i] - '0';
        }
        for (int i = len2 - 1, k = 0; i >= 0; i--)
        {
            num2[k++] = b[i] - '0';
        }
        for (int i = 0; i < len; i++)
        {
            num1[i] += num2[i];
            if (num1[i] >= 10)
            {
                num1[i + 1]++;
                num1[i] -= 10;
            }
        }
        if (num1[len] > 0)
            printf("%d", num1[len]);
        for (int i = len - 1; i >= 0; i--)
            printf("%d", num1[i]);
        printf("\n");
    }
    return 0;
}