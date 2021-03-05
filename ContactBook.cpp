#include"ContactBook.h"
#include<stdio.h>
void ContactBookInit(ContactBook* pcb)
{
	assert(pcb);
	pcb->size = 0;
	memset(pcb->array, 0, sizeof(Contact)*CONTACT_BOOK_MAX);
}
void ContactBookAdd(ContactBook*pcb, Contact* pc)
{
	assert(pcb);
	assert(pc);

	if (pcb->size == CONTACT_BOOK_MAX)
	{
		printf("通讯录已满\n");
		return;
	}
	memcpy(&pcb->array[pcb->size], pc, sizeof(Contact));
	pcb->size++;
}
void ContactBookPrint(ContactBook* pcb)
{
	for (int i = 0; i < pcb->size; ++i)
	{
		printf("name:%s\n", pcb->array[i].name);
		printf("addr:%s\n", pcb->array[i].address);
		printf("tel:%s\n", pcb->array[i].tel);
		printf("age:%d\n", pcb->array[i].age);
		printf("\n");

	}
}
void ContactBookDel(ContactBook* pcb, char* name)
{
	assert(pcb);
	assert(name);

	int i = 0;
	for (; i < pcb->size; ++i)
	{
		if (strcmp(pcb->array[i].name, name) == 0)
		{//删除
			memmove(pcb->array + i, pcb->array + i + 1, (pcb->size - i - 1)*sizeof(Contact));
			break;
		}
	}
	if (i == pcb->size)
	{
		printf("删除失败，查无此人\n");
	}
	else
	{
		pcb->size--;
		printf("删除成功\n");
	}

}

void ContactUpdate(ContactBook* pcb, Contact* pc)
{
	assert(pcb);
	assert(pc);

	int i = 0;
	for (; i < pcb->size; ++i)
	{
		if (strcmp(pcb->array[i].name, pc->name) == 0)
		{
			memcpy(pcb->array + i, pc,sizeof(Contact));
			break;
		}
	}
	if (i == pcb->size)
	{
		printf("修改失败，查无此人\n");
	}
	else
	{
		printf("修改成功\n");
	}
}
Contact* ContactBookSearch(ContactBook* pcb, char* name)
{
	for (int i = 0; i < pcb->size; ++i)
	{
		if (strstr(pcb->array[i].name, name) != NULL)
		{
			return &pcb->array[i];
		}
	}
	printf("查无此人\n");
	return NULL;

}
