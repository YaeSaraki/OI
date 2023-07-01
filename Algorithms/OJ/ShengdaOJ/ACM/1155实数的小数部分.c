#include <stdio.h>
#include <string.h>

char ans[110];
char *decimal(char *p);

int main()
{
    char str[100];
    scanf("%s", str);

    memset(ans, 0, sizeof(ans));

    if (strlen(decimal(str)) == 2)
        printf("No decimal part");
    else
        puts(ans);
        
    return 0;
}

char *decimal(char *p)
{
    int j = 1, len = strlen(p), flag = 0;
    ans[0] = '0';
    for (int i = 0; i < len; i++)
    { //将小数点后的全部截取
        if (p[i] == '.') 
        {
            ans[j] = p[i];
            j++;
            flag = 1;
            continue;
        }
        if (flag == 1)
        {
            ans[j] = p[i];
            j++;
        }
    }
    ans[j] = '\0';
    j--;
    while (ans[j] == '0')
    { //去掉后置0
        ans[j] = '\0';
        j--;
    }
    return ans;
}