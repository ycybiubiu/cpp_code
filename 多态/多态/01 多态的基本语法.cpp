#include<iostream>
using namespace std;

class Animal
{
public:
	//�麯��
	virtual void speak()
	{
		cout << "������˵��" << endl;
	}
};
class Cat :public Animal
{
public:
	void speak()
	{
		cout << "Сè��˵��" << endl;
	}
};
//��ַ��� �ڱ���׶ξ�ȷ��������ַ
//�����ִ����è˵������ô��������Ͳ�����ǰ�󶨣���Ҫ�����н׶ν��а󶨣���ַ���
//��̬��̬�������м̳й�ϵ�������������д�����麯��
//��̬��̬ʹ���踸���ָ������ã�ָ���������
void doSpeak(Animal &animal)
{
	animal.speak();
}



int main1()
{
	Cat cat;
	doSpeak(cat);
	cout << "sizeof Animal: " << sizeof(Animal) << endl;
	system("pause");
	return 0;
}