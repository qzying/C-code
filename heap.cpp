// heap.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
/*
*	默认是less<int>() 最大堆，greter<int>()最小堆
*	greter<int>()包含在 #include <functional>
*	make_heap等包含在 #include <algorithm>
*/
int _tmain(int argc, _TCHAR* argv[])
{
	int a[9]={5,99,2,3,4,8,9,3,5};
	vector<int> v(a,a+9);
	cout<<v.front()<<endl;

	make_heap(v.begin(),v.end(),greater<int>());
	cout<<v.front()<<endl;

	pop_heap(v.begin(),v.end(),greater<int>());
	v.pop_back();
	cout<<v.front()<<endl;
	
	v.push_back(100);
	push_heap(v.begin(),v.end(),greater<int>());
	cout<<v.front()<<endl;

	return 0;
}

