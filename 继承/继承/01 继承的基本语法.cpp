#include<iostream>
using namespace std;

//javaҳ��
//class Java 
//{
//public:
//	void header()
//	{
//		cout << "��ҳ�������Ρ���¼��ע��...������ͷ����" << endl;
//	}
//	void footer()
//	{
//		cout << "�������ġ�����������վ�ڵ�ͼ...�������ײ���" << endl;
//	}
//	void left()
//	{
//		cout << "Java��Python��C++��...�����������б�" << endl;
//	}
//	void content()
//	{
//		cout << "Javaѧ����Ƶ" << endl;
//	}
//};
//class Python
//{
//public:
//	void header()
//	{
//		cout << "��ҳ�������Ρ���¼��ע��...������ͷ����" << endl;
//	}
//	void footer()
//	{
//		cout << "�������ġ�����������վ�ڵ�ͼ...�������ײ���" << endl;
//	}
//	void left()
//	{
//		cout << "Java��Python��C++��...�����������б�" << endl;
//	}
//	void content()
//	{
//		cout << "Pythonѧ����Ƶ" << endl;
//	}
//};

//�̳�ʵ��ҳ��
//�﷨ class ���ࣨ�����ࣩ ���̳з�ʽ ���ࣨ���ࣩ
class BasePage
{
public:
	void header()
	{
		cout << "��ҳ�������Ρ���¼��ע��...������ͷ����" << endl;
	}
	void footer()
	{
		cout << "�������ġ�����������վ�ڵ�ͼ...�������ײ���" << endl;
	}
	void left()
	{
		cout << "Java��Python��C++��...�����������б�" << endl;
	}
};
//Javaҳ��
class Java :public BasePage
{
public:
	void content()
	{
		cout << "Javaѧ����Ƶ" << endl;
	}
};
class Python :public BasePage
{
public:
	void content()
	{
		cout << "Pythonѧ����Ƶ" << endl;
	}
};
void test01()
{
	cout << "Java������Ƶ�Ľ�������" << endl;
	Java java_page;
	java_page.header();
	java_page.footer();
	java_page.left();
	java_page.content();
	cout << "-------------------------------------" << endl;
	cout << "Python������Ƶ�Ľ�������" << endl;
	Python py_page;
	py_page.content();
	py_page.footer();
	py_page.left();
	py_page.content();
}

int main1()
{
	test01();
	system("pause");
	return 0;
}