#include"ContactBook.h"
#include<stdio.h>
void ContactBookTest()
{
	ContactBook cb;
	ContactBookInit(&cb);

	Contact ct1 = { "张飞", "18392977286", "绵竹", 40 };
	ContactBookAdd(&cb, &ct1);

	Contact ct2 = { "关羽", "15129187320", "荆竹", 45 };
	ContactBookAdd(&cb, &ct2);

	ContactBookPrint(&cb);
}
void Menu()
{
	ContactBook cb;
	ContactBookInit(&cb);

	Contact ct1 = { "张飞", "18392977286", "绵竹", 40 };
	ContactBookAdd(&cb, &ct1);

	Contact ct2 = { "关羽", "15129187320", "荆竹", 45 };
	ContactBookAdd(&cb, &ct2);

	int option = 0;

	do
	{
		printf("**********************************\n");
		printf("*******  1.添加联系人  ***********\n");
		printf("*******  2.删除联系人  ***********\n");
		printf("*******  3.修改联系人  ***********\n");
		printf("*******  4.查找联系人  ***********\n");
		printf("*******  5.展示联系人  ***********\n");
		printf("*******  0.退出        ***********\n");
		printf("**********************************\n");
		scanf("%d", &option);
		if (option == 1)
		{
			printf("请依次输入联系人的姓名、地址、联系方式、年龄:\n");
			Contact ct;
			scanf("%s", ct.name);
			scanf("%s", ct.address);
			scanf("%s", ct.tel);
			scanf("%d", &ct.age);

			ContactBookAdd(&cb, &ct);
			printf("添加成功\n");
		}
		else if (option == 2)
		{
			printf("请输入要删除联系人的姓名\n");
			char name[NAME_MAX];
			scanf("%s", name);
			ContactBookDel(&cb, name);
		}
		else if (option == 3)
		{
			printf("请依次输入联系人的姓名、地址、联系方式、年龄:\n");
			Contact ct;
			scanf("%s", ct.name);
			scanf("%s", ct.address);
			scanf("%s", ct.tel);
			scanf("%d", &ct.age);

			ContactUpdate(&cb, &ct);
		}
		else if (option == 4)
		{
			printf("请输入要查找联系人的姓名\n");
			char name[NAME_MAX];
			scanf("%s", name);
			Contact* pc = ContactBookSearch(&cb, name);
			if (pc)
			{
				printf("查找成功\n");
				printf("name:%s\n", pc->name);
				printf("addr:%s\n", pc->address);
				printf("tel:%s\n", pc->tel);
				printf("age:%d\n", pc->age);
				printf("\n");
			}

		}
		else if (option == 5)
		{
			ContactBookPrint(&cb);
		}
		else if (option != 0)
		{
