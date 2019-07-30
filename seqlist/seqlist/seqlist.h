#pragma once

typedef void SeqList;
typedef void SeqListNode;

//���� ����
SeqList* SeqList_Create(int capacity);

//���� ����
void SeqList_Destroy(SeqList* list);

////���� ���
void SeqList_Clear(SeqList* list);

//���� ����
int SeqList_Length(SeqList* list);


//���� ���� 
int SeqList_Capacity(SeqList* list);

//���� ��ĳһ��λ�� ����Ԫ��
int SeqList_Insert(SeqList* list, SeqListNode* node, int pos);

//��ȡĳһ��λ�õ�������
SeqListNode* SeqList_Get(SeqList* list, int pos);

//ɾ��ĳһ��λ�õĽ��
SeqListNode* SeqList_Delete(SeqList* list, int pos);





