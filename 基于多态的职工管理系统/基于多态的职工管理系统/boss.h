//�����ļ�
#pragma once
#include<iostream>
#include<string>
#include "worker.h"
using namespace std;

class Boss :public Worker
{
public:
	//���캯��
	Boss(int id, string name, int dID);
	//��ʾ������Ϣ
	virtual void ShowInfo();
	//��ȡ��λ����
	virtual string getDeptName();
};
