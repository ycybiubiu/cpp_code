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
//查看命名，利用开发者提示工具查看对象模型，跳转到cpp文件路径
// 使用命令 ‘cl /d1 reportSingleClassLayout类名 文件名’查看
int main3() 
{
	//父类中所有非静态成员属性都会被子类继承下去
	cout << "size of Son: " << sizeof(Son) << endl;
	system("pause");
	return 0;
}