# Problem A: 聚餐人数统计
[Creator : Imported]
Time Limit : 1.000 sec  Memory Limit : 128 MiB

SubmitProblemListSolved: 202Submit Num: 471StatisticsShowOff!
## Description

马克思手稿中有这样一道趣味数学题：男人、女人和小孩总计n个人，在一家饭店里吃饭，共花了cost先令，每个男人各花3先令，每个女人各花2先令，每个小孩各花1先令，请用穷举法编程计算男人、女人和小孩各有几个。

## Input

输入两个正整数，表示人数n和花费cost。

## Output

若问题有解，则输出所有解，每行输出三个数据，代表男人、女人和小孩的人数，用空格分隔；若问题无解，则输出“No answer"。

## Sample Input

30 50
## Sample Output

0 20 10
1 18 11
2 16 12
3 14 13
4 12 14
5 10 15
6 8 16
7 6 17
8 4 18
9 2 19
10 0 20

# Problem B: 时间间隔（多实例测试）
[Creator : Imported]
Time Limit : 1.000 sec  Memory Limit : 128 MiB

SubmitProblemListSolved: 88Submit Num: 187StatisticsShowOff!
## Description

从键盘输入两个时间点(24小时制），输出两个时间点之间的时间间隔，时间间隔用“小时:分钟:秒”表示。要求程序定义如下两个函数，并在main()中调用这两个函数实现相应的功能

/*三个形参分别为为用于表示一个时间点的时、分、秒，函数返回对应的秒。*/

int HmsToS(int h, int m, int s);  



/* 形参s表示一个时间段的长度，单位是秒，该函数将该时间段转换为对应的“小时:分钟:秒” 格式输出 */

void PrintTime(int s);

## Input

输入数据有多组。每组输入包括两行。第一行为时间点1，第二行为时间点2，时间点均以“HH:MM:SS”的格式输入。测试数据保证时间点1早于时间点2。

## Output

对应每组数据，有一行输出，以“HH:MM:SS”的格式输出时间间隔。注意不足两位要补占位符0。格式参看输入输出。

## Sample Input 

12:01:12
13:09:43
12:40:12
13:09:43
## Sample Output 

01:08:31
00:29:31
HINT


注意：要输出01:08:31中的占位符0，printf中的格式控制符用"%02d"

# Problem C: 水仙花数（函数专题）
[Creator : Imported]
Time Limit : 1.000 sec  Memory Limit : 128 MiB

SubmitProblemListSolved: 89Submit Num: 321StatisticsShowOff!
## Description

春天是鲜花的季节，水仙花就是其中最迷人的代表，数学上有个水仙花数，他是这样定义的： 
“水仙花数”是指一个三位数，它的各位数字的立方和等于其本身，比如：153=13+53+33。 
现在要求输出所有在m和n范围内的水仙花数。 


## Input

输入数据有多组，每组占一行，包括两个整数m和n（100<=m<=n<=999）。

## Output

对于每个测试实例，要求输出所有在给定范围内的水仙花数，就是说，输出的水仙花数必须大于等于m,并且小于等于n，如果有多个，则要求从小到大排列在一行内输出，之间用一个空格隔开; 
如果给定的范围内不存在水仙花数，则输出no; 
每个测试实例的输出占一行。 



不需要写main函数，写好需要包含的头文件，然后定义题意中要求的函数即可。

## Sample Input 

100 120
300 380
## Sample Output 

no
370 371
HINT

在不知道m到n之间有多少个水仙花数的情况下，如何控制两个数之间有空格，而最后一个水仙花数之后没有空格？解决方法之一是：第一个水仙花数之前不加空格，而其后每个水仙花数之前加空格。而通过一个标识变量可以判断出是否是第一个水仙花数。

初做多实例测试，要注意变量赋初值的位置。



不需要写main函数，写好需要包含的头文件，然后定义题意中要求的函数即可。


~~~
int main()
{
    int i,m,n,c;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        c=0;
     for(i=m;i<=n;i++)
     {
            if(Flower(i)==1)
            {
             printf("%d ",i);
             c++;
            }
     }
     if(c==0)
     printf("no");
     printf("\n");
    }

    return 0;
}
~~~

