#include <stdio.h>

#define N 10000

int MinIndex(int a[], int n); //函数返回数组a中最小元素的下标
int MaxIndex(int a[], int n); //函数返回数组a中最大元素的下标
void PrintArr(int a[], int n);

int main()
{
    int a[N], n, t, minI, maxI;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    minI = MinIndex(a, n);//根据题目输出事例 先替换最小值
    t = a[0];
    a[0] = a[minI];
    a[minI] = t;

    maxI = MaxIndex(a, n);//此函数必须放在处理最小值后 否则数组顺序会被打乱
    t = a[n - 1];
    a[n - 1] = a[maxI];
    a[maxI] = t;

    PrintArr(a, n);
    return 0;
}

int MinIndex(int a[], int n)
{
    int min = a[0], minI = 0;
    for (int i = 1; i < n; i++)
    {
        if (min > a[i])
        {
            min = a[i];
            minI = i;
        }
    }
    return minI;
}

int MaxIndex(int a[], int n)
{
    int max = a[0], maxI = 0;
    for (int i = 1; i < n; i++)
    {
        if (max < a[i])
        {
            max = a[i];
            maxI = i;
        }
    }
    return maxI;
}

void PrintArr(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            printf("%d", a[i]);
        else
            printf(" %d", a[i]);
    }
}