#include <iostream>
using namespace std;
//函数默认参数
int func(int a, int b, int c=30)
{
	return a + b + c;
}
//注意事项
//1、如果某个位置已经有了默认参数，那么从这个位置往后，都必须有默认值
//2、如果函数声明有默认参数，函数实现就不能有默认参数,声明和实现只能一个有默认参数
int func2(int a, int b);
int func2(int a=10, int b=10)
{
	return a + b;
}
//占位参数用来占位，调用时必须填补该位置,占位参数也可以有默认值
int func3(int a = 10, int = 10)
{
	cout << "aaaa=" << a << endl;
	return a;
}

//函数重载，让函数名相同，提高复用性
//1、同一个作用域下
//2、函数名称相同
//3、函数参数类型不同||个数不同||顺序不同
//4、函数的返回值不可以作为重载的条件
void func()
{
	cout << "func的调用" << endl;
}
void func(int a)
{
	cout << "func的调用!" << endl;
}
//引用作为重载的条件
void func4(int& a)
{
	cout << "func4(int& a)调用" << endl;
}
void func4(const int& a)
{
	cout << "func4(const int& a)调用" << endl;
}
//函数重载碰到默认参数可能出现二义性
void func5(int a, int b=10)
{
}
void func5(int a)
{
}
int main3()
{
	//自己传入参数的优先级高于默认值
	cout << func(10,40,50) << endl;

	cout << func2() << endl;
	func3();
	func(10);
	int a = 10;
	func4(a);
	func4(10);
	system("pause");
	return 0;
}