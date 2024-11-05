#include <iostream>
#include <string>
using namespace std;
class Person
{
public:
	Person(int age)
	{
		//this指针指向的是被调用的成员函数所属的对象
		this->age = age;
	}

	Person& PersonAddage(Person& p)
	{
		/*if (this == NULL)
		{
			return;
		}*/
		this->age += p.age;
		return *this;
	}
	int age;
};
//1、解决名称冲突
void test()
{
	Person p1(18);
	cout << p1.age << endl;
}
//2、返回对象本身用*this
void testt() 
{
	Person p1(12);
	Person p2(10);
	//链式编程思想
	p2.PersonAddage(p1).PersonAddage(p1);
	cout << p2.age << endl;
}
//const修饰成员函数
//成员函数后加const成为常函数，常函数不可以修改成员属性，成员属性加关键字mutable 在常函数可修改
//对象声明前加const成为常对象，常对象只能调用常函数

class Person1 {
public:
	//在成员函数后面加const,修饰的是this指向，让指针指向的值也不可以修改
	void showPerson() const 
	{
		this->m_B=100;
		//this->m_A=100;
	}
	void aaa() {
	
	}
	int m_A;
	mutable int m_B;
};


//友元
class Home;
class goodgg
{
public:
	goodgg();
	void visit();
	void visit2();
	Home* home;
};
class Home
{
	friend void goodguy(Home* home);//全局函数是Home的好朋友可以访问私有成员
	//friend class goodgg;//类做友元
	friend void goodgg::visit2();//成员函数做友元
public:
	Home() {
		m_sittingroom = "客厅";
		m_bedroom = "卧室";
		cout << "无参构造" << endl;
	}
	string m_sittingroom;
	
private:
	string m_bedroom;
};

//全局函数
void goodguy(Home* home)
{
	cout << "好基友全局函数正在访问：" << home->m_sittingroom << endl;
	cout << "好基友全局函数正在访问：" << home->m_bedroom << endl;
}

goodgg::goodgg() 
{
	//创建home
	home = new Home;
}
void goodgg::visit()
{
	cout << "好基友全局函数正在访问：" << home->m_sittingroom << endl;
	//cout << "好基友全局函数正在访问：" << home->m_bedroom << endl;
}
void goodgg::visit2()
{
	cout << "好基友全局函数正在访问：" << home->m_sittingroom << endl;
	cout << "好基友全局函数正在访问：" << home->m_bedroom << endl;
}
int main5()
{
	test();
	testt();
	Person1 p;
	p.showPerson();
	const Person1 p1;
	//p1.aaa();调用常函数非法
	Home home;
	goodguy(&home);
	goodgg gg;
	gg.visit();
	gg.visit2();
	system("pause");
	return 0;
}