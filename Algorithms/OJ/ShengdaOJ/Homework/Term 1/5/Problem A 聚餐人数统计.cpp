#include <iostream>
using namespace std;

int main()
{
    int cost, x, y, z, n, flag = 1;
    cin >> n >> cost;
    for (x = 0; x <= cost / 3; x++)
        for (y = 0; y <= cost / 2; y++)
        {
            z = n - x - y;
            if (z >= 0)
                if (3 * x + 2 * y + z == cost)
                {
                    flag = 0;
                    cout << x << " " << y << " " << z << endl;
                }
        }
    if (flag)
        cout << "No answer" << endl;
    return 0;
}