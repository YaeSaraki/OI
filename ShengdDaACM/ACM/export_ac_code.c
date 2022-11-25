202205050342
Problem1000:
#include <stdio.h>
int main()
{
    int a, b, out;
    scanf("%d%d", &a, &b);
    out = a + b;
    printf("%d", out);
    return 0;
}
------------------------------------------------------
Problem1000:
#include <stdio.h>
int main()
{
    int a, b, out;
    scanf("%d%d", &a , &b);
    out = a + b;
    printf("%d", out);
    return 0;
}
------------------------------------------------------
Problem1002:
#include <stdio.h>
int main()
{
	int x, y;
	scanf("%d", &x);
	y = (2 * x * x) + x + 8;
	printf("%d", y);
	return 0;       
}
------------------------------------------------------
Problem1002:
#include <stdio.h>
int main()
{
	int x;
	scanf("%d", &x);
	printf("%d", 2 * x * x + x + 8);
	return 0;       
}
------------------------------------------------------
Problem1003:
#include <stdio.h>
int main()
{
	int num1, num2;
	scanf("%d%d", &num1, &num2);
	printf("%d\n%d\n%d\n%d\n%d", num1 + num2, num1 - num2, num1 * num2, num1 / num2, num1 % num2);
	return 0;
}
------------------------------------------------------
Problem1008:
#include <stdio.h>
#define Exc 6.5573
int main()
{
	float rmb, dor;
	scanf("%f", &dor);
	rmb = dor * Exc;
	printf("%.2f", rmb);

	
	return 0; 
}
------------------------------------------------------
Problem1010:
#include <stdio.h>
#define PI 3.14159
int main()
{
	double r, l, s;
	scanf("%lf", &r);
	l = 2*r*PI;
	s = r * r * PI;
	printf("%.2lf %.2lf", l, s);
	return 0;
	 
}

------------------------------------------------------
Problem1011:
#include <stdio.h>
#define PI 3.14159
int main()
{
	double r, h, s;
	scanf("%lf%lf", &r, &h);
	s = (2 * r * r * PI) + (2 * r * PI * h);
	printf("%.2lf", s);
	return 0;
	 
}

------------------------------------------------------
Problem1012:
int main()
{
    double input, out;
    scanf("%lf", &input);
    out = fabs(input);
    printf("%.2lf", out);
    return 0;
}

------------------------------------------------------
Problem1016:
#include <stdio.h>
#include <math.h>
#define PROFIT 0.0225

int main()
{
    int n;
    double deposit, sum;
    scanf("%d%lf", &n, &deposit);
    sum = pow((1 + PROFIT), n)*deposit;
    printf("%.6lf", sum);
    return 0;
}
------------------------------------------------------
Problem1017:
#include <stdio.h>
#include <math.h>

int main()
{
    int n, x;
    scanf("%d", &n);
    x = (int)log10(n)+1;
    printf("%d", x);
    return 0;
}
------------------------------------------------------
Problem1019:
#include <stdio.h>
#include <math.h>
#define PRICE 50

int main()
{
    float n;
    scanf("%f", &n);
    if (n < 30)
        printf("%.2f", n*PRICE);
    else
        printf("%.2f", n*(PRICE-2));

    return 0;
}
------------------------------------------------------
Problem1020:
#include <stdio.h>
#include <math.h>

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    if (b >= a)
        printf("%d %d", a, b);
    else
        printf("%d %d", b, a);
    return 0;
}
------------------------------------------------------
Problem1020:
#include <stdio.h>
#include <math.h>
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    if (b >= a)
        printf("%d %d", a, b);
    else
        printf("%d %d", b, a);
    return 0;
}
------------------------------------------------------
Problem1021:
#include <stdio.h>
int main()
{
    int a, b, c, max;
    scanf("%d%d%d", &a, &b, &c);
    max = a;
    if (b > max)
        max = b;
    if (c > max)
        max = c;
    printf("%d", max);
    return 0;
}
------------------------------------------------------
Problem1021:
#include <stdio.h>
int main()
{
    int a, b, c, max;
    scanf("%d%d%d", &a, &b, &c);
    max = (a > b) ? a : b;
    max = (c > max) ? c : max;
    printf("%d", max);
    return 0;
}
------------------------------------------------------
Problem1023:
#include <stdio.h>
int main()
{
    char c;
    scanf("%c", &c);
    if (c >= 97)
        printf("%c", c - 32);
    else
        printf("%c", c);
    return 0;
}
------------------------------------------------------
Problem1024:
#include<stdio.h>
int main()
{
	char a;
	a = getchar();
	if (a >=97)
		printf("%d", a-96);
	else 
		printf("%d", a-64);
	return 0;
}

