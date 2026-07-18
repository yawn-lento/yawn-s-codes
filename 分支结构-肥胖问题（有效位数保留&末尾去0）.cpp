#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
double set_precision(double n, int precision)
{
    if (precision < 0)
        return n;
    else
        return round(n * pow(10, precision)) / pow(10, precision);
}
int main()
{
    float m, h;
    int i = 1;
	int precision = 6;
    cin >> m >> h;
    float BMI;
    BMI = m / (h * h);
    double num = set_precision(BMI, precision-2);
    if (BMI < 18.5)
        cout << "Underweight" ;
    if (BMI >= 18.5 && BMI < 24)
        cout << "Normal" ;
    if (BMI >= 24)
    {
        while (10 * round(pow(10, 5 - i) * num / 10) == pow(10, 5 - i) * num)
        {
            num = int(num * pow(10, 4 - i)) / pow(10, 4 - i);
            i++;
        }
        cout << num<<endl<<"Overweight" ;
    }
    return 0;
}