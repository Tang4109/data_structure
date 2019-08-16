/****************************************!
*@brief  
*@author ZhangYunjia
*@date   2019/8/15/12:31

****************************************/
#include "SortTestHelper.h"
#include "Student.h"


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

	int n = 10;
	int* arr = SortTestHelper::generateRandomArray(n,0,n);
	selectionSort(arr, n);
	SortTestHelper::printArray(arr, n);

	float b[5] = { 1.3,2.5,3.2,6.5,5.9 };
	selectionSort(b, 5);
	SortTestHelper::printArray(b, 5);
	
	string c[4] = { "D","C","B","A" };
	selectionSort(c, 4);
	SortTestHelper::printArray(c, 4);

	Student d[4] = { {"D",90},{"C",100},{"B",95},{"A",95} };
	selectionSort(d, 4);
	SortTestHelper::printArray(d, 4);

	delete[] arr;

	n = 100000;
	int* arr2 = SortTestHelper::generateRandomArray(n, 0, n);
	SortTestHelper::testSort("selectionSort", selectionSort, arr2, n);
	delete[] arr2;

	cout<<"end.."<<endl;
	system("pause");
	return 0;
}