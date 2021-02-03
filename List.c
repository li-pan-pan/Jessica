#include"List.h"
ListNode* BuyListNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = x;
	node->next = NULL;
	node->prev = NULL;
	return node;
}
ListNode* ListCreate()
{
	ListNode* phead = (ListNode*)malloc(sizeof(ListNode));
	phead->next = phead;
	phead->prev = phead;
	return phead;
}
void ListDestory(ListNode* pHead)
{
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		ListNode* next = cur->next;
		ListErase(cur);
		cur = next;
	}
	free(pHead);
	pHead = NULL;
}
void ListPrint(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		printf("%d  ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* newnode = BuyListNode(x);
	ListNode* cur = pHead->prev;
	cur->next = newnode;
	newnode->prev = cur;
	pHead->prev = newnode;
	newnode->next = pHead;
}
void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	assert(pHead->next!=pHead);
	ListNode* tail = pHead->prev;
	ListNode* tailprev = tail->prev;
	tailprev->next = pHead;
	pHead->prev = tailprev;
	free(tail);
	tail = NULL;
}
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* head = pHead->next;
	ListNode* newnode = BuyListNode(x);
	pHead->next = newnode;
	newnode->prev = pHead;
	newnode->next = head;
	head->prev = newnode;
}
void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	assert(pHead->next != pHead);
	ListNode* head = pHead->next;
	ListNode* headnext = head->next;
	pHead->next = headnext;
	headnext->prev = pHead;
	free(head);
	head = NULL;
}
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* posprev = pos->prev;
	ListNode* newnode = BuyListNode(x);
	posprev->next = newnode;
	newnode->prev = posprev;
	pos->prev = newnode;
	newnode->next = pos;
}
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* posPrev = pos->prev;
	ListNode* posNext = pos->next;
	posPrev->next = posNext;
	posNext->prev = posPrev;
	free(pos);
	pos = NULL;
}
