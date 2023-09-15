#include <stdio.h>
#include <string.h>
int main()
{
    int t, j, i, n, len, a;
    char str[101];
    scanf("%d", &t);
    for (i = 0; i < t; i++)
    {
        scanf("%s %d", &str, &n);
        len = strlen(str);
        a = 0;
        for (j = 0; j < len; j++)
        {
            if (str[j] == '.')
                break;
            a++; //这个a你会发现它既是小数点前有几个数，又是小数点儿的下标，因为下标是从0开始的
        }
        if (n > len - a - 1) //这是n大于小数点数的情况
            printf("0\n");
        else
        {
            printf("%c\n", str[a + n]); //这就是小数点儿后的第n位数
        }
    }
    return 0;
}