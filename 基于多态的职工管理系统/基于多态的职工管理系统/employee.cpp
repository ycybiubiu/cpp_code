#include "employee.h"

//构造函数
Employee::Employee(int id, string name, int dID)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = dID;
}
//显示个人信息
void Employee::ShowInfo()
{
	cout << "职工编号：" << this->m_ID
		<< "\t 职工姓名：" << this->m_Name
		<< "\t 岗位：" << this->getDeptName()
		<< "\t 岗位职责：" << "完成经理交予的任务" << endl;
}
//获取岗位名称
string Employee::getDeptName()
{
	return string("普通员工");
}