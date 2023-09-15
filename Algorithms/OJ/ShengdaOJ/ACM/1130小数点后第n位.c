#include <stdio.h>
#include <math.h>
#define N 23333
int a[N] = {0};

int main()
{
    int i, n, m, j;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        double num, _num;
        scanf("%lf", &num);
        _num = num - (int)num; //仅保留小数部分
        for (j = 1; j <= N; j++)
        {
            _num *= 10;
            a[j] = (int)(_num);
            _num = fabs(_num - a[j]);
            if (_num <= fabs(0.000001))
                break;
        }
        scanf("%d", &m);
        if (m > j )
            printf("0");
        else
            printf("%d\n", a[m]);
    }
    return 0;
}