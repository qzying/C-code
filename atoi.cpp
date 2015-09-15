// atoi.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

enum Status { Valid = 0,inValid };
int g_status = Valid;

long long StrToIntCore(const char*, bool);

int StrToInt(const char* str)
{
	g_status = inValid;
	long long num = 0;
	if (str != NULL && *str != '\0')
	{
		bool minus = false;
		if (*str == '+')
			str++;
		else if (*str == '-')
		{
			str++;
			minus = true;
		}
		if (*str != '\0')
		{
			num = StrToIntCore(str,minus);
		}
	}
	return (int)num;
}
long long StrToIntCore(const char* digit, bool minus)
{
	long long num = 0;
	while (*digit != '\0')
	{
		if (*digit >= '0' && *digit <= '9')
		{
			int flag = minus ? -1 : 1;
			num = num * 10 + flag * (*digit - '0');
			if ((!minus && num > 0x7FFFFFFF) || (minus && num < (signed int)0x80000000))
			{
				num = 0;
				break;
			}
			digit++;
		}
		else
		{
			num = 0;
			break;
		}
	}
	if (*digit == '\0')
		g_status = Valid;
	return num;
}
int main()
{
	char* s = "0";
	int r = StrToInt(s);
	cout << r << endl;
	cout << g_status << endl;
    return 0;
}

