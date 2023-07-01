#include <stdio.h>

int main()
{
    int t, n, num;
    scanf("%d", &t);
    while (t--)
    {
        int sum = 0, max = 0;//变量初始位置要注意!!!!
        scanf("%d", &n);
        while (n--)
        {
            scanf("%d", &num);
            max = (max > num) ? max : num;
            sum += num;
        }
        if (sum - max >= max - 1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}