/****************************************!
*@brief  
*@author ZhangYunjia
*@date   2019/8/16/21:11

****************************************/

#include "SortTestHelper.h"

template<typename T>
void insertionSort(T arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		//Ѱ��Ԫ��arr[i]���ʵĲ���λ��
		for (int j = i; j > 0; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				swap(arr[j], arr[j - 1]);
			}
		}
	}
}

template<typename T>
void selectionSort(T arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		//Ѱ��[i,n)���������Сֵ
		int minIndex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}
		swap(arr[i], arr[minIndex]);

	}
}



int main()
{
	int n = 10000;
	int* arr = SortTestHelper::generateRandomArray(n, 0, n);
	int* arr2 = SortTestHelper::copyIntArray(arr, n);
	SortTestHelper::testSort("selectionSort", selectionSort, arr, n);
	SortTestHelper::testSort("insertionSort", insertionSort, arr2, n);


	delete[] arr;
	delete[] arr2;
	cout<<"end.."<<endl;
	system("pause");
	return 0;
}