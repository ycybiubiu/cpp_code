#include "boss.h"

//���캯��
Boss::Boss(int id, string name, int dID)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = dID;
}
//��ʾ������Ϣ
void Boss::ShowInfo()
{
	cout << "ְ����ţ�" << this->m_ID
		<< "\t ְ��������" << this->m_Name
		<< "\t ��λ��" << this->getDeptName()
		<< "\t ��λְ��" << "Ѱ����Ŀ���·���Ŀ���������������˾����" << endl;
}
//��ȡ��λ����
string Boss::getDeptName()
{
	return string("�ϰ�");
}