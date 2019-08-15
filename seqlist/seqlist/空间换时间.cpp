/****************************************!
*@brief  
*@author ZhangYunjia
*@date   2019/8/14/19:58

****************************************/

/*
	问题：
	在一个由自然数1-1000中某些数字所组成的数组中，每个数字可能出现零次或者多次。
	设计一个算法，找出出现次数最多的数字。
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

		sp[index]++;//数字n出现的次数放在新开辟的sp[n-1]的位置，把每一个数字的中间结果给缓存下来
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
