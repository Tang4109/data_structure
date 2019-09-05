
#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include "linklist.h"
using namespace std;

struct TLinkList
{
	LinkListNode header; 
	int		length;
};

LinkList* LinkList_Create()  //O(1)
{
	TLinkList *tmp = NULL;
	//tmp = (TLinkList *)malloc(sizeof(TLinkList));
	tmp = new TLinkList[sizeof(TLinkList)];
	if (tmp == NULL)
	{
		cout << "func LinkList_Create() err" << endl;
		return NULL;
	}
	//memset(tmp, 0, sizeof(TLinkList));
	tmp->length = 0;
	tmp->header.next = NULL; 
	return tmp;
}

void LinkList_Destroy(LinkList* list)  //O(1)
{
	if (list == NULL)
	{
		return ;
	}
	delete list;
	return ;
}

void LinkList_Clear(LinkList* list)   //O(1)
{
	TLinkList *tList = NULL;
	tList = (TLinkList *)list;
	if (tList == NULL)
	{
		return ;
	}
	tList->header.next = NULL;
	tList->length = 0;

	return ;
}

int LinkList_Length(LinkList* list)  //O(1)
{
	TLinkList *tList = NULL;
	tList = (TLinkList *)list;
	if (tList == NULL)
	{
		return -1;
	}
	return tList->length;
}

int LinkList_Insert(LinkList* list, LinkListNode* node, int pos)  //O(n)
{
	int				i = 0;
	LinkListNode	*current = NULL;
	TLinkList		*tList = NULL;

	tList = (TLinkList *)list;
	
	if (list==NULL || node==NULL || pos<0)
	{
		return -1;
	}

	current = &(tList->header);
	for (i=0; i<pos; i++)
	{
		current = current->next;
	}
	//�½�� ���� �������
	node->next = current->next;

	//ǰ������� ���� �½��
	current->next = node;

	tList->length ++;
	return 0;
}

LinkListNode* LinkList_Get(LinkList* list, int pos)  //O(n)
{
	int				i = 0;
	LinkListNode	*current = NULL;
	TLinkList		*tList = NULL;

	tList = (TLinkList *)list;

	if (list==NULL || pos<0)
	{
		return NULL;
	}

	current = &(tList->header); //��ֵָ�������ʼ��
	for (i=0; i<pos; i++)
	{
		current = current->next;
	}
	return current->next;
}

LinkListNode* LinkList_Delete(LinkList* list, int pos) //O(n)
{
	int				i = 0;
	LinkListNode	*current = NULL;
	LinkListNode	*ret = NULL;
	TLinkList		*tList = NULL;

	tList = (TLinkList *)list;
	if (list==NULL || pos<0)
	{
		return NULL;
	}

	current = &(tList->header);
	for (i=0; i<pos; i++)
	{
		current = current->next;
	}
	ret = current->next; //����Ҫɾ���Ľ��

	current->next = ret->next;

	tList->length --;

	return ret;
}

