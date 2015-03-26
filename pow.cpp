// pow.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
double pow(double x,int n)
{
if(n<0)  
        {  
            if(n==INT_MIN)  
                return 1.0 / (pow(x,INT_MAX)*x);  
            else  
                return 1.0 / pow(x,-n);  
        }  
        if(n==0)  
            return 1.0;  
        double ans = 1.0 ;  
        for(;n>0; x *= x, n>>=1)  
        {  
            if(n&1>0)  
                ans *= x;  
        }  
        return ans;  
}
int _tmain(int argc, _TCHAR* argv[])
{
	cout<<pow(2,6)<<endl;
	return 0;
}

