/****************************************!
*@brief  
*@author ZhangYunjia
*@date   2019/8/14/19:58

****************************************/

/*
	���⣺
	��һ������Ȼ��1-1000��ĳЩ��������ɵ������У�ÿ�����ֿ��ܳ�����λ��߶�Ρ�
	���һ���㷨���ҳ����ִ����������֡�
*/




#include<iostream>

using namespace std;

void search(int a[], int len)
{
	int sp[1000] = { 0 };
	int i = 0;
	int max = 0;

	for (i = 0; i < len; i++)
	{
		int index = a[i] - 1;

		sp[index]++;//����n���ֵĴ��������¿��ٵ�sp[n-1]��λ�ã���ÿһ�����ֵ��м�������������
	}

	for (i = 0; i < 1000; i++)
	{
		if (max < sp[i])
		{
			max = sp[i];
		}
	}

	for (i = 0; i < 1000; i++)
	{
		if (max == sp[i])
		{
			cout << (i + 1) << endl;
		}
	}
}

int main()
{
	int array[] = { 1, 1, 3, 4, 5, 6, 6, 6, 2, 3 };
	cout << sizeof(array) << endl;
	cout << sizeof(*array) << endl;


	search(array, sizeof(array) / sizeof(*array));
	system("pause");
	return 0;
}
