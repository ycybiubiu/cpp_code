#include <iostream>
using namespace std;
int g_a = 10;
int g_b = 10;
const int c_g_a = 10;
const int c_g_b = 10;
const string c_g_c = "hello world";

int* func(int b)//形参数据也会放在栈区
{
	b = 100;
	int a = 10;//局部变量，存放在栈区，栈区的数据在函数执行完后自动释放
	return &a;//返回局部变量的地址
}
int* func1()//形参数据也会放在栈区
{
	//利用new关键字，可以将数据开辟到堆区
	//指针本质是局部变量，放在栈区，指针保存了一个堆区的地址指向堆区的数据
	int *p=new int(10);//new返回的是该数据类型的指针
	return p;
}
int main1() {
	//全局区
	//全局变量、静态变量、常量

	//创建普通局部变量
	int a = 10;
	int b = 10;
	cout << "局部变量a的地址为：" <<  & a << endl;
	cout << "局部变量b的地址为：" <<  & b << endl;

	cout << "全局变量g_a的地址为：" << &g_a << endl;
	cout << "全局变量g_b的地址为：" << &g_b << endl;

	//静态变量，在普通变量前面加static,属于静态变量
	static int s_a = 10;
	static int s_b = 10;
	cout << "静态变量s_a的地址为：" << &s_a << endl;
	cout << "静态变量s_b的地址为：" << &s_b << endl;
	//常量
	//字符串常量
	const string c_l_c = "hello world";
	cout << "字符串常量的地址为：" << &"hello world" << endl;
	cout << "局部字符串常量c_l_c的地址为：" << &c_l_c << endl;
	cout << "全局字符串常量c_g_c的地址为：" << &c_g_c << endl;
	//const修饰的全局变量，const修饰的局部变量
	cout << "全局常量c_g_a的地址为：" << &c_g_a << endl;
	cout << "全局常量c_g_b的地址为：" << &c_g_b << endl;

	const int c_l_a = 10;
	const int c_l_b = 10;
	cout << "局部常量c_l_a的地址为：" << &c_l_a << endl;
	cout << "局部常量c_l_b的地址为：" << &c_l_b << endl;


	//栈区数据注意事项 ----不要返回局部变量的地址
	//栈区的数据由编译器管理开辟和释放
	int* p = func(0);
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	//多次成功仅是偶然，变量所占内存没被使用

	//堆区 由程序员分配释放，若程序员不释放，程序结束后由操作系统回收
	int* p1 = func1();
	cout << *p1 << endl;
	cout << *p1 << endl;
	cout << *p1 << endl;
	delete p1;
	//cout << *p1 << endl;//内存已被释放，再次访问是非法操作
	//cout << *p1 << endl;
	//cout << *p1 << endl;
	string c = "aaaa";
	string* p2 = &c;
	system("pause");
	return 0;
}