/*
输入12个字母，输入对应的字典顺序，如abcdefghijkl对应1
*/
#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int getNum(int n)
{
	int r = 1;
	for (int i = 1; i <= n; ++i)
	{
		r *= i;
	}
	return r;
}

int minNum(const string& s, int i)
{
	int sum = 0;
	char s0 = s[i];
	for (int j = i + 1; j<12; ++j)
	{
		if (s[j] < s0)
			++sum;
	}
	return sum;
}

int getCount(const string& s)
{
	int count = 1;
	for (int i = 0; i<12; ++i)
	{
		int tmp = minNum(s, i);
		count += tmp*getNum(11 - i);
	}
	return count;
}

int main()
{
	int n = 0;
	vector<string> s;
	cin >> n;
	while (n-->0)
	{
		string tmp;
		cin >> tmp;
		s.push_back(tmp);
	}
	vector<int> result;
	for (vector<string>::iterator i = s.begin(); i != s.end(); ++i)
	{
		result.push_back(getCount(*i));
	}
	for (vector<int>::iterator i = result.begin(); i != result.end(); ++i)
	{
		cout << *i << endl;
	}
	return 0;
}
