#include<iostream>
using namespace std;
#include<string>
#include<fstream>

class Personr
{
public:
	char m_Name[64];
	int m_Age;
};
void test04()
{
	//1������ͷ�ļ�
	//2������������
	ifstream ifs;

	//3�����ļ�
	ifs.open("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	//4�����ļ�
	Personr pr;
	ifs.read((char*)&pr, sizeof(Personr));
	cout << "������" << pr.m_Name << endl<< "���䣺" << pr.m_Age << endl;
	//5���ر��ļ�
	ifs.close();
}

int main()
{

	test04();

	system("pause");
	return 0;
}