------------------------------------------------------
Problem1025:
#include<stdio.h>
int main()
{
	char a, b, c, max;
	scanf("%c %c %c",&a ,&b ,&c);
	max = a;
	max = c>max?c:max;
	max = b>max?b:max;
	printf("%c", max);
	return 0;
}
------------------------------------------------------
Problem1026:
#include<stdio.h>
int main()
{
	char ch;
	scanf("%c", &ch);
	if (ch<='Z' && ch>='A')
		printf("upper");
	else if (ch<='z' && ch>='a')
		printf("lower");
	else if (ch<='9' && ch>='0')
		printf("digit");
	else 
		printf("other");
	return 0;
}
------------------------------------------------------
Problem1029:
#include<stdio.h>
#include<math.h>
int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if ((a+b)>c && fabs(a-b)<c)
		printf("Yes");
	else 
		printf("No");
	return 0;
}
------------------------------------------------------
Problem1030:
#include<stdio.h>
#include<math.h>
int main()
{
	int a, b, c, t;
	scanf("%d%d%d", &a, &b, &c);
	if (b>a)
	{
		t = a;
		a = b;
		b = t;
	}
	if (c>a)
	{
		t = a;
		a = c;
		c = t;
	}
	if (c>b)
	{	t = b;
		b = c;
		c = t;
	}
	if (b+c>a && a-b<c && c*c+b*b==a*a )
		printf("yes");
	else 
		printf("no");
	return 0;
}
------------------------------------------------------
Problem1031:
#include <stdio.h>
int main()
{
    double x, y;
    scanf("%lf%lf", &x, &y);
    if (x>0)
    {
        if (y>0)
            printf("1");
        else
            printf("4");
    }
    else
    {
        if (y>0)
            printf("2");
        else
            printf("3");
    }

    return 0;
}
------------------------------------------------------
Problem1031:
#include <stdio.h>
int main()
{
    int x, y;
    scanf("%d%d", &x, &y);
    if (x>0)
    {
        if (y>0)
            printf("1");
        else
            printf("4");
    }
    else
    {
        if (y>0)
            printf("2");
        else
            printf("3");
    }

    return 0;
}
------------------------------------------------------
Problem1032:
#include <stdio.h>
#define Q 1500
int main()
{
    double profit, a, b, c;
    scanf("%lf", &profit);

    a = Q + 10000 * 0.05;
    b = 40000 * 0.03;
    c = (profit - 50000) * 0.02;

    if (profit < 10000)
        printf("%.2lf", Q + profit * 0.05);
    else if (profit > 10000 && profit < 50000)
        printf("%.2lf", a + (profit-10000) * 0.03);
    else
        printf("%.2lf", a + b + c);
    return 0;
}
------------------------------------------------------
Problem1033:
#include <stdio.h>

int main()
{
    int a;
    scanf("%d", &a);
    if (a>=90)
        printf("A");
    else if (80<=a && a<=89)
        printf("B");
    else if (70<=a && a<=79)
        printf("C");
    else if (60<=a && a<=69)
        printf("D");
    else 
        printf("E");
    return 0;
}
------------------------------------------------------
Problem1035:
#include <stdio.h>
#include <math.h>

int main()
{
    double x;
    scanf("%lf", &x);
    if (x < -2)
        printf("%.0lf", 7 - 2 * x);
    else if (-2 <= x && x < 3)
        printf("%.0lf", 5 - fabs(3 * x + 2));
    else
        printf("%.0lf", 3 * x + 4);
    return 0;
}
------------------------------------------------------
Problem1036:
#include <stdio.h>
#include <math.h>

int main()
{
    int year, month;
    scanf("%d%d", &year, &month);
    switch (month)
    {
    case 4:
    case 6:
    case 9:
    case 11:
        printf("30");
        break;
    case 2:
        if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
            printf("29");
        else
            printf("28");
        break;
    default:
        printf("31");
    }
return 0;
}
------------------------------------------------------
Problem1037:
#include <stdio.h>
#include <math.h>

