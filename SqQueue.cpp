// SqQueue.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define MAXSIZE 1000

typedef int QElemType;

struct SqQueue
{
	QElemType data[MAXSIZE];
	int front;
	int rear;
};

bool InitQueue(SqQueue * Q)
{
	Q->front = 0;
	Q->rear = 0;
	return OK;
}

int QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

bool EnQueue(SqQueue * Q,QElemType e)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)
		return ERROR;
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	return OK;
}

bool DeQueue(SqQueue * Q,QElemType * e)
{
	if(Q->front == Q->rear)
		return ERROR;
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return OK;
}
int _tmain(int argc, _TCHAR* argv[])
{
	SqQueue SQ;
	InitQueue(&SQ);
	EnQueue(&SQ,999);
	int x = 0;
	cout<<QueueLength(SQ)<<endl;
	DeQueue(&SQ,&x);
	cout<<x<<endl;
	cout<<QueueLength(SQ)<<endl;
	return 0;
}

