/****************************************!
*@brief  
*@author ZhangYunjia
*@date   2019/7/30/14:59

****************************************/

#include<iostream>
#include "seqlist.h"

using namespace std;

struct Teacher 
{
	int age;
	char name[64];

};


int main()
{
	int ret = 0;

	//创建
	SeqList* list = NULL;
	list = SeqList_Create(10);
	//if (list==NULL)
	//{
	//	ret = -1;
	//	cout << "error:" << ret << endl;
	//	return ret;
	//}

	Teacher t1, t2, t3, t4, t5;

	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	t4.age = 34;
	t5.age = 35;

	//插入
	ret = SeqList_Insert(list, &t1, 0);
	ret = SeqList_Insert(list, (SeqListNode*)&t2, 0);
	ret = SeqList_Insert(list, (SeqListNode*)&t3, 0);
	ret = SeqList_Insert(list, (SeqListNode*)&t4, 0);
	ret = SeqList_Insert(list, (SeqListNode*)&t5, 0);

	//遍历
	for (int i=0;i< SeqList_Length(list);i++)
	{
		Teacher* tmp = (Teacher*)SeqList_Get(list, i);
		if (tmp==NULL)
		{
			ret = -2;
			return ret;
		}
		cout << tmp->age << endl;
	}
	//删除
	while (SeqList_Length(list))
	{
		SeqList_Delete(list, 0);

	}
	


	
	cout<<"end.."<<endl;
	system("pause");
	return 0;
}