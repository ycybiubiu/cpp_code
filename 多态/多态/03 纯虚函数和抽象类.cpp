#include<iostream>
using namespace std;
class Base 
{
public:
	//纯虚函数，只要有一个纯虚函数，该类为抽象类，抽象类无法实例化对象
	//抽象类的子类必须要重写父类的纯虚函数，否则也属于抽象类
	virtual void func() = 0;
};
class Son :public Base
{
public:
	void func() 
	{
		cout << "Son's func()调用" << endl;
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