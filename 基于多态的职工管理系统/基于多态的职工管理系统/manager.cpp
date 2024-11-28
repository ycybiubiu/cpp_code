#include "manager.h"

//构造函数
Manager::Manager(int id, string name, int dID)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = dID;
}
//显示个人信息
void Manager::ShowInfo()
{
	cout << "职工编号：" << this->m_ID
		<< "\t 职工姓名：" << this->m_Name
		<< "\t 岗位：" << this->getDeptName()
		<< "\t 岗位职责：" << "将老板交予的任务下发给组内员工，并进行任务管理" << endl;
}
//获取岗位名称
string Manager::getDeptName()
{
	return string("经理");
}