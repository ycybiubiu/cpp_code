#include<iostream>
using namespace std;
class Base 
{
public:
	//���麯����ֻҪ��һ�����麯��������Ϊ�����࣬�������޷�ʵ��������
	//��������������Ҫ��д����Ĵ��麯��������Ҳ���ڳ�����
	virtual void func() = 0;
};
class Son :public Base
{
public:
	void func() 
	{
		cout << "Son's func()����" << endl;
	}
};
void test03()
{
	Son s;
	s.func();
	Base * b = new Son;
	b->func();
}
int main3()
{

	test03();
	system("pause");
	return 0;
}