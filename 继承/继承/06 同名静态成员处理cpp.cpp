#include<iostream>
using namespace std;

class Base6 
{
public:
	static int a;
	static void func() 
	{
		cout << "Base_static void func()调用" << endl;
	}
	static void func(int a)
	{
		cout << "Base_static void func(int a)调用" << endl;
	}
};
int Base6::a = 100;
class Son6:public Base6
{
public:
	static int a;
	static void func()
	{
		cout << "Son_static void func()调用" << endl;
	}
};
int Son6::a = 200;

void test06() 
{
	//1、通过对象访问
	cout << "通过对象访问静态成员" <<  endl;
	Son6 s6;
	cout << "Son's a = " << s6.a << endl;
	cout << "Base's a = " << s6.Base6::a << endl;
	//2、通过类名访问
	cout << "通过类名访问静态成员" << endl;
	cout << "Son's a = " << Son6::a<< endl;
	//第一个::代表通过类名方式访问，第二个::代表访问父类作用域
	cout << "Base's a = " << Son6::Base6::a << endl;
}
void test066() 
{
	cout << "通过对象访问静态成员函数" << endl;
	Son6 s6;
	//1、通过对象访问
	s6.func();
	s6.Base6::func();
	//2、通过类名访问
	cout << "通过类名访问静态成员函数" << endl;
	Son6::func();
	Son6::Base6::func();
	//如果子类中出现和父类同名的静态成员函数，也会隐藏掉父类中所有同名成员函数，访问需加作用域
	Son6::Base6::func(100);
}
int main6() 
{
	test06();
	test066();
	system("pause");
	return 0;
}