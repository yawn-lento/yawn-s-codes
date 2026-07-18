#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int s1=0, s2=0;
    int c1=0, c2=0;
    for (int i = 1; i < n + 1; i++)
    {
        if (i % k == 0)
        {
            s1 += i;
            c1++;
        }
        else
        {
            s2 += i;
            c2++;
        }
    }
    double t1, t2;
    t1 = (double) s1 / c1; t2 = s2 / (double)c2;//强制触发小数除法
    cout << fixed << setprecision(1) << t1<<" "<<t2;
    return 0;
}

