#include <iostream>
#include <string>
using namespace std;
class Person
{
public:
	Person(int age)
	{
		//thisָ��ָ����Ǳ����õĳ�Ա���������Ķ���
		this->age = age;
	}

	Person& PersonAddage(Person& p)
	{
		/*if (this == NULL)
		{
			return;
		}*/
		this->age += p.age;
		return *this;
	}
	int age;
};
//1��������Ƴ�ͻ
void test()
{
	Person p1(18);
	cout << p1.age << endl;
}
//2�����ض�������*this
void testt() 
{
	Person p1(12);
	Person p2(10);
	//��ʽ���˼��
	p2.PersonAddage(p1).PersonAddage(p1);
	cout << p2.age << endl;
}
//const���γ�Ա����
//��Ա�������const��Ϊ���������������������޸ĳ�Ա���ԣ���Ա���Լӹؼ���mutable �ڳ��������޸�
//��������ǰ��const��Ϊ�����󣬳�����ֻ�ܵ��ó�����

class Person1 {
public:
	//�ڳ�Ա���������const,���ε���thisָ����ָ��ָ���ֵҲ�������޸�
	void showPerson() const 
	{
		this->m_B=100;
		//this->m_A=100;
	}
	void aaa() {
	
	}
	int m_A;
	mutable int m_B;
};


//��Ԫ
class Home;
class goodgg
{
public:
	goodgg();
	void visit();
	void visit2();
	Home* home;
};
class Home
{
	friend void goodguy(Home* home);//ȫ�ֺ�����Home�ĺ����ѿ��Է���˽�г�Ա
	//friend class goodgg;//������Ԫ
	friend void goodgg::visit2();//��Ա��������Ԫ
public:
	Home() {
		m_sittingroom = "����";
		m_bedroom = "����";
		cout << "�޲ι���" << endl;
	}
	string m_sittingroom;
	
private:
	string m_bedroom;
};

//ȫ�ֺ���
void goodguy(Home* home)
{
	cout << "�û���ȫ�ֺ������ڷ��ʣ�" << home->m_sittingroom << endl;
	cout << "�û���ȫ�ֺ������ڷ��ʣ�" << home->m_bedroom << endl;
}

goodgg::goodgg() 
{
	//����home
	home = new Home;
}
void goodgg::visit()
{
	cout << "�û���ȫ�ֺ������ڷ��ʣ�" << home->m_sittingroom << endl;
	//cout << "�û���ȫ�ֺ������ڷ��ʣ�" << home->m_bedroom << endl;
}
void goodgg::visit2()
{
	cout << "�û���ȫ�ֺ������ڷ��ʣ�" << home->m_sittingroom << endl;
	cout << "�û���ȫ�ֺ������ڷ��ʣ�" << home->m_bedroom << endl;
}
int main5()
{
	test();
	testt();
	Person1 p;
	p.showPerson();
	const Person1 p1;
	//p1.aaa();���ó������Ƿ�
	Home home;
	goodguy(&home);
	goodgg gg;
	gg.visit();
	gg.visit2();
	system("pause");
	return 0;
}