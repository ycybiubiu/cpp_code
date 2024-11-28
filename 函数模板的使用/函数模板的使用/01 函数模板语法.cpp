#include<iostream>
using namespace std;



//�������ͽ�������
void SwapInt(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
//�������������ͺ���
void SwapDouble(double& a, double& b)
{
	double tmp = a;
	a = b;
	b = tmp;
}
//����ģ��
template<typename T>//����һ��ģ�壬���߱�������������е�T��Ҫ����T��һ��ͨ����������
void MySwap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

void test01()
{
	int a = 10;
	int b = 20;
	SwapInt(a, b);
	cout << "a=" << a << " b=" << b << endl;
	double c = 1.5;
	double d = 2.5;
	SwapDouble(c, d);
	cout << "c=" << c << " d=" << d << endl;
	//���ַ�ʽʹ�ú���ģ��
	//1���Զ������Ƶ�
	MySwap(a, b);
	cout << "a=" << a << " b=" << b << endl;
	//2����ʾָ������
	MySwap<double>(c, d);
	cout << "c=" << c << " d=" << d << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}