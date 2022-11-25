#include<stdio.h>
#define N 10001

int main()
{

    int a[N];
    int i, j, k, t, n;
    int len, maxlen;
    // 输入t，表示t组数据
    scanf("%d", &t);
    while (t--)
    {

        len = 1;
        maxlen = 1;
        // 输入n
        scanf("%d", &n);
        for (i = 0; i < n; i++)
        {

            scanf("%d", &a[i]);
        }
        // 比较交换排序
        for (i = 0; i < n - 1; i++)
        {

            for (j = i + 1; j < n; j++)
            {

                if (a[j] < a[i])
                {

                    k = a[i];
                    a[i] = a[j];
                    a[j] = k;
                }
            }
        }

        for (i = 1; i < n; i++)
        {

            if (a[i] == a[i - 1])
                len++;
            else
                len = 1;
            if (len > maxlen)
                maxlen = len;
        }
        printf("%d\n", maxlen);
    }
    return 0;
}