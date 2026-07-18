#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int A,int B)
{
	return A < B;
}
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int l[3] = { a,b,c };
	sort(l, l + 3, cmp);
	if (l[0] + l[1] <= l[2])
		cout << "Not triangle"<<endl;
	else
	{
		if (l[0] * l[0] + l[1] * l[1] > l[2] * l[2])
			cout << "Acute triangle" << endl;
		else if (l[0] * l[0] + l[1] * l[1] == l[2] * l[2])
			cout << "Right triangle" << endl;
		else
			cout << "Obtuse triangle" << endl;
		if ( l[0] == l[1] || l[1] == l[2] || l[0] == l[2])
			cout << "Isosceles triangle" << endl;
		if (l[0]==l[2])
			cout << "Equilateral triangle" << endl;
	}
	return 0;
}