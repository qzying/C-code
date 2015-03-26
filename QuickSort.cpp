// sort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stack>
#include <iostream>
using namespace std;

int Partition(int * x,int low,int high)
{
	int key = x[low];
	while(low < high)
	{
		while((low < high)&&(x[high] >= key))--high;
		x[low] = x[high];
		while((low < high)&&(x[low] <= key))++low;
		x[high] = x[low];
	}
	x[low] = key;
	return low;
}
//快排递归实现
void QuickSort(int * x,int low,int high)
{
	if (low < high)
	{
		int pivotloc = Partition(x,low,high);
		QuickSort(x,low,pivotloc-1);
		QuickSort(x,pivotloc+1,high);
	}
}

//快排非递归C实现
void QuickSortND1(int * x,int len)
{
	int * stk = new int[len];
	int p = 0;
	int l,h,m;
	stk[p++] = 0;
	stk[p++] = len-1;
	while(p!=0)
	{
		h = stk[--p];
		l = stk[--p];
		m = Partition(x,l,h);
		if(m-1 > l)
		{
			stk[p++] = l;
			stk[p++] = m-1;		
		}
		if(m+1 < h)
		{
			stk[p++] = m+1;
			stk[p++] = h;
		}
		
	}
	delete [] stk;

}
//快排非递归C++实现,使用栈实现
void QuickSortND2(int * x,int low,int high)
{
    stack<int> st; 	
    st.push(low);
    st.push(high);        
   //用栈保存每一个待排序子串的首尾元素下标，下一次while循环时取出这个范围，对这段子序列进行Partition操作
    while(!st.empty())
	{
        int q = st.top();
        st.pop();
        int p = st.top();
        st.pop();
        int mid = Partition(x,p,q);
        if(p < mid-1)
		{
            st.push(p);
            st.push(mid-1);
        }
        if(mid+1 < q)
		{
            st.push(mid+1);
            st.push(q);
        }       
     }
}
 
int _tmain(int argc, _TCHAR* argv[])
{
	int a[5]={67,2,45,103,17};
	for(int i=0;i<5;++i)
	{
		cout<<a[i]<<endl;
	}
	cout<<"============"<<endl;
//	QuickSort(a,0,sizeof(a)/sizeof(a[0])-1);
	QuickSortND1(a,sizeof(a)/sizeof(a[0]));
//	QuickSortND2(a,0,sizeof(a)/sizeof(a[0])-1);
	for(int i=0;i<5;++i)
	{
		cout<<a[i]<<endl;
	}
	return 0;
}

