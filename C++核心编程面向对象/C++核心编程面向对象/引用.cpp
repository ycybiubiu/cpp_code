#include <iostream>
using namespace std;
//引用的本质是指针常量 
//值传递
//1、值传递
void swap01(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}
//2、地址传递
void swap02(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
//3、引用传递
void swap03(int &a,int&b)
{  
	int temp = a;
	a = b;
	b = temp;
}

//引用做函数的返回值
//1、不要返回局部变量的引用
int& test01()
{
	int a = 10;//局部变量，存放在栈区，函数结束后释放
	return a;
}
//2、函数的调用可以作为左值
int& test02()
{
	static int a = 10;//静态变量，存放在全局区，程序结束后释放
	return a;
}
int main2()
{
	int a = 10;
	int& b = a;//引用必须要初始化，一旦初始化就不可以更改
	int c = 20;
	//int& b = c;非法操作
	b = c;//赋值不是更改引用
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;

	/*   _______         _______
	    |       |       |       |
	    |   a   | ----> |   10  | 
		|_______|    /  |_______|
		 _______   /  引用初始化 
		|       |/
		|   b   |
		|_______|\	不能再引用其他变量	
		 _______   X     _______ 
		|       |    \	|       |
		|   c   | ---->	|   20  |
		|_______|		|_______|

	*/ 
	//
	int d = 10;
	int e = 20;
	cout << "d=" << d << endl;
	cout << "e=" << e << endl;
	swap01(d, e);//值传递。形参不会修饰实参
	cout << "值传递后d=" << d << endl;
	cout << "值传递后e=" << e << endl;
	swap02(&d, &e);//地址传递，形参会修饰实参
	cout << "地址传递后d=" << d << endl;
	cout << "地址传递后e=" << e << endl;
	swap03(d, e);//引用传递，形参会修饰实参，d、e实际上是引用名，原数据的别名
	cout << "引用传递后d=" << d << endl;
	cout << "引用传递后e=" << e << endl;
	
	int& ref01 = test01();
	cout << "ref01=" << ref01 << endl;
	cout << "ref01=" << ref01 << endl;

	int& ref02 = test02();
	cout << "ref02=" << ref02 << endl;
	test02() = 1000;
	cout << "ref02=" << ref02 << endl;
	

	system("pause");
	return 0;
}