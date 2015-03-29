// SqDoubleStack.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define MAXSIZE 1000

typedef int SElemType;

struct SqDoubleStack
{
	SElemType data[MAXSIZE];
	int top1;
	int top2;
};

void InitSqDoubleStack(SqDoubleStack * S)
{
	S->top1 = -1;
	S->top2 = MAXSIZE;
}

bool Push(SqDoubleStack * S,SElemType e,int stackNumber)
{
	if(S->top1+1==S->top2)
		return ERROR;
	if(stackNumber==1)
		S->data[++S->top1]=e;
	else if(stackNumber==2)
		S->data[--S->top2]=e;
	return OK;
}

bool Pop(SqDoubleStack * S,SElemType * e,int stackNumber)
{
	if(stackNumber==1)
	{
		if(S->top1==-1)
			return ERROR;
		*e=S->data[S->top1--];
	}
	else if(stackNumber==2)
	{
		if(S->top2==MAXSIZE)
			return ERROR;
		*e=S->data[S->top2++];
	}
	return OK;
}

int _tmain(int argc, _TCHAR* argv[])
{
	SqDoubleStack SDS;
	InitSqDoubleStack(&SDS);
	Push(&SDS,3,1);
	Push(&SDS,7,2);
	int x = 0,y = 0;
	cout<<x<<endl;
	cout<<y<<endl;
	Pop(&SDS,&x,1);
	Pop(&SDS,&y,2);
	cout<<x<<endl;
	cout<<y<<endl;
	return 0;
}

