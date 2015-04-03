// HashTable.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#define SUCCESS 1
#define UNSUCCESS 0
#define OK 1
#define ERROR 0
#define HASHSIZE 12
#define NULLKEY -32768

struct HashTable
{
	int *elem;
	int count;
};
int m = 0;
bool InitHashTable(HashTable *H)
{
	int i;
	m = HASHSIZE;
	H->count = m;
	H->elem = (int *)malloc(m*sizeof(int));
	for(i = 0;i<m;++i)
		H->elem[i] = NULLKEY;
	return OK;
}
int Hash(int key)
{
	return key % m;
}
void InsertHash(HashTable *H,int key)
{
	int addr = Hash(key);
	while(H->elem[addr] != NULLKEY)
		addr = (addr+1) % m;
	H->elem[addr] = key;
}
bool SearchHash(HashTable H,int key,int *addr)
{
	*addr = Hash(key);
	while(H.elem[*addr] != key)
	{
		*addr = (*addr + 1) % m;
		if(H.elem[*addr] == NULLKEY || *addr == Hash(key))
			return UNSUCCESS;
	}
	return SUCCESS;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int a[12] = {12,67,56,16,25,37,22,29,15,47,48,34};
	HashTable HH;
	InitHashTable(&HH);
	for(int i = 0;i<12;++i)
	{
		InsertHash(&HH,a[i]);
	}
	int x = 0;
	SearchHash(HH,48,&x);
	cout<<x<<endl;
	return 0;
}

