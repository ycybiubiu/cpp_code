#include <iostream>
using namespace std;
int g_a = 10;
int g_b = 10;
const int c_g_a = 10;
const int c_g_b = 10;
const string c_g_c = "hello world";

int* func(int b)//�β�����Ҳ�����ջ��
{
	b = 100;
	int a = 10;//�ֲ������������ջ����ջ���������ں���ִ������Զ��ͷ�
	return &a;//���ؾֲ������ĵ�ַ
}
int* func1()//�β�����Ҳ�����ջ��
{
	//����new�ؼ��֣����Խ����ݿ��ٵ�����
	//ָ�뱾���Ǿֲ�����������ջ����ָ�뱣����һ�������ĵ�ַָ�����������
	int *p=new int(10);//new���ص��Ǹ��������͵�ָ��
	return p;
}
int main1() {
	//ȫ����
	//ȫ�ֱ�������̬����������

	//������ͨ�ֲ�����
	int a = 10;
	int b = 10;
	cout << "�ֲ�����a�ĵ�ַΪ��" <<  & a << endl;
	cout << "�ֲ�����b�ĵ�ַΪ��" <<  & b << endl;

	cout << "ȫ�ֱ���g_a�ĵ�ַΪ��" << &g_a << endl;
	cout << "ȫ�ֱ���g_b�ĵ�ַΪ��" << &g_b << endl;

	//��̬����������ͨ����ǰ���static,���ھ�̬����
	static int s_a = 10;
	static int s_b = 10;
	cout << "��̬����s_a�ĵ�ַΪ��" << &s_a << endl;
	cout << "��̬����s_b�ĵ�ַΪ��" << &s_b << endl;
	//����
	//�ַ�������
	const string c_l_c = "hello world";
	cout << "�ַ��������ĵ�ַΪ��" << &"hello world" << endl;
	cout << "�ֲ��ַ�������c_l_c�ĵ�ַΪ��" << &c_l_c << endl;
	cout << "ȫ���ַ�������c_g_c�ĵ�ַΪ��" << &c_g_c << endl;
	//const���ε�ȫ�ֱ�����const���εľֲ�����
	cout << "ȫ�ֳ���c_g_a�ĵ�ַΪ��" << &c_g_a << endl;
	cout << "ȫ�ֳ���c_g_b�ĵ�ַΪ��" << &c_g_b << endl;

	const int c_l_a = 10;
	const int c_l_b = 10;
	cout << "�ֲ�����c_l_a�ĵ�ַΪ��" << &c_l_a << endl;
	cout << "�ֲ�����c_l_b�ĵ�ַΪ��" << &c_l_b << endl;


	//ջ������ע������ ----��Ҫ���ؾֲ������ĵ�ַ
	//ջ���������ɱ����������ٺ��ͷ�
	int* p = func(0);
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	//��γɹ�����żȻ��������ռ�ڴ�û��ʹ��

	//���� �ɳ���Ա�����ͷţ�������Ա���ͷţ�����������ɲ���ϵͳ����
	int* p1 = func1();
	cout << *p1 << endl;
	cout << *p1 << endl;
	cout << *p1 << endl;
	delete p1;
	//cout << *p1 << endl;//�ڴ��ѱ��ͷţ��ٴη����ǷǷ�����
	//cout << *p1 << endl;
	//cout << *p1 << endl;
	string c = "aaaa";
	string* p2 = &c;
	system("pause");
	return 0;
}