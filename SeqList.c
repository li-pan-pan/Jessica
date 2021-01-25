#include"SeqList.h"
void SeqListInit(SeqList* ps)
{
	ps->a = (SLDateType*)malloc((sizeof(SLDateType)* 4));
	if (ps->a == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	ps->size = 0;
	ps->capacity = 4;
}
void SeqListDestory(SeqList* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}
void SeqListPrint(SeqList* ps)
{
	for (int i = 0; i < ps->size; ++i)
	{
		printf("%d  ", ps->a[i]);
	}
	printf("\n");
}
void CheckCapacity(SeqList* ps)
{
	if (ps->size == ps->capacity)
	{
		SLDateType* temp = (SLDateType*)realloc(ps->a,sizeof(SLDateType)*ps->capacity * 2);
		if (temp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->a = temp;
		ps->capacity *= 2;
	}
}
void SeqListPushBack(SeqList* ps, SLDateType x)
{
	assert(ps);
	CheckCapacity(ps);
	ps->a[ps->size] = x;
	++ps->size;
}
void SeqListPushFront(SeqList* ps, SLDateType x)
{
	assert(ps);
	CheckCapacity(ps);
	for (int i = ps->size; i > 0; --i)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[0] = x;
}
void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	for (int i = 0; i <= ps->size-2; ++i)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}
void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	assert(ps->size>0);
	ps->size--;
}
void SeqListFind(SeqList* ps, SLDateType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; ++i)
	{
		if (ps->a[i] == x)
		{
			printf("找到该数字了，它的位置在%d\n", i);
			break;
		}
	}
	printf("找不到该数字\n");
}
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
{
	assert(ps);
	CheckCapacity(ps);
	for (int i = ps->size; i >=pos; --i)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[pos - 1] = x;
	++ps->size;
	printf("已经放入\n");
}
void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps);
	for (int i = pos-1; i < ps->size; ++i)
	{
		ps->a[i] = ps->a[i + 1];
	}
	--ps->size;
}
