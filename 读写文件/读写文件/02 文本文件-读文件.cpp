#include<iostream>
using namespace std;
#include<fstream>
#include<string>
void test02()
{
	//1、包含头文件fstream
	//2、创建流对象
	ifstream ifs;
	//3、指定打开方式
	ifs.open("test.txt", ios::in);

	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	//4、读内容
	//第一种
	char buf[1024] = { 0 };
	while (ifs >> buf)
	{
		cout << buf << endl;
	}
	ifs.clear();             // 清除流状态（包括 EOF 状态）
	ifs.seekg(0, ios::beg);  // 将文件指针重新定位到文件开头
	//第二种
	while (ifs.getline(buf,sizeof(buf)))
	{
		cout << buf << endl;
	}
	ifs.clear();             // 清除流状态（包括 EOF 状态）
	ifs.seekg(0, ios::beg);  // 将文件指针重新定位到文件开头
	//第三种
	string str;
	while (getline(ifs, str))
	{
		cout << str << endl;
	}
	ifs.clear();             // 清除流状态（包括 EOF 状态）
	ifs.seekg(0, ios::beg);  // 将文件指针重新定位到文件开头
	//第四种
	char c;
	while ((c = ifs.get()) != EOF)
	{
		cout << c;
	}
	//5、关闭文件
	ifs.close();
}

int main2()
{
	test02();

	system("pause");
	return 0;
}