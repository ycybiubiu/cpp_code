#include <iostream>
using namespace std;
//���õı�����ָ�볣�� 
//ֵ����
//1��ֵ����
void swap01(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}
//2����ַ����
void swap02(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
//3�����ô���
void swap03(int &a,int&b)
{  
	int temp = a;
	a = b;
	b = temp;
}

//�����������ķ���ֵ
//1����Ҫ���ؾֲ�����������
int& test01()
{
	int a = 10;//�ֲ������������ջ���������������ͷ�
	return a;
}
//2�������ĵ��ÿ�����Ϊ��ֵ
int& test02()
{
	static int a = 10;//��̬�����������ȫ����������������ͷ�
	return a;
}
int main2()
{
	int a = 10;
	int& b = a;//���ñ���Ҫ��ʼ����һ����ʼ���Ͳ����Ը���
	int c = 20;
	//int& b = c;�Ƿ�����
	b = c;//��ֵ���Ǹ�������
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;

	/*   _______         _______
	    |       |       |       |
	    |   a   | ----> |   10  | 
		|_______|    /  |_______|
		 _______   /  ���ó�ʼ�� 
		|       |/
		|   b   |
		|_______|\	������������������	
		 _______   X     _______ 
		|       |    \	|       |
		|   c   | ---->	|   20  |
		|_______|		|_______|

	*/ 
	//
	int d = 10;
	int e = 20;
	cout << "d=" << d << endl;
	cout << "e=" << e << endl;
	swap01(d, e);//ֵ���ݡ��ββ�������ʵ��
	cout << "ֵ���ݺ�d=" << d << endl;
	cout << "ֵ���ݺ�e=" << e << endl;
	swap02(&d, &e);//��ַ���ݣ��βλ�����ʵ��
	cout << "��ַ���ݺ�d=" << d << endl;
	cout << "��ַ���ݺ�e=" << e << endl;
	swap03(d, e);//���ô��ݣ��βλ�����ʵ�Σ�d��eʵ��������������ԭ���ݵı���
	cout << "���ô��ݺ�d=" << d << endl;
	cout << "���ô��ݺ�e=" << e << endl;
	
	int& ref01 = test01();
	cout << "ref01=" << ref01 << endl;
	cout << "ref01=" << ref01 << endl;

	int& ref02 = test02();
	cout << "ref02=" << ref02 << endl;
	test02() = 1000;
	cout << "ref02=" << ref02 << endl;
	

	system("pause");
	return 0;
}