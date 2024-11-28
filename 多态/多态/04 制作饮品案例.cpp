#include<iostream>
using namespace std;
//案例制作饮品
class AbstractDrinking
{
public:
	//煮水
	virtual void Boil() = 0;
	//冲泡
	virtual void Brew() = 0;
	//倒入杯中
	virtual void PourinCup() = 0;
	//加入辅料
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
	//煮水
	virtual void Boil() 
	{
		cout << "煮沸纯净水" << endl;
	}
	//冲泡
	virtual void Brew() 
	{
		cout << "冲泡咖啡" << endl;
	}
	//倒入杯中
	virtual void PourinCup()
	{
		cout << "倒入咖啡杯" << endl;
	}
	//加入辅料
	virtual void AddSomething()
	{
		cout << "加入厚乳" << endl;
	}
};
class Tea :public AbstractDrinking
{
public:
	//煮水
	virtual void Boil()
	{
		cout << "煮沸农夫山泉" << endl;
	}
	//冲泡
	virtual void Brew()
	{
		cout << "冲泡茶叶" << endl;
	}
	//倒入杯中
	virtual void PourinCup()
	{
		cout << "倒入茶杯" << endl;
	}
	//加入辅料
	virtual void AddSomething()
	{
		cout << "加入枸杞" << endl;
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
	cout << "------------我是分割线------------" << endl;
	doWork(new Tea);
}

int main4()
{

	test04();
	system("pause");
	return 0;
}