// s.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

const static long long FREQUENCY = 3.2*1e9;//3.2GHZ

inline unsigned __int64 GetCycleCount()
{
    __asm
    {
        _emit 0x0F;
        _emit 0x31;
    }
}

int _tmain(int argc, _TCHAR* argv[])
{
	unsigned long t1,t2;
	string s1 = "abc";
	string s2 = "123";
	string s3 = "abc";
	string s4 = "123";

	t1 = (unsigned long)GetCycleCount();
	for(int i=0;i<100;++i)
	{
		s1 += s2;
	}
    t2 = (unsigned long)GetCycleCount();
	cout<<(t2 - t1)*1.0/FREQUENCY<<endl;

	t1 = (unsigned long)GetCycleCount();
	for(int i=0;i<100;++i)
	{
		s3.append(s4);
	}
    t2 = (unsigned long)GetCycleCount();
	cout<<(t2 - t1)*1.0/FREQUENCY<<endl;

	cout<<s1<<endl;
	cout<<s3<<endl;

	return 0;
}

