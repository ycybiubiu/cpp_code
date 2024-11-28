#pragma once//��ֹͷ�ļ��ظ�����
#include<iostream>//�������������ͷ�ļ�
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include<fstream>
#define FILENAME "EmpFile.txt"
using namespace std;

class WorkerManager
{
public:
	//���캯��
	WorkerManager();

	//չʾ�˵�
	void ShowMenu();

	//�˳�ϵͳ
	void ExitSystem();
	
	//��¼ְ������
	int m_EmpNum;

	//ְ������ָ��
	Worker** m_EmpArray;

	//���ְ��
	void Add_Emp();
	
	//�����ļ�
	void SaveEmpFile();

	//�ж��ļ��Ƿ�Ϊ�յı�־
	bool m_FileIsEmpty;

	//ͳ��ְ������
	int GetEmpNum();

	//��ʼ��ְ��
	void InitEmp();

	//��ʾְ����Ϣ
	void ShowEmp();

	//ɾ��ְ��
	void DelEmp();
	
	//�ж�ְ���Ƿ����
	int IsEmpExist(int id);
	
	//�޸�ְ��
	void ModifyEmp();

	//����ְ��
	void FindEmp();

	//����ְ��
	void SortEmp();

	//����ļ�
	void CleanFile();

	//��������
	~WorkerManager();
};