# Problem D: 计算平均成绩（函数专题）
[Creator : Imported]
Time Limit : 1.000 sec  Memory Limit : 128 MiB

SubmitProblemListSolved: 68Submit Num: 148StatisticsShowOff!
## Description

输入某位同学各门课的成绩，输出平均成绩。输入的成绩均为五级制成绩，五级制成绩转换为百分之成绩的规则如下：'A'转换为百分之成绩为95分，'B'对应85分，C对应75分，'D'对应65分，'E'对应40分。 输出的平均成绩为一个实数，保留1为小数。

## Input

输入为一行只包含'A'~'E'的字母，每个字母表示一门课的成绩，

## Output

输出平均成绩，为一个实数，保留一位小数。

## Sample Input

ABCDE
## Sample Output

72.0
HINT
~~~
不需要写main函数，写好需要包含的头文件，然后定义题意中要求的函数即可。

int main()
{
    char m;
    double c,sum,i;
    sum=0;c=0.0;i=0;
    while(scanf("%c",&m),m!='\n')
    {
        i++;
        sum+=average(m);
         
    }
        c=sum/i;
        printf("%.1lf\n",c);
} 
~~~
# Problem E: 逆序数字（函数专题）
[Creator : Imported]
Time Limit : 1.000 sec  Memory Limit : 128 MiB

SubmitProblemListSolved: 60Submit Num: 133StatisticsShowOff!
## Description

输入一个正整数n，计算n的逆序数m，输出m与n的和。要求程序定义一个inverse()函数和一个main()函数，inverse()函数接收一个整数值,返回这个数中数字逆序后的结果值。例如,给定数7631,函数返回1367 。 
int inverse(int n) 
{ 
//计算并返回n的逆序数字 
} 

## Input

一个正整数n，输入保证计算结果在int范围内。 
## Output

输出一个整数，n与n的逆序数的和。输出占一行。 
## Sample Input

1780
## Sample Output
~~~
2651
HINT

不需要写main函数，写好需要包含的头文件，然后定义题意中要求的函数即可。
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",n+inverse(n));
} 
~~~
# Problem F: 第二日问题
[Creator : Imported]
Time Limit : 1.000 sec  Memory Limit : 128 MiB

SubmitProblemListSolved: 17Submit Num: 92StatisticsShowOff!
## Description

众所周知，一个成熟的软件，需要无数次的测试才会有满足大众的结果。例如：qq经过这么多年的发展，已经很成熟了，什么功能都比较完备了，用着就是很舒服。微信虽然很火，但是，毕竟是后起之秀，有很多地方需要完善，所以用起来总是那么别扭。只有经过大浪淘沙的过程，才能使得产品趋于成熟。就像看书一样，人生很短，看就看被历史长河刷下来的书，流行的书一定不要看，就是在浪费人生，要看经得起历史过滤的。同样，一个成熟的软件，必须要经过多次的测试，大三的时候会有一个软件测试，其中最经典的问题就是第二日问题。这题太简单了，给定一个日期求下一个日期，这对大家来说so easy，赶紧拿 一血吧。 
## Input

输入为多组数据，每组输入只有一行，year，month，day，数据符合实际要求；最后一组输入为0，认为是输入结束的标志，不需要处理。 
## Output

输出占一行，请输出该日期的下一天。 
## Sample Input

2012 2 3
2011111111 1 2
2035 2 28 
0
## Sample Output

2012 2 4
2011111111 1 3
2035 3 1

# Problem G: 和尚特烦恼2
[Creator : Imported]
Time Limit : 1.000 sec  Memory Limit : 128 MiB

SubmitProblemListSolved: 32Submit Num: 44StatisticsShowOff!
## Description

