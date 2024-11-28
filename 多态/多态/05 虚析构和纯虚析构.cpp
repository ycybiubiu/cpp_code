#include<iostream>
using namespace std;

class Mammals
{
public:
	Mammals()
	{
		cout << "Mammals构造函数调用" << endl;
	}
	//利用虚析构可以解决父类指针释放子类对象不干净的问题
	/*virtual ~Mammals()
	{
		cout << "Mammals虚析构函数调用" << endl;
	}*/
	//纯虚析构，需要声明也需要实现，有了纯虚析构这个类也属于抽象类
	virtual ~Mammals() = 0;
	virtual void speak() = 0;
};
Mammals:: ~Mammals()
{
	cout << "Mammals纯虚析构函数调用" << endl;
}
class Dog: public Mammals
{
public:
	Dog(string name)
	{
		cout << "Dog构造函数调用" << endl;
		m_name = new string(name);
	}
	~Dog()
	{
		if (m_name != NULL)
		{
			cout << "Dog析构函数调用" << endl;
			delete m_name;
			m_name = NULL;
		}
	}
	virtual void speak()
	{
		cout << *m_name << "小狗汪汪汪" << endl;
	}
	string* m_name;
};

void test05()
{
	Mammals* mammal = new Dog("Corgi");
	mammal->speak();
	//父类指针在析构时候不会调用子类中析构函数，导致子类若有堆区数据可能会内存泄露
	delete mammal;
}

int main5()
{
	test05();
	system("pause");
	return 0;
}