#include<iostream>
using namespace std;

class Mammals
{
public:
	Mammals()
	{
		cout << "Mammals���캯������" << endl;
	}
	//�������������Խ������ָ���ͷ�������󲻸ɾ�������
	/*virtual ~Mammals()
	{
		cout << "Mammals��������������" << endl;
	}*/
	//������������Ҫ����Ҳ��Ҫʵ�֣����˴������������Ҳ���ڳ�����
	virtual ~Mammals() = 0;
	virtual void speak() = 0;
};
Mammals:: ~Mammals()
{
	cout << "Mammals����������������" << endl;
}
class Dog: public Mammals
{
public:
	Dog(string name)
	{
		cout << "Dog���캯������" << endl;
		m_name = new string(name);
	}
	~Dog()
	{
		if (m_name != NULL)
		{
			cout << "Dog������������" << endl;
			delete m_name;
			m_name = NULL;
		}
	}
	virtual void speak()
	{
		cout << *m_name << "С��������" << endl;
	}
	string* m_name;
};

void test05()
{
	Mammals* mammal = new Dog("Corgi");
	mammal->speak();
	//����ָ��������ʱ�򲻻�������������������������������ж������ݿ��ܻ��ڴ�й¶
	delete mammal;
}

int main5()
{
	test05();
	system("pause");
	return 0;
}