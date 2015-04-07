// struct_sort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <ctime>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct pos
{
	int x;
	int y;
	int z;
};

bool judge(const pos &a,const pos &b)
{
	if(a.x != b.x)
		return a.x<b.x;
	else if(a.y!=b.y)
		return a.y<b.y;
	else 
		return a.z<b.z;
}
int _tmain(int argc, _TCHAR* argv[])
{
	vector<pos> pp;
	for(int i=0;i<100;++i)
	{
		srand(i);
		pos temp;
		int x0 = rand()%100;
		int y0 = rand()%100;
		int z0 = rand()%100;
		temp.x = x0;
		temp.y = y0;
		temp.z = z0;
		pp.push_back(temp);
	}
	for(vector<pos>::iterator i=pp.begin();i!=pp.end();++i)
	{
		cout<<i->x<<" "<<i->y<<" "<<i->z<<" "<<endl;
	}
	sort(pp.begin(),pp.end(),judge);
	for(vector<pos>::iterator i=pp.begin();i!=pp.end();++i)
	{
		cout<<i->x<<" "<<i->y<<" "<<i->z<<" "<<endl;
	}
	return 0;
}

