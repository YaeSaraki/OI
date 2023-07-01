
#include<stdio.h>
#include<string.h>
 
int main()
{
    char s1[10001],s2[10001];
    int i;
    while(scanf("%s%s",s1,s2)!=EOF)
    {
        for(i=0;i<strlen(s1);i++)
        {
            if(s1[i]>='a')
                s1[i]=(s1[i]-'a')*2+1;
            else if(s1[i]>='A')
                s1[i]=(s1[i]-'A')*2;
        }
        for(i=0;i<strlen(s2);i++)
        {
            if(s2[i]>='a')
                s2[i]=(s2[i]-'a')*2+1;
            else if(s2[i]>='A')
                s2[i]=(s2[i]-'A')*2;
        }
        if(strcmp(s1,s2)<0)
            printf("YES\n");
        else
            printf("NO\n");
    }
	return 0;
}
