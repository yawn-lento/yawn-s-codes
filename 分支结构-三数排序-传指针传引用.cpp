#include<iostream>
using namespace std;
void sort1(int& a, int& b, int& c)
{
    int temp;
    if (a > b)
    {
        temp = a;
        a = b;
        b = temp;
    }
    if (a > c)
    {
        temp = a;
        a = c;
        c = temp;
    }
    if (b > c)
    {
        temp = b;
        b = c;
        c = temp;
    }
}//以上是传引用，最推荐的c++式做法
void sort2(int* a, int* b, int* c)
{
    int temp;
    if (*a > *b)
    {
        temp = *a;
        *a = *b;
        *b = temp;
    }
    if (*a > *c)
    {
        temp = *a;
        *a = *c;
        *c = temp;
    }
    if (*b > *c)
    {
        temp = *b;
        *b = *c;
        *c = temp;
    }
}//以上是传指针，繁琐一些
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    bool flag;
    cout << "输入1采取传引用，输入0采取传指针" << endl;
    cin >> flag;
    if (flag == 1)
        sort1(a, b, c);
    else
        sort2(&a, &b, &c);
    cout << a << " " << b << " " << c;
    return 0;
}