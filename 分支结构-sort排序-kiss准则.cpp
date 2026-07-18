// ConsoleApplication51.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*#include <iostream>
using namespace std;
double compare(int num, int price)
{
    double single_price=price/num;
    return single_price;
}
void sort(double& a, double& b, double& c, int& i,int & j,int& k)
{
    double temp;
    if (a > b)
    {
        temp = a;
        a = b;
        b = temp;
        i++;
    }
    if (a > c)
    {
        temp = a;
        a = c;
        c = temp;
        j++;
    }
    if (b > c)
    {
        temp = b;
        b = c;
        c = temp;
        k++;
    }
}
int main()
{
    int total_num, num1, p1, num2, p2, num3, p3;
    int m1, m2, m3, r1, r2, r3, s1, s2, s3;
    int i, j, k = 0;
    int n1, n2, n3;
    int h1, h2, h3;
    cin >> total_num >> num1 >> p1 >> num2 >> p2 >> num3 >> p3;
    double sp1 = compare(num1, p1); double sp2 = compare(num2, p2); double sp3 = compare(num3, p3);
    sort(sp1, sp2, sp3, i, j, k);
    if (i == j == 0)
    {
        n1 = num1; h1 = p1;
        if (k == 0)
        {
            n2 = num2, n3 = num3;
            h2 = p2, h3 = p3;
        }
        else
            n2 = num3, n3 = num2;
    }
    if (i == 1 && j == 0)
    {
        n1 = num2; h1 = p2;
        if (k == 0)
        {
            n2 = num1, n3 = num3; h2 = p1, h3 = p3;
        }
        else
            n2 = num3, n3 = num1; h2 = p3, h3 = p1;
    }
    if (i == 0 && j == 1)
    {
        n1 = num3; h1 = p3;
        if (k == 0)
        {
            n2 = num2, n3 = num1; h2 = p2, h3 = p1;
        }
        else
            n2 = num1, n3 = num2; h2 = p1, h3 = p2;
    }
    if (i == j == 1)
    {
        n1 = num3; h1 = p3;
        if (k == 0)
        {
            n2 = num1, n3 = num2; h2 = p1, h3 = p2;
        }
        else
            n2 = num2, n3 = num1; h2 = p2, h3 = p1;
    }
    if (n1 <= total_num)
    {
        {
            m1 = total_num / n1;
            r1 = total_num % n1;
            s1 = sp1 * m1;
        }
        if (n2 <= r1)
        {
            {
                m2 = r1 / n2;
                r2 = r1 % n2;
                s2 = sp2 * m2;
            }
            if (n3 <= r2)
            {
                {
                    cout << s1 + s2 + min(min(h1,h2),h3*(1+r2/n3));
                }
            }
            else
                cout << s1 + s2 + min(min(p1,p2),p3);
        }
        else
        {
            if (n3 >= r1)
                cout << s1 + min(min(p1, p2), p3);
            else
                cout << s1 + min(min(h1,h2), h3 * (1 + r1 / n3));
        }
    }
    else
    {
        if (n2 >= total_num && n3 >= total_num)
        {
            cout << min(min(p1, p2), p3);
        }
        if (n2 >= total_num && n3 < total_num)
            cout << min(min(p1, p2), (1 + total_num / n3));
    }
}*/
//以上是想用贪心去分解，但不如暴力枚举来的快，还容易错。在处理“求满足最小需求的组合最小值”时，暴力枚举往往比复杂的贪心推论要安全可靠。
#include <iostream>
#include <algorithm>
using namespace std;
struct Package {
    int num;  
    int price; 
    double sp; 
};
bool cmp(Package a, Package b) {
    return a.sp < b.sp;
}
int main() {
    int total_num;
    Package p[3];
    cin >> total_num;
    for (int i = 0; i < 3; i++) {
        cin >> p[i].num >> p[i].price;
        p[i].sp = (double)p[i].price / p[i].num;
    }
    sort(p, p + 3, cmp);//从p0到p2的数组按照cmp的逻辑排序，spn<spn+1，cmp为真，不交换，反之交换次序，使得数组按照cmp要求排好
    int cost_min = INT_MAX;
    int cost_tmp = INT_MAX;
    for (int i = 0; i < 10001; i++)
    {
        for (int j = 0; j < 10001; j++)
        {
            int k = (total_num - p[0].num * i - p[1].num * j) / p[2].num;
            if (p[0].num * i + p[1].num * j + p[2].num * k != total_num)
                k++;
            if (p[0].num * i + p[1].num * j - total_num <= 0)
                cost_tmp = p[0].price * i + p[1].price * j + k * p[2].price;
            else
                cost_tmp = p[0].price * i + p[1].price * j;
            if (cost_tmp < cost_min)
                cost_min = cost_tmp;
        }
    }
    cout << cost_min;
}
//"KISS 原则 (Keep It Simple, Stupid)。在计算机中，避免过早优化。先用暴力算法证明逻辑没问题，再在跑不动的时候用数学加速。"