#include "manager.h"

//���캯��
Manager::Manager(int id, string name, int dID)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = dID;
}
//��ʾ������Ϣ
void Manager::ShowInfo()
{
	cout << "ְ����ţ�" << this->m_ID
		<< "\t ְ��������" << this->m_Name
		<< "\t ��λ��" << this->getDeptName()
		<< "\t ��λְ��" << "���ϰ彻��������·�������Ա�����������������" << endl;
}
//��ȡ��λ����
string Manager::getDeptName()
{
	return string("����");
}