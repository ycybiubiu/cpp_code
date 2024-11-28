#include "boss.h"

//构造函数
Boss::Boss(int id, string name, int dID)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = dID;
}
//显示个人信息
void Boss::ShowInfo()
{
	cout << "职工编号：" << this->m_ID
		<< "\t 职工姓名：" << this->m_Name
		<< "\t 岗位：" << this->getDeptName()
		<< "\t 岗位职责：" << "寻找项目，下发项目任务给经理，并做公司管理" << endl;
}
//获取岗位名称
string Boss::getDeptName()
{
	return string("老板");
}