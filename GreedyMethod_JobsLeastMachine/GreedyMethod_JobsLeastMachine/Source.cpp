#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

struct Job
{
	int id;
	int s;
	int f;
};

bool compare(Job a, Job b)
{
	return a.s < b.s;
}

bool compareID(Job a, Job b)
{
	return a.id < b.id;
}

int main()
{
	Job j[7] = { {0,0,2},{1,3,7},{2,4,7},{3,9,11},{4,7,10},{5,1,5},{6,6,8}};
	map<int, int> map_job_mach;
	map<int, int> map_mach_f;
	sort(&j[0], &j[0] + 7, compare);
	int machNum = 0;
	bool find = false;
	for (int i = 0; i < 7; i++)
	{
		if (machNum == 0)
		{
			map_job_mach[j[i].id] = machNum;
			map_mach_f[machNum] = j[i].f;
			machNum++;
		}
		else
		{
			find = false;
			for (int h = 0; h < machNum; h++)
			{
				if (j[i].s >= map_mach_f[h])
				{
					map_job_mach[j[i].id] = h;
					map_mach_f[h] = j[i].f;
					find = true;
					break;
				}
			}
			if (!find)
			{
				map_job_mach[j[i].id] = machNum;
				map_mach_f[machNum] = j[i].f;
				machNum++;
			}
		}
	}
	sort(&j[0], &j[0] + 7, compareID);
	for (int i = 0; i < 7; i++)
	{
		cout << j[i].s << " " << j[i].f << " " << map_job_mach[i] << endl;
	}
	return 0;
}