int main()
{
    double s1, s2, result,_error_;
    char op;
    _error_ = 0;
    scanf("%lf %c %lf", &s1, &op, &s2);
    switch (op)
    {
    case '+':
        result = s1 + s2;
        break;
    case '-':
        result = s1 - s2;
        break;
    case '*':
        result = s1 * s2;
        break;
    case '/':
        if (fabs(s2) > 1e-10)
            result = s1 / s2;
        else
            _error_ = 1;
        break;
    default:
        _error_ = 1;
        break;
    }
    if (_error_ == 0)
        printf("%.2lf", result);
    else 
        printf("Wrong input!");
return 0;
}
------------------------------------------------------
Problem1038:
#include <stdio.h>
#include <math.h>
int main()
{
    double a, b, c;
    double max;
    scanf("%lf%lf%lf", &a, &b, &c);
    max = fabs(a);
    max = (fabs(b) > max) ? fabs(b) : max;
    max = (fabs(c) > max) ? fabs(c) : max;
    if (fabs(max - a) < 1e-10 || fabs(max + a) < 1e-10)
        printf("%.0lf", a);
    else if (fabs(max - b) < 1e-10 || fabs(max + b) < 1e-10) 
        printf("%.0lf", b);
    else 
        printf("%.0lf", c);

    return 0;
}
------------------------------------------------------
Problem1039:
#include <stdio.h>
#include <math.h>
int main()
{
    int i, n, num, sum;
    sum = 0;
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        scanf("%d", &num);
        sum += num;
    }
    printf("%d", sum);
    return 0;
}
------------------------------------------------------
Problem1040:
#include <stdio.h>
int main()
{
    double sum;
    int n, i;
    sum = 0.0;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        sum += 1.0 / (2 * i - 1);
    printf("%.2lf", sum);
}
------------------------------------------------------
Problem1040:
#include <stdio.h>
int main()
{
    double sum;
    int n, i, deno;
    sum = 0.0;
    deno = 1;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        sum += 1.0 / deno;
        deno += 2;
    }
    printf("%.2lf", sum);
    return 0;
}
------------------------------------------------------
Problem1041:
#include <stdio.h>
int main()
{
    double sum, flag;
    int n, i, deno;
    sum = 0.0;
    deno = 1;
    flag = 1;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        sum += flag * 1.0 / deno;
        deno += 2;
        flag = - flag ;
    }
    printf("%.2lf", sum);
    return 0;
}
------------------------------------------------------
Problem1042:
#include <stdio.h>
int main()
{
    double sum, flag;
    int n, i, deno, lala;
    sum = 0.0;
    deno = 1;
    flag = 1;
    lala = 1;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        sum += flag * lala / deno;
        lala += 1;
        deno += 2;
        flag = - flag ;
    }
    printf("%.3lf", sum);
    return 0;
}
------------------------------------------------------
Problem1043:
#include <stdio.h>
int main( )
{
int n, i, num , max ;
scanf("%d", &n);
scanf("%d", &num);
max=num;
for(i = 1; i < n; i++)
{
scanf("%d", &num);
if(max < num)
max = num;
}
printf("%d\n", max);
return 0;
}
------------------------------------------------------
Problem1044:
#include <stdio.h>
int main()
{
    int i, n;
    double sum, mark, d;
    d = 0;
    scanf("%d", &n);
    for (i = 1; i <= n; ++i)
    {
        scanf("%lf", &mark);
        if (mark < 60)
            d++;
    }
    printf("%.2lf", d / n);
    return 0;
}
------------------------------------------------------
Problem1045:
#include <stdio.h>
int main()
{
    int i, n, num, f, o, z;
    f = 0;
    o = 0;
    z = 0;
    scanf("%d", &n);
    for (i = 1; i <= n; ++i)
    {
        scanf("%d", &num);
        if (num < 0)
            f++;
        else if (num == 0)
            o++;
        else
            z++;
    }
    printf("%d %d %d", f, o, z);
    return 0;
}
------------------------------------------------------
Problem1046:
#include <stdio.h>
int main()
{
    int i, n, num, sum;
    sum = 1;
    scanf("%d", &n);
    for (i = 1; i <= n; ++i)
    {
        scanf("%d", &num);
        if (0 != num % 2 )
            sum *=num;
    }
    printf("%d", sum);
    return 0;
}
------------------------------------------------------
Problem1047:
#include <stdio.h>
#include <math.h>
int main()
{
    int i, m, n;
    scanf("%d%d", &m, &n);
    for (i = m; i <= n; ++i)
    {
        printf("%4d%8.4lf\n",i, log(i));
    }
    return 0;
}
------------------------------------------------------
Problem1048:
#include <stdio.h>
#include <math.h>
int main()
{
    double a, i, n;
    scanf("%lf", &n);
    a = 1;
    printf("%-4.0lf%-20.0lf\n", a, a);
    for (i = 2; i <= n; ++i)
    {
        a = a * i;
        printf("%-4.0lf%-20.0lf\n",i, a);
    }
    return 0;
}
------------------------------------------------------
Problem1049:
#include <stdio.h>
#include <math.h>
int main()
{
    int m, n, jsum, osum, i;
    jsum = 0;
    osum = 0;
    scanf("%d%d", &m, &n);
    for (i = m; i <= n; ++i)
    {
        if (i % 2 == 0)
            osum += i * i;
        else
            jsum += i * i * i;
    }
    printf("%d %d", osum, jsum);
    return 0;
}
------------------------------------------------------
Problem1050:
#include <stdio.h>
int main()
{
    int i = 0;
    int n = 0;
    int num = 0;
    int ret = 1;
    scanf("%d", &n);
    for (i = 1; i <= n; ++i)
    {
        ret *= i;  
        num += ret; 
    }
    printf("%d\n", num);
    return 0;
}
------------------------------------------------------
Problem1050:
#include <stdio.h>
#include <math.h>
int main()
{
    int sum, a, m, n, i;
    scanf("%d", &n);
    a = 1;
    i = 1;
    sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        a = a * i;
        sum += a;
    }
    printf("%d", sum);
    return 0;
}
------------------------------------------------------
Problem1051:
#include <stdio.h>
#include <math.h>
int main()
{
    int i = 0;
    int n = 0;
    double item = 0;
    scanf("%lf%d", &item ,&n);
    double num = item;
    for (i = 2; i <= n; ++i)
    {
        item = sqrt(item);  
        num += item; 
    }
    printf("%.2lf\n", num);
    return 0;
}
------------------------------------------------------
Problem1052:
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n,a,item,sum;
    scanf("%d%d",&n,&a);
    item=0;
    sum=0;
    for(i=1;i<=n;i++)
    {
        item=item*10+a;
        sum+=item;
    }
    printf("%d\n",sum);

    return 0;
}

