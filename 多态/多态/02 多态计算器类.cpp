#include<iostream>
using namespace std;
//普通对象实现
class Calculator
{
public:

	int getResult(string oper)
	{
		if(oper == "+")
		{
			return  m_Num1 + m_Num2;
		}
		else if(oper == "-")
		{
			return  m_Num1 - m_Num2;
		}
		else if (oper == "*")
		{
			return  m_Num1 * m_Num2;
		}
		else if (oper == "/")
		{
			return  m_Num1 / m_Num2;
		}
		//如需扩展新功能，需要修改源码
		//在真实开发中，提倡开闭原则：对扩展进行开放，对修改进行关闭
	}
	int m_Num1;
	int m_Num2;
};

//利用多态实现计算器类
//好处：1、组织结构清晰  2、可读性强  3、对于前期和后期扩展和维护性高
//实现计算器抽象类
class AbstractCalculator
{
public:
	virtual int getResult()
	{
		return 0;
	}
	int m_Num1;
	int m_Num2;
};
//加法计算器类
class addCalulator:public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 + m_Num2;
	}
};
//减法计算器类
class subCalulator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 - m_Num2;
	}
};
//乘法计算器类
class mulCalulator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 * m_Num2;
	}
};
void test02()
{
	Calculator c;
	c.m_Num1 = 10;
	c.m_Num2 = 20;
	cout << c.m_Num1 << " + " << c.m_Num2 << " = " << c.getResult("+") << endl;
	cout << c.m_Num1 << " - " << c.m_Num2 << " = " << c.getResult("-") << endl;
	cout << c.m_Num1 << " * " << c.m_Num2 << " = " << c.getResult("*") << endl;
	cout << c.m_Num1 << " / " << c.m_Num2 << " = " << c.getResult("/") << endl;


	//多态使用条件：父类指针或引用指向子类对象
	AbstractCalculator* abs = new addCalulator;
	abs->m_Num1 = 10;
	abs->m_Num2 = 20;
	cout << abs->m_Num1 << " + " << abs->m_Num2 << " = " << abs->getResult() << endl;
	//用完后手动销毁
	delete abs;
	abs = new subCalulator;
	abs->m_Num1 = 10;
	abs->m_Num2 = 20;
	cout << abs->m_Num1 << " - " << abs->m_Num2 << " = " << abs->getResult() << endl;
	delete abs;
	abs = new mulCalulator;
	abs->m_Num1 = 10;
	abs->m_Num2 = 20;
	cout << abs->m_Num1 << " * " << abs->m_Num2 << " = " << abs->getResult() << endl;
	delete abs;
}

int main2()
{
	test02();
	system("pause");
	return 0;
}