#include<iostream>
using namespace std;

class Base6 
{
public:
	static int a;
	static void func() 
	{
		cout << "Base_static void func()����" << endl;
	}
	static void func(int a)
	{
		cout << "Base_static void func(int a)����" << endl;
	}
};
int Base6::a = 100;
class Son6:public Base6
{
public:
	static int a;
	static void func()
	{
		cout << "Son_static void func()����" << endl;
	}
};
int Son6::a = 200;

void test06() 
{
	//1��ͨ���������
	cout << "ͨ��������ʾ�̬��Ա" <<  endl;
	Son6 s6;
	cout << "Son's a = " << s6.a << endl;
	cout << "Base's a = " << s6.Base6::a << endl;
	//2��ͨ����������
	cout << "ͨ���������ʾ�̬��Ա" << endl;
	cout << "Son's a = " << Son6::a<< endl;
	//��һ��::����ͨ��������ʽ���ʣ��ڶ���::������ʸ���������
	cout << "Base's a = " << Son6::Base6::a << endl;
}
void test066() 
{
	cout << "ͨ��������ʾ�̬��Ա����" << endl;
	Son6 s6;
	//1��ͨ���������
	s6.func();
	s6.Base6::func();
	//2��ͨ����������
	cout << "ͨ���������ʾ�̬��Ա����" << endl;
	Son6::func();
	Son6::Base6::func();
	//��������г��ֺ͸���ͬ���ľ�̬��Ա������Ҳ�����ص�����������ͬ����Ա�������������������
	Son6::Base6::func(100);
}
int main6() 
{
	test06();
	test066();
	system("pause");
	return 0;
}