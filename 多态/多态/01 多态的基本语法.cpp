#include<iostream>
using namespace std;

class Animal
{
public:
	//虚函数
	virtual void speak()
	{
		cout << "动物在说话" << endl;
	}
};
class Cat :public Animal
{
public:
	void speak()
	{
		cout << "小猫在说话" << endl;
	}
};
//地址早绑定 在编译阶段就确定函数地址
//如果想执行让猫说话，那么这个函数就不能提前绑定，需要在运行阶段进行绑定，地址晚绑定
//动态多态首先须有继承关系，其次子类需重写父类虚函数
//动态多态使用需父类的指针或引用，指向子类对象
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