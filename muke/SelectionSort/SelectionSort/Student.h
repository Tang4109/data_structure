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
		return score != otherStudent.score ? score > otherStudent.score : name < otherStudent.name; //��Ŀ�����
	}
	//�����Ԫ������Ȩ�����������˽�У�private����Ա�ͱ�����protected����Ա
	friend ostream& operator<<(ostream& os, const Student& student)
	{
		os << "Student_name: " << student.name << " " << "Student_score: " << student.score << " " << endl;
		return os; //ʹ�÷��������ṩ��ʽ��ֵ֧��
	}

};
