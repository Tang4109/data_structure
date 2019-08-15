#include "seqlist.h"
#include<iostream>
using namespace std;

struct _tag_SeqList 
{
	int length;
	int capacity;
	unsigned int* node;
};


//���� ����
SeqList* SeqList_Create(int capacity)
{
	int ret = 0;
	_tag_SeqList* tmp = NULL;
	tmp = new _tag_SeqList[sizeof(_tag_SeqList)];
	if (tmp==NULL)
	{
		ret = -1;
		cout << "func SeqList_Create() err:" << ret << endl;
		return NULL;
	}
	//����capacity�Ĵ�С����ڵ�ռ�
	tmp->node = new unsigned int[sizeof(unsigned int*)*capacity];
	if (tmp->node==NULL)
	{
		ret = -2;
		cout << "func SeqList_Create() err:" << ret << endl;
		return NULL;
	}
	tmp->capacity = capacity;
	tmp->length = 0;

	return tmp;

}

//���� ����
void SeqList_Destroy(SeqList* list)
{
	_tag_SeqList* tlist = NULL;
	if (list==NULL)
	{
		return ;
	}
	tlist = (_tag_SeqList*)list;
	if (tlist->node!=NULL)
	{
		delete tlist->node;
	}
	delete tlist;
	return;

}

////���� ���
void SeqList_Clear(SeqList* list)
{
	_tag_SeqList* tlist = NULL;
	if (list == NULL)
	{
		cout << "list is NULL" << endl;
		return;
	}
	tlist = (_tag_SeqList*)list;
	tlist->length = 0;

	return;

}

//���� ����
int SeqList_Length(SeqList* list)
{
	_tag_SeqList* tlist = NULL;
	if (list == NULL)
	{
		cout << "list is NULL" << endl;
		return -1;
	}
	tlist = (_tag_SeqList*)list;
	return tlist->length;

}


//���� ���� 
int SeqList_Capacity(SeqList* list)
{
	_tag_SeqList* tlist = NULL;
	if (list == NULL)
	{
		cout << "list is NULL" << endl;
		return -1;
	}
	tlist = (_tag_SeqList*)list;
	return tlist->capacity;

}

//���� ��ĳһ��λ�� ����Ԫ��
int SeqList_Insert(SeqList* list, SeqListNode* node, int pos)
{
	int ret = 0;
	_tag_SeqList* tlist = NULL;
	if (list==NULL||node==NULL||pos<0)
	{
		ret = -1;
		cout << "input err:"<< ret << endl;
		return ret;
	}
	tlist = (_tag_SeqList*)list;
	//��������
	if (tlist->length >= tlist->capacity)
	{
		ret = -2;
		cout << "��������" << endl;
		return ret;
	}
	//�ݴ�����
	if (pos > tlist->length)
	{
		pos = tlist->length;
	}

	//Ԫ�غ���
	int i = 0;
	for (i = tlist->capacity; i>pos; i--)
	{
		tlist->node[i] = tlist->node[i - 1];
	}
	//Ԫ�ز���
	tlist->node[i] = (unsigned int)node;
	tlist->length++;

	return 0;

}

//��ȡĳһ��λ�õ�������
SeqListNode* SeqList_Get(SeqList* list, int pos)
{
	int ret = 0;
	_tag_SeqList* tlist = NULL;
	if (list == NULL || pos < 0)
	{
		ret = -1;
		cout << "input err:" << ret << endl;
		return NULL;
	}
	tlist = (_tag_SeqList*)list;
	return (SeqListNode*)tlist->node[pos];

}

//ɾ��ĳһ��λ�õĽ��
SeqListNode* SeqList_Delete(SeqList* list, int pos)
{
	int ret = 0;
	int i = 0;
	_tag_SeqList* tlist = NULL;
	if (list == NULL || pos < 0)
	{
		ret = -1;
		cout << "input err:" << ret << endl;
		return NULL;
	}
	tlist = (_tag_SeqList*)list;
	
	for (i=pos+1;i<tlist->length;i++)
	{
		tlist->node[i - 1] = tlist->node[i];
	}
	tlist->length--;
	return (SeqList*)tlist->node[pos];

}





