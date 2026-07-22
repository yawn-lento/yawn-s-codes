#include<iostream>
using namespace std;
long long path_count=0;
int n, m, x, y;
bool if_block(int i,int j)
{
	return((i == x && j == y) || i > n || j > m || i < 0 ||j<0 || ((i - x) * (i - x) + (j - y) * (j - y) == 5));
}
void DFS(int i, int j)
{
	if(if_block(i, j))
	return;
	if (i == n && j == m)
	{
		path_count++;
		return;
	}
	DFS(i + 1, j);
	DFS(i, j + 1);
}
int main()
{
	cin >> n >> m >> x >> y;
	DFS(0, 0);
	cout << path_count << endl;
	return 0;
}