和尚解决了上一次的难题之后。又碰到了新的难题。这次也是关于素数的。一位施主首先把素数编号。最小的素数2编号为1，然后依次增加。施主要要求和尚迅速回答出对应编号的素数。
## Input

输入数据有多组，输入数据有多组，每组数据首先输入一个整数n(n<100). 然后有n个正整数m(m<10000).
## Output

对于每个正整数编号，输出对应的素数
每个输出占一行
## Sample Input

3
1
2
3
## Sample Output

2
3
5

# Problem H: 和尚的烦恼3
[Creator : Imported]
Time Limit : 1.000 sec  Memory Limit : 128 MiB

SubmitProblemListSolved: 26Submit Num: 37StatisticsShowOff!
## Description

话说两个小和尚从出生就在少林寺生活（我也很奇怪一出生就在少林寺，和尚，尼姑？？？？？？？？？），他们每天的生活很单调啊，除了读书就是写字，偶尔跟鲁智深种菜，种菜也是很无聊的，加上鲁智深那种粗人动不动月牙铲就冲过了，很吓人的，还不如读书了，说不定哪天在藏经阁发现什么武功秘籍，成为大师级别的武林高手，就可以出山了，少林的规矩很简单，要么武功很高，闯过什么十八铜人就可以下山了，要么就是在少林熬个几十年，具体是经过15个闰年就可以了，这样的时间可是很长的啊。两个小和尚就去问师傅了，师傅说，他还没有下过山了，他也不知道，让小和尚们问问轻工业学院的新生们，萌萌哒的小伙伴们赶紧告诉他们最早可以在什么时候下山吧；
## Input

首先输入一个整数n(n<1000)，接下来有n组数据，每组包含一个正整数year，表示小和尚出生的那一年（year>1）；
## Output

每组数据只输出一个整数，表示小和尚下山的年份；
## Sample Input

5
32
572
797
758
76
## Sample Output

88
632
856
816
136

# Problem I: 镂空三角形
[Creator : Imported]
Time Limit : 1.000 sec  Memory Limit : 32 MiB

SubmitProblemListSolved: 15Submit Num: 40StatisticsShowOff!
## Description

把一个字符三角形掏空，就能节省材料成本，减轻重量，但关键是为了追求另一种视觉效果。在设计的过程中，需要给出各种花纹的材料和大小尺寸的三角形样板，通过电脑临时做出来，以便看看效果。
## Input

每行包含一个字符和一个整数n(0<n<41)，不同的字符表示不同的花纹，整数n表示等腰三角形的高。显然其底边长为2n-1。如果遇到@字符，则表示所做出来的样板三角形已经够了。
## Output

每个样板三角形之间应空上一行，三角形的中间为空。显然行末没有多余的空格。
## Sample Input

X 2
A 7
@
## Sample Output
~~~
 X
XXX

      A
     A A
    A   A
   A     A
  A       A
 A         A
AAAAAAAAAAAAA
~~~

# Problem J: 最强魔法师
[Creator : Imported]
Time Limit : 1.000 sec  Memory Limit : 128 MiB

Submit# ProblemListSolved: 6Submit Num: 30StatisticsShowOff!
## Description

哈利.波特战胜伏地魔以后，夺取了魔法世界永不会输的魔杖，准备开始新的征途。就在这时，身披金甲圣衣，脚踩七色云彩的你降生了，哈利知道你就是新一代的王牌魔法师，于是失去了继续努力的信心，折断了接骨木魔杖 ，准备放弃魔法师生涯。从第二天开始过上了三天打鱼两天晒网的生活。现在是2019年的某天，请问哈利.波特是在打鱼还是在晒网？

## Input

输入为两行，第一行是一个日期，代表你的生日，第二行也是一个日期，代表今年的某天。输入保证第二个日期大于第一个日期。

## Output

输出为一行，当哈利在打鱼时，请输出“He is fishing.”，否则，请输出”He is drying the net.”

## Sample Input

2000-01-01
2019-11-18
## Sample Output

He is fishing.
