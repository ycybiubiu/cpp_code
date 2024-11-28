#include<iostream>
using namespace std;
#include<string>
#include<fstream>

class Personr
{
public:
	char m_Name[64];
	int m_Age;
};
void test04()
{
	//1、包含头文件
	//2、创建流对象
	ifstream ifs;

	//3、打开文件
	ifs.open("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	//4、读文件
	Personr pr;
	ifs.read((char*)&pr, sizeof(Personr));
	cout << "姓名：" << pr.m_Name << endl<< "年龄：" << pr.m_Age << endl;
	//5、关闭文件
	ifs.close();
}

int main()
{

	test04();

	system("pause");
	return 0;
}