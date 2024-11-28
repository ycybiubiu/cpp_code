#include<iostream>
using namespace std;

class Base1
{
public:
	int a;
protected:
	int b;
private:
	int c;
};
//公共继承
class son1 :public Base1 
{
public:
	void func() 
	{
		a = 10;//父类中的公共权限成员，到子类中依然是公共权限
		b = 20;//父类中的保护权限成员，到子类中是保护权限
		//c = 30;//父类中的私有权限成员到子类中不能访问
	}
};
//保护继承
class son2 :protected Base1
{
public:
	void func()
	{
		a = 10;//父类中的公共权限成员，到子类中是保护权限
		b = 20;//父类中的保护权限成员，到子类中依然是保护权限
		//c = 30;//父类中的私有权限成员到子类中不能访问
	}
};
//私有继承
class son3 :private Base1
{
public:
	void func()
	{
		a = 10;//父类中的公共权限成员，到子类中是私有权限
		b = 20;//父类中的保护权限成员，到子类中是私有权限
		//c = 30;//父类中的私有权限成员到子类中不能访问
	}
};
class grandson3 : public son3
{
public:
	void func()
	{
		//a = 10;//在父类中变为私有权限，子类中不能访问
		//b = 20;//在父类中变为私有权限，子类中不能访问
		//c = 30;//父类中的私有权限成员到子类中不能访问
	}

};
void test02() 
{
	son1 s1;
	s1.a;
	//s1.b;//son1中 b是保护权限，类外访问不到
	son2 s2;
	//s2.a;//son2中 a变为保护权限，类外访问不到
	//s2.b;//son2中 b依然是保护权限，类外访问不到
	son3 s3;
	//s3.a; //a变私有权限，类外访问不到
}
int main2()
{

	system("pause");
	return 0;
}