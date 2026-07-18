#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int rand01() 
{
	return rand() % 2;
}
struct point
{
	int x, y;
};
int distance(point A, point B)
{
	return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}
bool cmp(point m, point n)
{
	return (m.x ==n.x && m.y ==n.y);
}
int main()
{
	srand(time(0));
	point horse, end;
	static point path[399][39];
	cin >> end.x >> end.y >> horse.x >> horse.y;
	point temp;  int valid = 0; int fork; int flag=0; int count = 0;
	while( count<399)
	{
		temp.x = temp.y = 0; int step = 0; 
		while (temp.x <= end.x && temp.y <= end.y&&!cmp(temp, end))
		{
			fork = rand01();
			int tempx = temp.x, tempy = temp.y;
			if (temp.x < end.x && temp.y < end.y)
			{
				temp.x = temp.x + fork, temp.y = temp.y + 1 - fork;
			}
			else if (temp.x == end.x && temp.y < end.y)			
				temp.y++;				
			else			
				temp.x++;
			if (distance(temp, horse) != 5 && !cmp(temp, horse))
			{
				path[count][step] = temp;
				for (int i = 0; i < count; i++)
				{
					if (cmp(path[i][step], temp))
						flag++;
				}
				step++;
			}
			else if (tempx < end.x && tempy < end.y)
				temp.x--, temp.y--;
			else
			{
				flag = 999;
				break;
			}
		}
		if (flag < end.x + end.y - 1 && cmp(temp, end))
		{
			valid++;
			count++;
		}
		flag = 0;
	}
	cout << valid<<endl;
}//本地跑总是超时，只能借鉴一下模型思路
