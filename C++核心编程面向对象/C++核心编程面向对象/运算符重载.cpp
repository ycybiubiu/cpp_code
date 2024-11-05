#include <iostream>
using namespace std;
//内置数据类型表达式的运算符不能改变
class numberarr1 
{
public:
	numberarr1() 
	{

	}
	numberarr1(int a, int b)
	{
		m_a = a;
		m_b = b;
	}

	int m_a;
	int m_b;
	//成员函数重载
	numberarr1 operator+(numberarr1 &n)
	{
		numberarr1 n1;
		n1.m_a = this->m_a + n.m_a;
		n1.m_b = this->m_b + n.m_b;
		return n1;
	}
};
//全局函数重载
numberarr1 operator-(numberarr1 &n, numberarr1& n1)
{
	numberarr1 n2;
	n2.m_a = n.m_a - n1.m_a;
	n2.m_b = n.m_b - n1.m_b;
	return n2;
}
class numberarr2
{
	friend ostream& operator <<(ostream& out, numberarr2& n);
public:
	numberarr2(int a, int b)
	{
		m_a = a;
		m_b = b;
	}
private:
	int m_a;
	int m_b;
};
ostream& operator <<(ostream& out, numberarr2& n)
{
	out << "m_a= " << n.m_a << " m_b= " << n.m_b;
	return out;
}
class MyInteger 
{
	friend ostream& operator <<(ostream& cout,MyInteger MyInt);
public:
	MyInteger() {
		m_num = 0;
	}
	MyInteger& operator++() 
	{
		m_num++;
		return *this;
	}
	MyInteger operator++(int) 
	{
		MyInteger temp = *this;
		m_num++;
		return temp;
	}

private:
	int m_num;
};
ostream& operator <<(ostream& cout, MyInteger MyInt)
{
	cout << MyInt.m_num;
	return cout;
}

int main()
{
	numberarr1 n1(10, 20);
	numberarr1 n2(10, 30);
	numberarr1 n3 = n1 + n2;
	//numberarr1 n3 = n1.operator+(n2);//本质调用
	numberarr1 n4 = n1 - n2;
	//numberarr1 n4 = operator-(n1, n2);//本质调用
	cout << n3.m_a << "      " << n3.m_b << endl;
	cout << n4.m_a << "      " << n4.m_b << endl;

	numberarr2 n5(1, 2);
	cout << n5 << endl;

	MyInteger myint;
	cout << ++(++myint) << endl;
	cout << myint++ << endl;
	cout << myint << endl;
	system("pause");
	return 0;
}