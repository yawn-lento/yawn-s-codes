#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct carpet
{
	int a, b;
	int c, d;
};
bool judge(carpet m, int x, int y)
{
	return(m.a <= x && m.b <= y && (x <= m.a + m.c) && (y <= m.b + m.d));
}
int main()
{
	int n;
	int x, y;
	cin >> n;
	vector<carpet>carpets(n);
	for (int i = 0; i < n; i++)
		cin >> carpets[i].a >> carpets[i].b >> carpets[i].c >> carpets[i].d;
	cin >> x >> y;
	stack<bool> if_in;
	for (int i = 0; i < n; i++)
		if_in.push ( judge(carpets[i], x, y));
	for (int i=n;i>-1;i--)
	{		
		if ( if_in.empty())
		{
			cout << -1 << endl;
			return 0;
		}
		else if (!if_in.empty() && if_in.top())
		{
			cout << i << endl;
			return 0;
		}
		else
				if_in.pop();			
	}
	return 0;
}
