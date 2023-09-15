#include <stdio.h>
#include <stdbool.h>

int n;
int map[12][12];
bool IsUpperTriMatrix()
{
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (map[i][j])
                return false;
    return true;
}
int main()
{
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &map[i][j]);
        printf("%s", IsUpperTriMatrix() ? "YES" : "NO");
    }
    return 0;
}