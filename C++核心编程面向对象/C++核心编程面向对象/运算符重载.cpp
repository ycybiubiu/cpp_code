#include <iostream>
using namespace std;
//�����������ͱ��ʽ����������ܸı�
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
	//��Ա��������
	numberarr1 operator+(numberarr1 &n)
	{
		numberarr1 n1;
		n1.m_a = this->m_a + n.m_a;
		n1.m_b = this->m_b + n.m_b;
		return n1;
	}
};
//ȫ�ֺ�������
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


class Person2
{
public:
	Person2(int age)
	{
		m_age = new int(age); // ʹ�� new �����ڴ�
	}
	int* m_age;
	~Person2() 
	{
		if (m_age != NULL) 
		{
			delete m_age;
			m_age = NULL;
		}
	}
	//���ظ�ֵ�����
	Person2& operator=(Person2 &p){
		//�������ṩ��ǳ����
		//m_age = p.m_age;
		//Ӧ�����ж��Ƿ��������ڶ�������������ͷŸɾ���Ȼ�������
		if (m_age != NULL)
		{
			delete m_age;
			m_age = NULL;
		}
		//���
		m_age = new int(*p.m_age);
		return *this;
	}
};

class Person03 
{
public:
	Person03(string name, int age) 
	{
		m_name = name;
		m_age = age;
	}
	bool operator==(Person03& p)
	{
		if (this->m_name == p.m_name && this->m_age == p.m_age) 
		{
			return true;
		}
		return false;
	}
	bool operator!=(Person03& p)
	{
		if (this->m_name != p.m_name || this->m_age != p.m_age)
		{
			return false;
		}
		return true;
	}
	string m_name;
	int m_age;
};
//�����������أ�α����
class myadd 
{
public:
	int operator()(int n1, int n2)
	{
		return n1 + n2;
	}
};
int main()
{
	numberarr1 n1(10, 20);
	numberarr1 n2(10, 30);
	numberarr1 n3 = n1 + n2;
	//numberarr1 n3 = n1.operator+(n2);//���ʵ���
	numberarr1 n4 = n1 - n2;
	//numberarr1 n4 = operator-(n1, n2);//���ʵ���
	cout << n3.m_a << "      " << n3.m_b << endl;
	cout << n4.m_a << "      " << n4.m_b << endl;

	numberarr2 n5(1, 2);
	cout << n5 << endl;

	MyInteger myint;
	cout << ++(++myint) << endl;
	cout << myint++ << endl;
	cout << myint << endl;

	Person2 p1(18);
	Person2 p2(20);
	Person2 p3(30);
	p3 = p2 = p1;
	cout << *p1.m_age << *p2.m_age<< *p3.m_age<< endl;
	Person03 wukong("���", 5000);
	Person03 bajie("�˽�", 50000);
	if (wukong == bajie) {
		cout << "wukong == bajie" << endl;
	}
	else {
		cout << "wukong != bajie" << endl;
	}
	cout << myadd()(10, 20) << endl;//���봴�����������ʹ�������������
	system("pause");
	return 0;
}