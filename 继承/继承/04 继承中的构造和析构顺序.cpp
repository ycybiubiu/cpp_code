#include<iostream>
using namespace std;
class Base3
{
public:
	Base3() 
	{
		cout << "Base3构造函数" << endl;
	}
	~Base3() 
	{
		cout << "Base3析构函数" << endl;
	}
};
class Son3:public Base3
{
public:
	Son3()
	{
		cout << "Son3构造函数" << endl;
	}
	~Son3()
	{
		cout << "Son3析构函数" << endl;
	}
};
void test04() 
{
	//Base3 b3;
	Son3 s3;
}
int main4()
{
	//继承中的构造和析构顺序为先构造父类，先析构子类
	test04();
	system("pause");
	return 0;
}