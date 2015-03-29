// LinkStack.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define MAXSIZE 1000

typedef int SElemType;

struct StackNode
{
	SElemType data;
	StackNode * next;
};

typedef StackNode * LinkStackPtr;

struct LinkStack
{
	LinkStackPtr top;
	int count;
};

void InitStack(LinkStack * S)
{
	S->count = 0;
}

bool StackEmpty(LinkStack S)
{
	if(S.count == 0)
		return OK;
	else 
		return ERROR;
}

bool Push(LinkStack * S,SElemType e)
{
//	LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
	LinkStackPtr s = new StackNode;
	s->data = e;
	s->next = S->top;
	S->top = s;
	S->count++;
	return OK;
}

bool Pop(LinkStack * S,SElemType * e)
{
	LinkStackPtr p;
	if(StackEmpty(*S))
		return ERROR;
	*e = S->top->data;
	p = S->top;
	S->top = S->top->next;
//	free(p);
	delete p;
	S->count--;
	return OK;
}

int _tmain(int argc, _TCHAR* argv[])
{
	LinkStack LS;
	InitStack(&LS);
	Push(&LS,999);
	int x = 0;
	cout<<x<<endl;
	Pop(&LS,&x);
	cout<<x<<endl;
	return 0;
}

