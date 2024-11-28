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
		cout << "Base_func()调用" << endl;
	}
	void func(int a)
	{
		cout << "Base_func(int a)调用" << endl;
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
		cout << "Son_func()调用" << endl;
	}
	void func(int a)
	{
		cout << "Son_func(int a)调用" << endl;
	}
	int a;
};

void test05() 
{
	Son5 s5;
	cout << "Son's a = " << s5.a << endl;
	//如果通过子类对象访问到父类对象中同名成员，需要加作用域
	cout << "Base's a = " << s5.Base5::a << endl;
}
void test055() 
{
	Son5 s5;
	s5.func();//直接调用 调用的是子类中的同名成员
	s5.Base5::func();
//如果子类中出现和父类同名的成员函数，子类的同名成员会隐藏掉父类中所有同名成员函数
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