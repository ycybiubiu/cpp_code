#include<iostream>
using namespace std;
#include<string>
#include<fstream>

class Person
{
public:
	char m_Name[64];
	int m_Age;
};
void test03()
{
	//1、包含头文件
	//2、创建流对象
	ofstream ofs;

	//3、打开文件
	ofs.open("person.txt", ios::out | ios::binary);

	//4、写入文件
	Person p = { "张三",18 };
	ofs.write((const char*)&p, sizeof(Person));
	//5、关闭文件
	ofs.close();
}

int main3()
{

	test03();

	system("pause");
	return 0;
}