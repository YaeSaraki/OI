#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 10000

void input(char *str);
int judge(char *tA, char *sA);

int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    while (n--)
    {
        char trueAnwser[N], submitAnswer[N];
        //初始化
        memset(trueAnwser, 0, sizeof(trueAnwser));
        memset(submitAnswer, 0, sizeof(submitAnswer));

        input(trueAnwser);
        input(submitAnswer);

        int result = judge(trueAnwser, submitAnswer);

        if (result == 0)
            printf("Accepted\n");
        else if (result == 1)
            printf("Presentation Error\n");
        else if (result == -1)
            printf("Wrong Answer\n");
    }
    return 0;
}

void input(char *str)
{
    while (1)
    {
        char temp[N] = {0};
        gets(temp);
        if (strcmp(temp, "START") == 0)
            continue;
        if (strcmp(temp, "END") == 0)
            break;
        if (temp[0] == 0)
            strcat(str, "\n"); // 如果不判断为空的情况加上一个换行符的话，有可能会把presentation  变成 Accept（错误点）
        else
            strcat(str, temp);
    }
}

int judge(char *tA, char *sA)
{
    if (strcmp(tA, sA) == 0)
        return 0;
    char s1[N] = {0}, s2[N] = {0};

    for (int i = 0, k = 0; tA[i] != '\0'; i++)
        if (tA[i] != ' ' && tA[i] != '\n' && tA[i] != '\t')
            s1[k++] = tA[i];
    for (int i = 0, k = 0; sA[i] != '\0'; i++)
        if (sA[i] != ' ' && sA[i] != '\n' && sA[i] != '\t')
            s2[k++] = sA[i];

    if (strcmp(s1, s2) == 0)
        return 1;
    else
        return -1;
}