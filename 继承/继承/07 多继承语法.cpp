#include<iostream>
using namespace std;

class Base71
{
public:
	Base71()
	{
		a = 10;
	}
	int a;
};
class Base72
{
public:
	Base72()
	{
		a = 20;
	}
	int a;
};

class Son7:public Base71,public Base72
{
public:
	Son7() 
	{
		c = 100;
		d = 200;
	}
	int c;
	int d;
};
void test07()
{
	Son7 s7;
	cout << "Son's sizeof = " << sizeof(s7) << endl;
	cout << "Base71's a = " << s7.Base71::a << endl;
	cout << "Base72's a = " << s7.Base72::a << endl;
}
int main7() 
{
	test07();
	system("pause");
	return 0;
}