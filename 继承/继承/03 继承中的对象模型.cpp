#include<iostream>
using namespace std;

class Base2
{
public:
	int a;
protected:
	int b;
private:
	int c;
};
class Son :public Base2
{
public:
	int d;
};
//�鿴���������ÿ�������ʾ���߲鿴����ģ�ͣ���ת��cpp�ļ�·��
// ʹ������ ��cl /d1 reportSingleClassLayout���� �ļ������鿴
int main3() 
{
	//���������зǾ�̬��Ա���Զ��ᱻ����̳���ȥ
	cout << "size of Son: " << sizeof(Son) << endl;
	system("pause");
	return 0;
}