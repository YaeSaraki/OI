#include <iostream>
using namespace std;

void hanoi(int n, char A, char B, char C)
{
    if (n == 1)
    {
        cout << A << "->" << C << endl;
        return;//递归终止
    }
    hanoi(n - 1, A, C, B);//将n-1个盘子从A移到B
    cout << A << "->" << C << endl;
    hanoi(n - 1, B, A, C);//将n-1个盘子从B移到C
    return;

}

int main()
{
    char A = 'A', B = 'B', C = 'C';
    int n;
    cout << "请输入圆盘数量：";
    cin >> n;
    hanoi(n, A, B, C);
    system("pause");
    return 0;
}