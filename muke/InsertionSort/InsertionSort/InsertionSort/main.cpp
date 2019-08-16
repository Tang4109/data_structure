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
		//寻找元素arr[i]合适的插入位置
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
		//寻找[i,n)区间里的最小值
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