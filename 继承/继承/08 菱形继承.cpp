#include<iostream>
using namespace std;

class Animal
{
public:
	int age;
	
};
//������̳п��Խ�����μ̳е�����
//Animal���Ϊ�����
class Sheep:virtual public Animal
{
public:

};
class Tuo :virtual public Animal
{
public:

};
class SheepTuo :public Sheep,public Tuo
{
public:

};

void test08()
{
	SheepTuo st;
	st.Sheep::age =18;
	st.Tuo::age = 28;
	//�����μ̳У���������ӵ����ͬ���ݣ���Ҫ��������������
	cout << "st.age = " << st.age << endl;
	cout << "st.Sheep::age = " << st.Sheep::age << endl;
	cout << "st.Tuo::age = " << st.Tuo::age << endl;
	//����ֻ��һ�������μ̳е������������ݣ���Դ�˷�
}
int main()
{
	test08();
	system("pause");
	return 0;
}