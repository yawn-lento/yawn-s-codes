#include <iostream>
#include<algorithm>
using namespace std;
bool cmp(long long a, long long b)
{
	return a < b;
}
int main()
{
	long long a[3] = {};
	for (int i = 0; i < 3; i++)
		cin >> a[i];
	sort(a, a + 3, cmp);
	long long m = a[2], n = a[0];
	while (m % n != 0)
	{
		long long temp = m;
		m = n;
		n = temp % n;
	}
	cout << a[0] / n << "/" << a[2] / n << "\n";
	return 0;
}

