#include <stdio.h>
#include <string.h>

int main()
{
    char str[21];
    char a[] = "s", b[] = "es";
    int len;
    // 输入一个仅含小写字母的字符串
    gets(str);
    len = strlen(str) - 1;
    // 判断结尾字符是否符合相应条件
    if (str[len] == 'o' || str[len] == 's' || str[len] == 'x' ||
         (str[len - 1] == 'c' || str[len - 1] == 's') && str[len] == 'h')
    
        // 调用函数strcat()进行字符连接
        strcat(str, b);
    else if (str[len] == 'y')
    {
        str[len] = 'i';
        strcat(str, b);
    }
    else
        strcat(str, a);
    // 输出数组元素
    puts(str);
    return 0;
}
