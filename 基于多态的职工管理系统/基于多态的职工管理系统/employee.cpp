#include "employee.h"

//���캯��
Employee::Employee(int id, string name, int dID)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = dID;
}
//��ʾ������Ϣ
void Employee::ShowInfo()
{
	cout << "ְ����ţ�" << this->m_ID
		<< "\t ְ��������" << this->m_Name
		<< "\t ��λ��" << this->getDeptName()
		<< "\t ��λְ��" << "��ɾ����������" << endl;
}
//��ȡ��λ����
string Employee::getDeptName()
{
	return string("��ͨԱ��");
}