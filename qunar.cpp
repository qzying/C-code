/*
输入一系列linux版本号，输出对应的最新稳定版本号
*/
#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct kernel
{
	kernel(int a0,int b0,int c0):a(a0),b(b0),c(c0){}
	kernel& operator=(const kernel& r)
	{
		a = r.a;
		b = r.b;
		c = r.c;
		return *this;
	}
	int a;
	int b;
	int c;
};

kernel getNumber(string& s)
{
	string a, b, c;
	int flag = 0;
	int n = s.size();
	for (int i = 0; i < n; ++i)
	{
		if (s[i] == '.')
		{
			++flag;
			continue;
		}
		if (flag == 0)
			a += s[i];
		else if (flag == 1)
			b += s[i];
		else
			c += s[i];
	}
	kernel r(atoi(a.c_str()), atoi(b.c_str()), atoi(c.c_str()));
	return r;
}
kernel getStable(vector<string>& s)
{
	kernel result(0,0,0);
	for (vector<string>::iterator i = s.begin(); i != s.end(); ++i)
	{
		kernel tmp = getNumber(*i);
		if ((tmp.b & 1) == 0)
		{
			if (tmp.a>result.a)
			{
				result = tmp;
			}
			else if (tmp.a == result.a)
			{
				if (tmp.b>result.b)
				{
					result = tmp;
				}
				else if (tmp.b == result.b && tmp.c > result.c)
				{
					result = tmp;
				}
			}
		}
	}
	return result;
}

int main()
{
	int n;
	cin >> n;
	vector<string> s;
	for (int i = 0; i<n; ++i)
	{
		string tmp;
		cin >> tmp;
		s.push_back(tmp);
	}
	kernel k = getStable(s);
	if (k.a == 0 && k.b == 0 && k.c == 0)
		cout << "no stable available";
	else if (k.c == 0 && k.b == 0)
		cout << k.a;
	else if (k.c == 0 && k.b != 0)
		cout << k.a << '.' << k.b;
	else if (k.c != 0)
		cout << k.a << '.' << k.b << '.' << k.c;
	return 0;
}