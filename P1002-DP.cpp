#include<iostream>
#pragma warning(disable: 6385)
using namespace std;
long long dp[22][22];
int main()
{
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	if (m > 20 || n > 20 || x > 20 || y > 20||m < 0 || n <0 || x<0 || y<0)
		return 0;
	dp[0][0] = 1;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (i == 0 && j == 0) 
				continue;
			if ((i - x) * (i - x) + (j - y) * (j - y) == 5||(i==x&&j==y))
			{
				dp[i][j] = 0;
				continue;
			}
			if (i != 0 && j != 0)
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			else if(i==0)
				dp[i][j] = dp[i][j - 1];
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	cout << dp[n][m] << endl;
	return 0;
}