------------------------------------------------------
Problem1052:
#include <stdio.h>
#include <math.h>
int main()
{
    int i = 0;
    int a = 0;
    int n = 0;
    int b = 0;
    int sum = 0;
    scanf("%d%d", &n, &a);
    for (i = 1; i <= n; ++i)
    {
        b = b * 10 + a;
        sum += b;
    }
    printf("%d", sum);
    return 0;
}
------------------------------------------------------
Problem1053:
#include <stdio.h>
int main()
{
    int flag = 1;
    double x;
    double b = 1;
    scanf("%lf", &x);
    double d = x;
    double sum = 0;
    for (int i = 1; i <= 10; i++)
    {
        sum += d * flag / b;
        d *= x * x;
        flag = -flag;
        b *= 2 * i * (2 * i + 1);
    }
    printf("%.3lf", sum);
    return 0;
}
------------------------------------------------------
Problem1054:
#include <stdio.h>
int main()
{
    int n, a, all, part;
    part = 1;
    all = 0;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        all = part;
        part = (part + 1) * 2;
    }
    printf("%d", all);
    return 0;
}
------------------------------------------------------
Problem1055:
#include <stdio.h>
int main()
{
    int n, a, b, c, sum;
    a = 1;
    b = 1;
    c = 1;
    scanf("%d", &n);
    if (n <= 2)
        printf("1");
    else
    {
        for (int i = 3; i <= n; i++)
        {
            b = c;
            sum = a + b;
            a = b;
            c = sum;
        }
        printf("%d", sum);
    }
    return 0;
}
------------------------------------------------------
Problem1056:
#include <stdio.h>
int main()
{
    double x, sum;
    scanf("%lf", &x);
    sum = 0;
    for (int i = 1; i <= 5; i++)
    {
        sum += 1000;
        sum /= 1 + 12 * x;
    }
    printf("%.2lf", sum);
    return 0;
}
------------------------------------------------------
Problem1057:
#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int state = 1;
    for (int i = 2; i <= 1000; i++)
    {
        if (i == n)
            continue;
        else if (n % i == 0 || n == 1)
        {
            state = 0;
            break;
        }
    }
    if (state == 1)
        printf("Yes");
    else
        printf("No");
    return 0;
}
------------------------------------------------------
Problem1058:
#include<stdio.h>
#include<math.h>
int main()
{
	int a, n;
	double sum;
	sum = 0;
	a = 1;
	scanf("%d", &n);
	for (int i=1;;i++)
	{
		a*=i;
		sum +=a;
		if (sum>=n)
		{
		
			printf("m<=%d", (i-1));
			break;
		}
		
	}
	return 0;
}
------------------------------------------------------
Problem1059:
#include<stdio.h>
#include<math.h>
int main()
{
	int a, max;
	a = 0;
	max = 0;
	for (int i=1;;i++)
	{
		scanf("%d", &a);
		if (a<=0)
			break;
		max = (a>max)?a:max;		
	}
	printf("%d", max);
	return 0;
}

------------------------------------------------------
Problem1060:
#include<stdio.h>
#include<math.h>
int main()
{
	int a, n;
	a = 0;
	scanf("%d", &n);
	for (int i;;i++)
	{
		if (n>=10)
		{
			a = n%10;
			n = n/10;
			printf("%d ", a);
		}
		else 
		{
			printf("%d", n);
			break;
		}	
	}
	return 0;
}



------------------------------------------------------
Problem1061:
#include<stdio.h>
#include<math.h>
int main()
{
	int t,num =0;
	int mask = 1;
	scanf("%d", &num);
	t = num;
	while (t>9)
	{
		t/=10;
		mask*=10;	
	}	
	while(mask>0)
	{
	 	printf("%d ", num/mask)	;
	 	num %=mask;
	 	mask/=10;
	}
    return 0;
}
	
------------------------------------------------------
Problem1062:
#include<stdio.h>
#include<math.h>
int main()
{
	
	int num,num1,num2,t=1;
	scanf("%d%d", &num1, &num2);
	if (num1<num2)
	{
	    num = num1;
	    num1 = num2;
	    num2 = num;
	}
	while (t)
	{
	t = num1%num2;
	num1 = num2;
	num2 = t;
	}	
	printf("%d", num1);
    return 0;
}
------------------------------------------------------
Problem1062:
#include <stdio.h>
#include <math.h>
int m, n;
int gcd();
int main()
{
    scanf("%d%d", &m, &n);
    printf("%d", gcd(m, n));
    return 0;
}
int gcd(m, n)
{
    if (m % n == 0)
        return n;
    else
        return gcd(n, m % n);
}
------------------------------------------------------
Problem1063:
#include<stdio.h>
#include<math.h>
int main()
{
	
	int num,num1,num2,t=1;
	scanf("%d%d", &num1, &num2);
	if (num1<num2)
	{
	    num = num1;
	    num1 = num2;
	    num2 = num;
	}
	double n = num1;
	double m = num2;
	while (t)
	{
	t = num1%num2;
	num1 = num2;
	num2 = t;
	}	
	printf("%d ", num1);
	double c = n*m/num1;
	printf("%.0lf", c);
    return 0;
}
------------------------------------------------------
Problem1064:
#include<stdio.h>
int main()
{
	char ch;
	while ((ch = getchar()) != '@')
	{
	    if (ch >= 'A' && ch <= 'Y')
            ch+= 32;
        if (ch == 'Z' || ch == 'z')
            ch= 'a';
        else if (ch >= 'a' && ch <= 'y')
            ch++;
        putchar(ch);
    }
    printf("\n");
	return 0;
}
------------------------------------------------------
Problem1065:
#include<stdio.h>
int main()
{
	char ch;
	int count= 0;
	while (ch =getchar(),ch != '\n')
	{
	    if ('0'<= ch && ch <='9')
	    	count++;
    }
    printf("%d", count);
	return 0;
}
------------------------------------------------------
Problem1066:
#include<stdio.h>
int main()
{
	char ch;
	int digit=0, letter=0, other= 0;
	while (ch =getchar(),ch != '\n')
	{
	    if ('0'<= ch && ch <='9')
	    	digit++;
	    else if (('A'<=ch && ch <='Z')||('a'<= ch && ch <='z'))
	    	letter++;
	    else 
	    	other++;
    }
    printf("letter:%d\n", letter);
	printf("digit:%d\n", digit);
	printf("other:%d\n", other);
	return 0;
}
------------------------------------------------------
Problem1067:
#include <stdio.h>
int main()
{
    int num;
    scanf("%d", &num);
    int sum = 0, w = 1;
    while (num != 0)
    {
        int n = num % 10;
        if (n > 4)
            n--;
        sum += n * w;
        w *= 9;
        num /= 10;
    }
    printf("%d", sum);
    return 0;
}
------------------------------------------------------
Problem1068:
#include<stdio.h>
int main()
{
	char ch;//定义字符ch
    int d=0;//初始化d为0
    while(ch=getchar(), ch!='\n')//当输入不等于换行符时，继续进行操作
        d=d*2+(ch-'0');//进行二进制计算每次结果*2，相当于往前递推一位
    printf("%d\n",d);//输出结果d
	return 0;//程序正常退出
}

