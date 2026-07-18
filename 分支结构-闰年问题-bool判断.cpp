#include<iostream>
using namespace std;
bool judge(int year)
{
    if (year % 4 == 0&&year%100!=0)
        return true;
    if (year % 400 == 0)
        return true;
    else
        return false;
}
int main()
{
    int y, m;
        cin >> y >> m;
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
        cout << 31;
    if (m == 4 || m == 6 || m == 9 || m == 11)
        cout << 30;
    if (m == 2)
        if (judge(y))
            cout << 29;
        else
            cout << 28;
    return 0;
}