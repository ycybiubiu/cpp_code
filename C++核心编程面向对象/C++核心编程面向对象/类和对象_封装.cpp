#include <iostream>
#include <string>
using namespace std;
class Student {
public://����Ȩ��
	//����Ȩ�� public    ���ڿ� �����
	//����Ȩ�� protected ���ڿ� �����  ����ɷø��ౣ������
	//˽��Ȩ�� private   ���ڿ� �����  ���಻�ɷø���˽������
	string name;
	string stu_number;

	void showinfo()
	{
		cout << "������" << name << endl;
		cout << "ѧ�ţ�" << stu_number << endl;
	}
};

class Cube {
public:
	//���ó�
	void set_long(int l)
	{
		m_long = l;
	}
	//��ȡ��
	int get_long()
	{
		return m_long;
	}
	//���ÿ�
	void set_wight(int w)
	{
		m_wight = w;
	}
	//��ȡ��
	int get_wight()
	{
		return m_wight;
	}
	//���ø�
	void set_height(int h)
	{
		m_height = h;
	}
	//��ȡ��
	int get_height()
	{
		return m_height;
	}
	//��������
	int calc_S()
	{
		return 2 * m_long * m_wight + 2 * m_long * m_height + 2 * m_wight * m_height;
	}
	//�������
	int calc_V()
	{
		return m_long * m_wight * m_height;
	}
private:
	int m_long;
	int m_wight;
	int m_height;
};
//	���캯������
//  1�����ղ�����Ϊ�޲κ��в�
//  2���������ͷ�Ϊ��ͨ�Ϳ���
class Person0 {
public:
	//�޲�
	Person0() {
		cout << "�����޲ι���" << endl;
	}
	//�в�
	Person0(int a, int height) {
		age = a;
		m_height = new int(height);
		cout << "�����вι���" << endl;
	}
	//����
	Person0(const Person0 &p) {
		age = p.age;
		//m_height = p.m_height;//Ĭ�Ͽ��������ǳ����
		m_height = new int(*p.m_height);//��������¶���
		cout << "���ÿ�������" << endl;
	}
	//��������
	~Person0() {
		if (m_height != NULL)
		{
			delete m_height;
			m_height = NULL;
		}
		cout << "������������" << endl;
	}
	int age;
	int* m_height;
};
//���ù��캯��
void test01() {
	//��ʾ��
	Person0 p1;
	Person0 p2(10,160);
	Person0 p3(p2);
	//���ŷ�
	Person0 p4 = Person0(100, 160);
	Person0 p5 = Person0(p4);//ǳ���������������Ƕ��������ظ��ͷ�
	//��ʽ��
	//Person p6 = 1000,160;
	//Person p7 = p6;
	//ע�ⲻ��ʹ�ÿ������캯����ʼ���������󣬱�������Ϊ�Ƕ�������
}
int main4()
{

	Student lisi;
	lisi.name = "����";
	lisi.stu_number = "2024015423";
	lisi.showinfo();

	Cube c1;
	c1.set_height(10);
	c1.set_long(10);
	c1.set_wight(10);
	cout << "�����" << c1.calc_V() << endl;
	cout << "�����" << c1.calc_S() << endl; 
	test01();
	system("pause");
	return 0;

}