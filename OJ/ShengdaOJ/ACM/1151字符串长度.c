#include <stdio.h>
int len(char *sp);
int main()
{
    char a[100];
    gets(a);
    printf("%d", len(a));
    return 0;
}
int len(char *sp)
{
    int sum = 0, i = 0;
    while (*(sp++) != '\0') //递增指针，使指针指向数组下一位置
        if (*sp != ' ')
            sum++;
    return sum;
}
