#include<iostream>
using namespace std;
class Base5 
{
public:
	Base5()
	{
		a = 100;
	}
	void func()
	{
		cout << "Base_func()����" << endl;
	}
	void func(int a)
	{
		cout << "Base_func(int a)����" << endl;
	}
	int a;
};
class Son5 :public Base5 
{
public:
	Son5() 
	{
		a = 200;
	}
	void func()
	{
		cout << "Son_func()����" << endl;
	}
	void func(int a)
	{
		cout << "Son_func(int a)����" << endl;
	}
	int a;
};

void test05() 
{
	Son5 s5;
	cout << "Son's a = " << s5.a << endl;
	//���ͨ�����������ʵ����������ͬ����Ա����Ҫ��������
	cout << "Base's a = " << s5.Base5::a << endl;
}
void test055() 
{
	Son5 s5;
	s5.func();//ֱ�ӵ��� ���õ��������е�ͬ����Ա
	s5.Base5::func();
//��������г��ֺ͸���ͬ���ĳ�Ա�����������ͬ����Ա�����ص�����������ͬ����Ա����
	s5.func(100);
	s5.Base5::func(100);
}

int main5() 
{
	test05();
	test055();
	system("pause");
	return 0;
}