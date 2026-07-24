#include <iostream>
#include<vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cstring>
using namespace std;
int num[9][9] = { 0 };
int temp[9][9] = { 0 };
bool cmp(int a, int b) {
	return a > b;
}
int rand01()
{
	return rand() % 2;
}
void fill(int x, int y, int v)
{
	num[x - 1][y - 1] = v;
	temp[x - 1][y - 1] = v;
}
int main()
{
	int N;
	cin >> N;
	srand(time(0));
	int x, y, v;
	while (cin >> x && cin >> y && cin >> v)
	{
		if (x == 0 && y == 0 && v == 0) break;
		fill(x, y, v);
	}
	int attempt1 = 0, attempt2 = 0;
	int sum_1[100] = { 0 };
	int sum_2[100] = { 0 };
	int tempx, tempy, fork;
	while (attempt1 < 100)
	{
		tempx = tempy = 0;
		while (tempx < N-1 || tempy < N-1)
		{
			fork = rand01();
			if (tempx < N - 1 && tempy < N - 1)
			{
				tempx = tempx + fork, tempy = tempy + 1 - fork;
			}
			else if (tempx == N - 1 && tempy < N - 1)
				tempy++;
			else
				tempx++;
			sum_1[attempt1] += num[tempx][tempy];
			num[tempx][tempy] = 0;
		}
		while (attempt2 < 100)
		{
			tempx = tempy = 0;
			while (tempx < N - 1 || tempy < N - 1)
			{
				fork = rand01();
				if (tempx < N - 1 && tempy < N - 1)
				{
					tempx = tempx + fork, tempy = tempy + 1 - fork;
				}
				else if (tempx == N - 1 && tempy < N - 1)
					tempy++;
				else
					tempx++;
				sum_2[attempt2] += num[tempx][tempy];
			}
			attempt2++;
		}
		sort(sum_2, sum_2 + attempt2, cmp);
		sum_1[attempt1] += sum_2[0];
		attempt1++;
		attempt2 = 0;
		memcpy(num, temp, sizeof(num));
		memset(sum_2, 0, sizeof(sum_2)); 
	}
	sort(sum_1, sum_1 + attempt1, cmp);
	cout << sum_1[0] +num[0][0]<< endl;
	return 0;
}