------------------------------------------------------
Problem1069:
#include <stdio.h>
int main()
{
    int M, k, day;
    int t = 0;
    scanf("%d%d", &M, &k);
    for (day = 0; M > 0; day++)
    {
        M -= 1;
        t += 1;
        if (t == k)
        {
            t = 0;
            M += 1;
        }
    }
    printf("%d", day);
    return 0;
}
------------------------------------------------------
Problem1070:
#include <stdio.h>
int main()
{
    int x = 0, y = 0, time = 0;
    int t;
    int turn = 0;
    int Direction = 2;
    while (turn != 3)
    {
        scanf("%d", &t);
        time = t - time;
        switch (Direction)
        {
        case 1:
            x += time * 10;
            break;
        case 2:
            y += time * 10;
            break;
        case 3:
            x -= time * 10;
            break;
        case 4:
            y -= time * 10;
            break;
        }
        time = t;
        scanf("%d", &turn);
        if (turn == 1)
            Direction++;
        else if (turn == 2)
            Direction--;

        if (Direction == 5)
            Direction = 1;
        else if (Direction == 0)
            Direction = 4;
    }
    printf("%d %d", x, y);
    return 0;
}
------------------------------------------------------
Problem1071:
#include <stdio.h>
int main()
{
    int n;
    int i = 2;
    scanf("%d", &n);
    while (n != 1)
    {
        while (n % i == 0)
        {
            printf("%d", i);
            if (n != i)
                printf(" ");
            n /= i;
            i = 2;
        }
        i++;
    }
    return 0;
}

------------------------------------------------------
Problem1072:
#include <stdio.h>
int main()
{
    int day = 0, high, t = 0, up, down;
    scanf("%d%d%d", &high, &up, &down);
    while (high > t)
    {
        t += up;
        if (high > t)
            t -= down;
        day++;
    }
    printf("%d", day);
    return 0;
}
------------------------------------------------------
Problem1073:
#include <stdio.h>
int main()
{
    double sn = 0, k;
    int n;
    scanf("%lf", &k);
    for (n = 1; sn <= k; n++)
    {
        sn += 1.0 / n;
    }
    printf("%d", n-1);
    return 0;

}

------------------------------------------------------
Problem1074:
#include <stdio.h>
int main()
{
    int n, cock, hen, chick, sign = 0;
    scanf("%d", &n);
    for (cock = 0; cock <= n/5; cock++)
    {
        for (hen = 0; hen <= n/3; hen++)
        {
            chick = n - hen - cock;
            if (3*(cock * 5 + hen * 3) + chick * 1 == 3*n)
            {
                printf("%4d%4d%4d\n", cock, hen, chick);
                sign = 1;
            }
        }
    }
    if (sign == 0)
        printf("No Answer");
    return 0;
}
------------------------------------------------------
Problem1075:
# include<stdio.h>
int main()
{
	int n,cost,a,b,c,flag=0;
	scanf("%d %d",&n,&cost);
	for(a=0;a<cost/3;a++)
	{
		for(b=0;b<cost/2;b++)
		{
			for(c=0;c<=n;c++)
			{
				if((a+b+c==n)&&(a*3+b*2+c==cost))
				{
					printf("%d %d %d\n",a,b,c);
					flag=1;
				}
			}
		}
	}
	if(flag==0)
	{
		printf("No answer");
	 } 
	 return 0;
}
------------------------------------------------------
Problem1076:
#include <stdio.h>
int main()
{
    int x, y, z, n, answer = 0;
    scanf("%d", &n);
    for (x = 1; x <= 9; x++)
    {
        for (y = 1; y <= 9; y++)
        {
            for (z = 0; z <= 9; z++)
            {
                if ((x + y) * 100 + (y + z) * 10 + z * 2 == n)
                {
                    answer = 1;
                    printf("%4d%4d%4d", x, y, z);
                }
            }
        }
    }
    if (answer ==0)
        printf("No Answer");
    return 0;
}
------------------------------------------------------
Problem1077:
#include <stdio.h>

int main()
{
    char ch[1000];
    int i, k;
    fgets(ch,sizeof(ch),stdin);
    scanf("%d", &k);
    for (i = 0; ch[i]; i++)
    {
        if (ch[i] >= 'a' && ch[i] <= 'z')
            ch[i] = (ch[i] - 'a' + k) % 26 + 'a';
        else if (ch[i] >= 'A' && ch[i] <= 'Z')
            ch[i] = (ch[i] - 'A' + k) % 26 + 'A';
    }
    puts(ch);
    return 0;
}
------------------------------------------------------
Problem1078:
#include <stdio.h>

int main()
{
    int n, a, b;
    scanf("%d", &n);
    n -= 1;
    int Add[n];
    for (int i = 0; i <= n; i++)
    {
        scanf("%d%d", &a, &b);
        Add[i] = a + b;
        printf("%d\n", Add[i]); 
    }
    return 0;
}
------------------------------------------------------
Problem1079:
#include<stdio.h>
int main() 
{ 
    int a,b; 
    while(scanf("%d%d",&a,&b)!=EOF) 
    { 
        printf("%d\n",a+b); 
    } 
    return 0; 
} 
------------------------------------------------------
Problem1080:
#include"stdio.h" 
int main() 
{ 
    int a,b; 
    while(scanf("%d%d",&a,&b), a!=0||b!=0) 
        printf("%d\n",a+b); 
    return 0; 
} 
------------------------------------------------------
Problem1081:
#include <stdio.h>
int main()
{
    int n, m, part, sum=0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &m);
        for (int u = 1; u <= m; u++)
        {
            scanf("%d", &part);
            sum += part;
        }
        printf("%d\n", sum);
        sum = 0;
    }
    return 0;
}
------------------------------------------------------
Problem1082:

