#include <iostream>
using namespace std;
int main()
{
    int x, n;
    cin >> x >> n;
    int num = n / 7;
    int rest = n%7;
    int i = 0;
    int j = 0;
    while(i<rest)
    {
        if ((x + i)%7 != 6 && (x + i)%7 != 0)
            j++;
        i++;
    }
    cout << 250*(5 * num + j);
    return 0;
}
