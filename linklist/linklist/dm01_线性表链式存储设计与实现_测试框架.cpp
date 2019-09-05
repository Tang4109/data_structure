
#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include "linklist.h"
using namespace std;

struct Teacher
{
	LinkListNode node;
	
	char		name[32];
	int			age ;
};


void main()
{
	LinkList	*list = NULL;
	int			i = 0;

	Teacher t1, t2, t3, t4, t5, t6;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	t4.age = 34;
	t5.age = 35;
	t6.age = 36;

	list = LinkList_Create();

	//思考1: 业务节点 和 链表算法是如何分离
	//思考2:  业务节点的生命周期 归谁管...

	cout << &t1 << " " << &t1.node << endl;
	cout << &t1 << " " << &t1.age<< endl;


	//插入元素
	LinkList_Insert(list, (LinkListNode *)&t1, 0);
	LinkList_Insert(list, (LinkListNode *)&t2, 0);
	LinkList_Insert(list, (LinkListNode *)&t3, 0);
	LinkList_Insert(list, (LinkListNode *)&t4, 0);
	LinkList_Insert(list, (LinkListNode *)&t5, 0);
	LinkList_Insert(list, (LinkListNode *)&t6, 3);


	//遍历链表
	for (i=0; i<LinkList_Length(list); i++)
	{
		Teacher *tmp = (Teacher *)LinkList_Get(list, i);
		if (tmp == NULL)
		{
			return ;
		}
		cout << "age: " << tmp->age << endl;
	}


	//删除链表结点
	while (LinkList_Length(list) > 0)
	{
		Teacher *tmp = (Teacher *)LinkList_Delete(list, 0);
		if (tmp == NULL)
		{
			return ;
		}
		cout << "age: " << tmp->age << endl;

	}

	LinkList_Destroy(list);


	printf("hello...\n");
	system("pause");
	return ;
}