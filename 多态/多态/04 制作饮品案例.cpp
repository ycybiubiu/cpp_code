#include<iostream>
using namespace std;
//����������Ʒ
class AbstractDrinking
{
public:
	//��ˮ
	virtual void Boil() = 0;
	//����
	virtual void Brew() = 0;
	//���뱭��
	virtual void PourinCup() = 0;
	//���븨��
	virtual void AddSomething() = 0;
	void makedrink()
	{
		Boil();
		Brew();
		PourinCup();
		AddSomething();
	}
};
class Coffee:public AbstractDrinking
{
public:
	//��ˮ
	virtual void Boil() 
	{
		cout << "��д���ˮ" << endl;
	}
	//����
	virtual void Brew() 
	{
		cout << "���ݿ���" << endl;
	}
	//���뱭��
	virtual void PourinCup()
	{
		cout << "���뿧�ȱ�" << endl;
	}
	//���븨��
	virtual void AddSomething()
	{
		cout << "�������" << endl;
	}
};
class Tea :public AbstractDrinking
{
public:
	//��ˮ
	virtual void Boil()
	{
		cout << "���ũ��ɽȪ" << endl;
	}
	//����
	virtual void Brew()
	{
		cout << "���ݲ�Ҷ" << endl;
	}
	//���뱭��
	virtual void PourinCup()
	{
		cout << "����豭" << endl;
	}
	//���븨��
	virtual void AddSomething()
	{
		cout << "�������" << endl;
	}
};
void doWork(AbstractDrinking * abs)
{
	abs->makedrink();
	delete abs;
}
void test04()
{
	doWork(new Coffee);
	cout << "------------���Ƿָ���------------" << endl;
	doWork(new Tea);
}

int main4()
{

	test04();
	system("pause");
	return 0;
}