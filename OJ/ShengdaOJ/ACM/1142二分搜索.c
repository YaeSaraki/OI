#include <stdio.h>

int BinarySearch(int a[], int x, int n)
{
    int begin = 0, end = n - 1, mid; //
    while (begin <= end)
    {
        mid = (begin + end) / 2; //将数组从中一分为二
        if (a[mid] == x)         //判断中间位置的数与要查找的数的关系
            return mid;          //相等返回数的位置
        //不相等改变范围，重新进行二分查找
        if (a[mid] < x) //右侧查
            begin = mid + 1;
        else //左侧查找
            end = mid - 1;
    }
    return -1;
}

int main()
{
    int a[1000001], b[1000001];
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);
    for (int i = 0; i < m; i++)
    {
        int y;
        y = BinarySearch(a, b[i], n);
        if (y >= 0)
            printf("%d\n", y);
        else
            printf("Not found!\n");
    }
    return 0;
}