#include<stdio.h>
 
int main()
{
    int ncase,N,i;
    scanf("%d",&ncase);
    while(ncase--)
    {
        scanf("%d",&N);
     
        for(i=1;i<=N;i++)
        {
            if(i%7==0||i%10==7||(i/10)%10==7||(i/100)%10==7||(i/1000)%10==7||(i/10000)%10==7)
            {
                printf("%d ",i);
            }
        }
         
        printf("\n"); 
         
    }
    return 0;
}
------------------------------------------------------
Problem1083:

#include <stdio.h>
int main()
{
    int n;
    double number;
    int z, f, l;
    while (scanf("%d", &n), n)
    {
        z = 0, f = 0, l = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%lf", &number);
            if (number > 0)
            {
                z += 1;
            }
            else if (number == 0)
            {
                l += 1;
            }
            else
            {
                f += 1;
            }
        }
        printf("%d %d %d\n", f, l, z);
    }
    return 0;
}
------------------------------------------------------
Problem1084:
#include <stdio.h>
#include <math.h>
int main()
{
    double x1, x2, y1, y2, a;
    while (scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2) != EOF)
    {
        a = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        printf("%.2f\n", a);
    }
    return 0;
}
------------------------------------------------------
Problem1085:
#include <stdio.h>
#include <math.h>
int main()
{
    int n, num, sum = 1;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &num);
            if (num % 2 != 0)
            {
                sum *= num;
            }
        }
        printf("%d\n", sum);
        sum = 1;
    }
    return 0;
}
------------------------------------------------------
Problem1086:
#include <stdio.h>
int main ()
{
    char a,b,c;
    char temp;
    while(scanf("%c%c%c ",&a,&b,&c)!=EOF)
    {
        if(a<b)
        {
            temp=a;
            a=b;
            b=temp;
        }
        if(c<b)
        {
            temp=c;
            c=b;
            b=temp;
        }
        if(c>a)
        {
            temp=a;
            a=c;
            c=temp;
        }
        printf("%c %c %c\n",b,c,a);
    }
    return 0;
}
------------------------------------------------------
Problem1087:
#include <stdio.h>
int main()
{   
    int n, year, month, r;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%*6d%4d%2d%2d%*d", &year, &month, &r);
        printf("%d-%02d-%02d\n", year, month, r);
    }
 
    return 0;
}
------------------------------------------------------
Problem1088:
#include <stdio.h>
#include <math.h>
int main()
{
    int n,a;
    scanf("%d", &n);
    while (n--)
    {
    scanf("%*6d%5d", &a);
    printf("%d\n", a+600000);
    }
    return 0;
}

------------------------------------------------------
Problem1089:
#include <stdio.h>
#include <math.h>
int main()
{
    double fact = 1.0;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        fact = fact * i * 1.0;
        while (fact >= 100)
        {
            fact /= 10;
        }
    }
    if (fact <= 9)
    {
        printf("%.0lf\n", fact);
    }
    else
    {
        int s = (int)fact;
        printf("%d\n", s / 10);
    }
    return 0;
}
------------------------------------------------------
Problem1090:
#include <stdio.h>
#include <math.h>
#include <limits.h>
int main()
{
    int m;
    scanf("%d", &m);
    while (m--)
    {
        int a, b, n;
        scanf("%d%d", &a, &b);
        n = 1;
        for (int i = 1; i <= b; i++)
        {
            n *= a;
            n %= 1000;
        }
        printf("%d\n", n);
    }
    return 0;
}
------------------------------------------------------
Problem1091:
#include <stdio.h>
#include <math.h>
#include <limits.h>
int main()
{
    int n;
    while (scanf("%d", &n) && n != 0)
    {
        if (n == 1)
            printf("1\n");
            
        else if (n ==2)
            printf("2\n");
        else 
        {
            int sum = 1, a = 1, b = 2, c;
            for (int ii = 3; ii <= n; ii++)
            {
                c = a + b;
                a = b;
                b = c;
            }
            printf("%d\n", c);
        }
    }
    return 0;
}
------------------------------------------------------
Problem1092:
int prime(int n)
{
    int i, k;
    if(n == 1)
        return 0;
    k = (int)sqrt(n);
    for(i = 2; i <= k; i++)
    {
        if(n % i == 0)
            return 0;
    }
    return 1;
}
#include<stdio.h>
#include<math.h>
 
int prime(int n);
 
int main(void)
{
    int j,m,n;
    scanf("%d%d",&m,&n);
     
    for(j=m;j<=n;j++)
    {
        if(prime(j)!=0)
        {
            printf("%d ",j);
        }
    }
    return 0;
}


------------------------------------------------------
Problem1093:
#include <stdio.h>
#include <math.h>
int m;
int prime(int n);
int main()
{
    scanf("%d", &m);
    for (int i = 3; i <= m / 2; i += 2)
    {
        if (prime(i) && prime(m - i))
        {
            printf("%d %d\n", i, m - i);
        }
    }
    return 0;
}
int prime(int n)
{
    int k;
    k = (int)sqrt(n);
    if (n == 1)
        return 0;
    for (int i = 2; i <= k; i++)
    {
        if (n % i == 0)
            return 0;
    }

    return 1;
}
------------------------------------------------------
Problem1094:
#include <stdio.h>
#include <math.h>
int vowel(char ch);
int main()
{
    int num = 0;
    char ch;
    while (scanf("%c", &ch), ch != '\n')
    {
        num += vowel(ch);
    }
    printf("%d", num);
    return 0;
}
int vowel(char ch)
{
    switch (ch)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
        return 1;
        break;
    default:
        return 0;
    }
}

