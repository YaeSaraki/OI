#include<stdio.h>
#include<string.h>
char str[1001];
int n,num=0;  

void judge (int a,int b);    //num记录连续n个1的个数

int main(void)
{
    int i,temp=0;
    scanf("%s %d",str,&n);
    for(i=0;i<strlen(str);i++)
        judge(i,temp);
    printf("%d",num);
    return 0;
}

void judge(int a,int b)     //判断第a个字符时已经有连续b个1
{
    if(b==n)            //满足连续n个1时结束递归
    {
        num++;
        return;
    }
    if(str[a]=='1')     
    {
        b++;
        judge(a+1 ,b);       //判断下一位
    }
}