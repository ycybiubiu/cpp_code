#include<iostream>
using namespace std;
class Base3
{
public:
	Base3() 
	{
		cout << "Base3���캯��" << endl;
	}
	~Base3() 
	{
		cout << "Base3��������" << endl;
	}
};
class Son3:public Base3
{
public:
	Son3()
	{
		cout << "Son3���캯��" << endl;
	}
	~Son3()
	{
		cout << "Son3��������" << endl;
	}
};
void test04() 
{
	//Base3 b3;
	Son3 s3;
}
int main4()
{
	//�̳��еĹ��������˳��Ϊ�ȹ��츸�࣬����������
	test04();
	system("pause");
	return 0;
}