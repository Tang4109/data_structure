/****************************************!
*@brief  
*@author ZhangYunjia
*@date   2019/8/14/17:43

****************************************/

//算法最终编译成具体的计算机指令
//每一个指令， 在具体的计算机CPU上运行速度固定
//通过具体的 n 个步骤， 就可以推导出算法的复杂度

#include<iostream>

using namespace std;

long sum1(int n)//2n+4步----算法复杂度O(n）
{
	long ret = 0;//1
	int* array = (int*)malloc(n * sizeof(int));//1
	int i = 0;//1
	for (i = 0; i < n; i++)//n
	{
		array[i] = i + 1;
	} 
	for (i = 0; i < n; i++)//n
	{
		ret += array[i];
	} 
	free(array);//1
	return ret;
} 

long sum2(int n)//n+2步----算法复杂度O(n）
{
	long ret = 0;//1
	int i = 0;//1
	for (i = 1; i <= n; i++)//n
	{
		ret += i;
	} 
	return ret;
} 
long sum3(int n)//2--和问题的规模没有关系----算法复杂度O(1）
{
	long ret = 0;//1
	if (n > 0)
	{
		ret = (1 + n) * n / 2;//1
	} 
	return ret;
} 

int main()
{
	printf("%d\n", sum1(100));
	printf("%d\n", sum2(100));
	printf("%d\n", sum3(100));
	return 0;
}

int func(int a[], int len)
{
	int i = 0;
	int j = 0;
	int s = 0;
	for (i = 0; i < len; i++) 
	{
	for (j = 0; j < len; j++) 
	{
	s += i * j; //n*n
	}
	} 
		return s;
}

	
