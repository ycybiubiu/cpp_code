#pragma once//防止头文件重复包含
#include<iostream>//包含输入输出流头文件
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
	//构造函数
	WorkerManager();

	//展示菜单
	void ShowMenu();

	//退出系统
	void ExitSystem();
	
	//记录职工人数
	int m_EmpNum;

	//职工数组指针
	Worker** m_EmpArray;

	//添加职工
	void Add_Emp();
	
	//保存文件
	void SaveEmpFile();

	//判断文件是否为空的标志
	bool m_FileIsEmpty;

	//统计职工数量
	int GetEmpNum();

	//初始化职工
	void InitEmp();

	//显示职工信息
	void ShowEmp();

	//删除职工
	void DelEmp();
	
	//判断职工是否存在
	int IsEmpExist(int id);
	
	//修改职工
	void ModifyEmp();

	//查找职工
	void FindEmp();

	//排序职工
	void SortEmp();

	//清空文件
	void CleanFile();

	//析构函数
	~WorkerManager();
};
