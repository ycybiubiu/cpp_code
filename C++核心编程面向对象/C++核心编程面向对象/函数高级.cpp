#include <iostream>
using namespace std;
//����Ĭ�ϲ���
int func(int a, int b, int c=30)
{
	return a + b + c;
}
//ע������
//1�����ĳ��λ���Ѿ�����Ĭ�ϲ�������ô�����λ�����󣬶�������Ĭ��ֵ
//2���������������Ĭ�ϲ���������ʵ�־Ͳ�����Ĭ�ϲ���,������ʵ��ֻ��һ����Ĭ�ϲ���
int func2(int a, int b);
int func2(int a=10, int b=10)
{
	return a + b;
}
//ռλ��������ռλ������ʱ�������λ��,ռλ����Ҳ������Ĭ��ֵ
int func3(int a = 10, int = 10)
{
	cout << "aaaa=" << a << endl;
	return a;
}

//�������أ��ú�������ͬ����߸�����
//1��ͬһ����������
//2������������ͬ
//3�������������Ͳ�ͬ||������ͬ||˳��ͬ
//4�������ķ���ֵ��������Ϊ���ص�����
void func()
{
	cout << "func�ĵ���" << endl;
}
void func(int a)
{
	cout << "func�ĵ���!" << endl;
}
//������Ϊ���ص�����
void func4(int& a)
{
	cout << "func4(int& a)����" << endl;
}
void func4(const int& a)
{
	cout << "func4(const int& a)����" << endl;
}
//������������Ĭ�ϲ������ܳ��ֶ�����
void func5(int a, int b=10)
{
}
void func5(int a)
{
}
int main3()
{
	//�Լ�������������ȼ�����Ĭ��ֵ
	cout << func(10,40,50) << endl;

	cout << func2() << endl;
	func3();
	func(10);
	int a = 10;
	func4(a);
	func4(10);
	system("pause");
	return 0;
}