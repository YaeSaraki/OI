#include <stdio.h>
#include <math.h>

int digitSum(int n);

int main()
{
    int n;
    scanf("%d", &n);
    while (n > 9)
        n = digitSum(n);
    printf("%d", n);
    return 0;
}

int digitSum(int n)
{
    int Sum = 0;
    while (n != 0)
    {
        Sum += n % 10;
        n /= 10;
    }
    return Sum;
}