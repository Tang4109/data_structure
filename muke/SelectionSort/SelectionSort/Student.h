#pragma once
/****************************************!
*@brief  
*@author ZhangYunjia
*@date   2019/8/15/14:22

****************************************/

#include<iostream>

using namespace std;

struct Student
{
	string name;
	int score;

	bool operator<(const Student& otherStudent)
	{
		return score != otherStudent.score ? score > otherStudent.score : name < otherStudent.name; //三目运算符
	}
	//类的友元函数有权访问类的所有私有（private）成员和保护（protected）成员
	friend ostream& operator<<(ostream& os, const Student& student)
	{
		os << "Student_name: " << student.name << " " << "Student_score: " << student.score << " " << endl;
		return os; //使用返回引用提供链式赋值支持
	}

};
