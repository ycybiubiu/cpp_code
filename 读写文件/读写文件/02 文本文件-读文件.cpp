#include<iostream>
using namespace std;
#include<fstream>
#include<string>
void test02()
{
	//1������ͷ�ļ�fstream
	//2������������
	ifstream ifs;
	//3��ָ���򿪷�ʽ
	ifs.open("test.txt", ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	//4��������
	//��һ��
	char buf[1024] = { 0 };
	while (ifs >> buf)
	{
		cout << buf << endl;
	}
	ifs.clear();             // �����״̬������ EOF ״̬��
	ifs.seekg(0, ios::beg);  // ���ļ�ָ�����¶�λ���ļ���ͷ
	//�ڶ���
	while (ifs.getline(buf,sizeof(buf)))
	{
		cout << buf << endl;
	}
	ifs.clear();             // �����״̬������ EOF ״̬��
	ifs.seekg(0, ios::beg);  // ���ļ�ָ�����¶�λ���ļ���ͷ
	//������
	string str;
	while (getline(ifs, str))
	{
		cout << str << endl;
	}
	ifs.clear();             // �����״̬������ EOF ״̬��
	ifs.seekg(0, ios::beg);  // ���ļ�ָ�����¶�λ���ļ���ͷ
	//������
	char c;
	while ((c = ifs.get()) != EOF)
	{
		cout << c;
	}
	//5���ر��ļ�
	ifs.close();
}

int main2()
{
	test02();

	system("pause");
	return 0;
}