------------------------------------------------------
Problem1095:
#include <stdio.h>
#include <math.h>

int HmsToS(int h, int m, int s);
void PrintTime(int t);
int main()
{
    int h, m, s, a, b;
    while (scanf("%d:%d:%d", &h, &m, &s) != EOF)
    {
        a = HmsToS(h, m, s);
        scanf("%d:%d:%d", &h, &m, &s);
        b = HmsToS(h, m, s);
        PrintTime(b - a);
    }
    return 0;
}

int HmsToS(int h, int m, int s)
{
    return h * 3600 + m * 60 + s;
}
void PrintTime(int t)
{
    int h, m, s;
    h = t / 3600;
    t %= 3600;
    m = t / 60;
    t %= 60;
    printf("%02d:%02d:%02d\n", h, m, t);
}
------------------------------------------------------
Problem1096:
#include <stdio.h>
#include <math.h>
void sxhs(int m, int n);
int main()
{
    int m;
    int n;
    while (scanf("%d%d", &m, &n) != EOF)
    {
        sxhs(m, n);
        printf("\n");
    }
    return 0;
}

void sxhs(int m, int n)
{
    int a, b, c, flag = 0;
    for (int i = m; i <= n; i++)
    {
        if (pow(i / 100, 3) + pow(i % 100 / 10, 3) + pow(i % 10, 3) == i)
        {
            if (flag != 0)
                printf(" ");
            printf("%d", i);
            flag += 1;
        }
    }
    if (flag == 0)
        printf("no");
}

------------------------------------------------------
Problem1097:
#include <stdio.h>
#include <math.h>

double power(char ch);

int main()
{
    char ch;
    double average = 0;
    int time = 0;
    while ((ch = getchar()) != '\n') //不能使用EOF,会将\n带入输入缓冲区
    {
        time++;
        average += power(ch);
    }
    average *= 1.00 / time;
    printf("%.1lf\n", average);
    return 0;
}

double power(char ch)
{
    switch (ch)
    {
    case 'A':
        return 95;
    case 'B':
        return 85;
    case 'C':
        return 75;
    case 'D':
        return 65;
    case 'E':
        return 40;
    default:
        return 0;
    }
}
------------------------------------------------------
Problem1098:
#include <stdio.h>
#include <math.h>

double funF(double x);
double funG(double x);

int main()
{
    double x, y;
    scanf("%lf", &x);
    y = funF(funG(x));
    printf("%.2lf\n", y);
    return 0;
}

double funF(double x)
{
    return fabs(x - 3) + fabs(x + 1);
}
double funG(double x)
{
    return x * x - 3 * x;
}

------------------------------------------------------
Problem1099:
#include <stdio.h>
#include <math.h>

int main()
{
    int n, step;
    while ((scanf("%d", &n)) != EOF)
    {
        step = 0;
        while (n != 1)
        {
            if (n % 2 == 0)
            {
                n /= 2;
                step++;
            }
            else
            {
                n = 3 * n + 1;
                step++;
            }
        }
        printf("%d\n", step);
    }

    return 0;
}
------------------------------------------------------
Problem1100:
#include <stdio.h>

long fact(long n);

int main()
{
    int m, k;
    scanf("%d%d", &m, &k);
    printf("%ld", fact(m) / (fact(k) * fact(m - k)));
    return 0;
}

long fact(long n)
{
    long sum = 1;
    while (n)
    {
        sum *= n;
        n--;
    }
    return sum;
}
------------------------------------------------------
Problem1101:

int inverse(int n)
{
    int isum = 0;
    while (n != 0)
    {
        isum = isum * 10 + n % 10;
        n /= 10;
    }
    return isum;
}
#include<stdio.h>
int inverse(int n) ;
 
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",n+inverse(n));
	return 0;
}

------------------------------------------------------
Problem1102:
#include <stdio.h>

double CancelFee(double price);

int main()
{
    double price;
    scanf("%lf", &price);
    printf("%.1lf", CancelFee(price));
    return 0;
}

double CancelFee(double price)
{
    price *= 0.05;
    int fee = (int)price;
    if (price - fee < 0.25)
        return fee * 1.0;
    else if (0.25 <= price - fee && price - fee < 0.75)
        return fee + 0.5;
    else
        return fee + 1.0;
}
------------------------------------------------------
Problem1103:
#include <stdio.h>

int xuefen(int cj);

int main()
{
    int n;
    scanf("%d", &n);
    double sumxf = 0, average = 0;
    for (int i = 1; i <= n; i++)
    {
        int jidian, chengji;
        scanf("%d%d", &jidian, &chengji);
        average += jidian * xuefen(chengji);
        sumxf += jidian;
    }
    average = average * 1.0 / sumxf;
    printf("%.1lf\n", average);
    return 0;
}

int xuefen(int cj)
{
    if (cj < 60)
        return 0;
    else
        return (cj - 50) / 10;
}
------------------------------------------------------
Problem1104:
#include <stdio.h>

int FacSum(int n);

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", FacSum(n));
    return 0;
}

int FacSum(int n)
{
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
            sum += i;
    }
    return sum;
}
------------------------------------------------------
Problem1105:
#include <stdio.h>

int FacSum(int n);

