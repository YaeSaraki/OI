#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    char a[200];
    int i, max = 0;
    gets(a);
    int len = strlen(a);
    for (i = 0; i < len; i++) //找到ASCLL码最大的元素，保存下来，记为max
    {
        if (a[i] >= max)
        {
            max = a[i];
        }
    }

    for (i = 0; i < len; i++) //遍历数组找到元素值为max的，进行打印（不用把max放入数组）
    {
        if (a[i] == max)
        {
            printf("%c(max)", a[i]); //元素值为max的这样打印
        }
        else
        {
            printf("%c", a[i]); //否则这样打印
        }
    }
}
