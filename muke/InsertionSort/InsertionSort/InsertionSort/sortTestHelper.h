#pragma once //解决.h文件的多重引用的问题
#include <iostream>
#include <ctime>
#include <cassert>
#include <string>
using namespace std;

namespace SortTestHelper
{
	//生成有n个元素的随机数，范围是[rangeL,rangeR]
	int* generateRandomArray(int n, int rangeL, int rangeR)
	{
		assert(rangeL <= rangeR);

		int* arr = new int[n];
		srand(time(NULL));
		for (int i = 0; i < n; i++)
		{
			arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;

		}
		return arr;
	}
	//打印输出
	template<typename T>
	void printArray(T* arr, int n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	//判断是否正确排序
	template<typename T>
	bool isUpSorted(T arr[], int n)
	{
		for (int i = 0; i < n - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				return false;
			}
		}
		return true;
	}
	//判断是否正确排序
	template<typename T>
	bool isDownSorted(T arr[], int n)
	{
		for (int i = 0; i < n - 1; i++)
		{
			if (arr[i] < arr[i + 1])
			{
				return false;
			}
		}
		return true;
	}

	//测试算法的性能
	template<typename T>
	void testSort(string sortName, void(*sort)(T[], int), T arr[], int n)
	{
		clock_t startTime = clock();
		sort(arr, n);
		clock_t endTime = clock();
		assert(isUpSorted(arr, n));
		cout << sortName << ": " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
		return;

	}

	//拷贝数组
	template<typename T>
	T* copyIntArray(T a[], int n)
	{
		T* arr = new T[n];
		copy(a, a + n, arr); //深拷贝
		return arr;
	}



}