// 999999.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	int count =0;
	for(int i=0;i<1000000;++i)
	{
		int m= i;
		while(m>0)
		{
			if (m%10==1)
				goto A;
			m=m/10;
		}
		count++;
		A:;
	}
	cout<<count<<endl<<9*9*9*9*9*9;
	return 0;
}

