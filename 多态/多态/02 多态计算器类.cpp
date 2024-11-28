#include<iostream>
using namespace std;
//��ͨ����ʵ��
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
		//������չ�¹��ܣ���Ҫ�޸�Դ��
		//����ʵ�����У��ᳫ����ԭ�򣺶���չ���п��ţ����޸Ľ��йر�
	}
	int m_Num1;
	int m_Num2;
};

//���ö�̬ʵ�ּ�������
//�ô���1����֯�ṹ����  2���ɶ���ǿ  3������ǰ�ںͺ�����չ��ά���Ը�
//ʵ�ּ�����������
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
//�ӷ���������
class addCalulator:public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 + m_Num2;
	}
};
//������������
class subCalulator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 - m_Num2;
	}
};
//�˷���������
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


	//��̬ʹ������������ָ�������ָ���������
	AbstractCalculator* abs = new addCalulator;
	abs->m_Num1 = 10;
	abs->m_Num2 = 20;
	cout << abs->m_Num1 << " + " << abs->m_Num2 << " = " << abs->getResult() << endl;
	//������ֶ�����
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