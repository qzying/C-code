// SqStack.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define MAXSIZE 1000

typedef int SElemType;

struct SqStack
{
	SElemType data[MAXSIZE];
	int top;
};

//初始化top = -1
void InitStack(SqStack * S)
{
	S->top = -1;
}

bool Push(SqStack * S,SElemType e)
{
	if (S->top == MAXSIZE - 1)
		return ERROR;
	S->top++;
	S->data[S->top] = e;
	return OK;
}

bool Pop(SqStack * S,SElemType * e)
{
	if(S->top == -1)
		return ERROR;
	*e = S->data[S->top];
	S->top--;
	return OK;
}

int _tmain(int argc, _TCHAR* argv[])
{
	SqStack SS;
	InitStack(&SS);

	Push(&SS,5);
	int x = 0;
	cout<<x<<endl;

	Pop(&SS,&x);
	cout<<x<<endl;

	return 0;
}