int main()
{
    int m, n, flag = 0;
    scanf("%d%d", &m, &n);
    for (int i = m; i <= n; i++)
    {
        int a = FacSum(i);
        if (i == FacSum(a) && i < a)
        {
            printf("%d %d\n", i, a);
            flag = 1;
        }
    }
    if (flag == 0)
        printf("No answer");
    return 0;
}

int FacSum(int n)
{
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
            sum += i;
    }
    return sum;
}
------------------------------------------------------
Problem1106:
#include <stdio.h>

int inverse(int n);

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    int start = 0;
    for (int i = m; i <= n; i++)
    {
        if (i == inverse(i))
        {
            if (start == 1)
                printf(" ");
            start = 1;
            printf("%d", i);
        }
    }
    return 0;
}

int inverse(int n)
{
    int isum = 0;
    while (n != 0)
    {
        isum = isum * 10 + n % 10;
        n /= 10;
    }
    return isum;
}
------------------------------------------------------
Problem1107:
#include <stdio.h>

int inverse(int n);

int main()
{
    int n, start = 0;
    scanf("%d", &n);
    while (n != inverse(n))
    {
        if (start == 1)
            printf(" ");
        start = 1;
        printf("%d", n);
        n = n + inverse(n);
    }
    if (start == 1)
        printf(" ");
    printf("%d", n);
    return 0;
}

int inverse(int n)
{
    int isum = 0;
    while (n != 0)
    {
        isum = isum * 10 + n % 10;
        n /= 10;
    }
    return isum;
}
------------------------------------------------------
Problem1108:
#include <stdio.h>
void PrintLine(int n)
{
    int i, j;
    for (i = 1; i < 2 * n; i++)
    {
        if (i <= n)
        {
            for (j = 1; j <= n - i; j++)
                printf(" "); //先处理空格的问题，这是输出空格的操作
            for (j = 1; j <= i; j++)
                printf("%d", j); //这些是第 i 行第 i 个数前面的数，正常输出就行咧
            for (j = i - 1; j > 0; j--)
                printf("%d", j); //这些就是第 i +1个数的输出情况，倒着输出这些数就行咧
        }
        else
        {
            for (j = 1; j <= i - n; j++)
                printf(" "); //处理空格的操作
            for (j = 1; j <= 2 * n - i; j++)
                printf("%d", j); //这些是第n+1行以后的数的操作
            for (j = (2 * n - i - 1); j > 0; j--)
                printf("%d", j);
        }
        printf("\n"); //每输完一行，都要进行换行
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    PrintLine(n);
    return 0;
}
------------------------------------------------------
Problem1108:
#include <stdio.h>

void PrintLine(int n);

int main()
{
    int m;
    scanf("%d", &m);
    PrintLine(m);
    return 0;
}

void PrintLine(int n)
{
    int o = n - 1;
    static int site[17][17];
    for (int y = 0; y <= o; y++)
    {
        for (int x = 0; x <= o; x++)
        {
            site[o + x][o + y] = n - x - y;
            site[o - x][o - y] = n - x - y;
            site[o - x][o + y] = n - x - y;
            site[o + x][o - y] = n - x - y;
        }
    }
    for (int y = 2 * n - 2; y >= 0; y--)
    {
        for (int x = 0; x <= 2 * n - 2; x++)
        {

            if (site[x][y] <= 0)
                printf(" ");
            else
                printf("%d", site[x][y]);
        }
        printf("\n");
    }
}

------------------------------------------------------
Problem1109:
#include <stdio.h>
int digitSum(int n);
int main()
{
    int n,t;
    scanf("%d",&n);
    t=digitSum(n);
    while(t>=10)  //判断是否满足和小于10
    {
        digitSum(t);
        t=digitSum(t);  //不满足则继续求和
    }
    printf("%d",t);
    return 0;
}
int digitSum(int n) //求每一位数的的和
{
    int sum=0;
    while(n!=0)
    {
        sum+=n%10;
        n=n/10;
    }
    return sum;
}

------------------------------------------------------
Problem1109:
#include <stdio.h>

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
------------------------------------------------------
Problem1110:
#include <stdio.h>

int common(int x, int y);

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    printf("%d\n", common(m, n));
    return 0;
}

int common(int x, int y)
{
    if (x == y)
        return x;
    if (x > y)
        return common(x / 2, y);
    else
        return common(x, y / 2);
}
------------------------------------------------------
Problem1111:
#include <stdio.h>
void inverse(int n);
int main()
{
    int n;
    scanf("%d", &n);
    inverse(n);
    return 0;
}

void inverse(int n)
{
    int num;
    if (n > 1)
    {
        scanf("%d", &num);
        inverse(n - 1);
        printf("%d ", num);
    }
    if (n == 1)
    {
        scanf("%d", &num);
        printf("%d ", num);
    }
}

------------------------------------------------------
Problem1112:
#include <stdio.h>

void convert(int n);

int main()
{
    int n;
    scanf("%d", &n);
    convert(n);
    return 0;
}

void convert(int n)
{
    if (n > 0)
    {
        convert(n / 2);
        printf("%d", n % 2);
    }
}

------------------------------------------------------
Problem1113:
#include <stdio.h>

int fib(int k);
int time = 0;
int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%d\n", fib(n));
    printf("递归调用了%d次", time);
    return 0;
}

int fib(int k)
{
    time++;
    if (k == 1 || k == 2)
    {
        return 1;
    }
    else
    {
        return fib(k - 1) + fib(k - 2);
    }
}
------------------------------------------------------
Problem1114:
#include <stdio.h>
#define N 10
int main()
{
    int i, n;
    int a[N];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = n - 1; i >= 0; i--)
        printf("%4d", a[i]);
    printf("\n");
    return 0;
}

------------------------------------------------------
