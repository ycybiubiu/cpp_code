#include<iostream>
using namespace std;



//两个整型交换函数
void SwapInt(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
//交换两个浮点型函数
void SwapDouble(double& a, double& b)
{
	double tmp = a;
	a = b;
	b = tmp;
}
//函数模板
template<typename T>//声明一个模板，告诉编译器后面代码中的T不要报错，T是一个通用数据类型
void MySwap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

void test01()
{
	int a = 10;
	int b = 20;
	SwapInt(a, b);
	cout << "a=" << a << " b=" << b << endl;
	double c = 1.5;
	double d = 2.5;
	SwapDouble(c, d);
	cout << "c=" << c << " d=" << d << endl;
	//两种方式使用函数模板
	//1、自动类型推导
	MySwap(a, b);
	cout << "a=" << a << " b=" << b << endl;
	//2、显示指定类型
	MySwap<double>(c, d);
	cout << "c=" << c << " d=" << d << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}