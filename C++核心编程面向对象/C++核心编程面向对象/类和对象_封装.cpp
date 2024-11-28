#include <iostream>
#include <string>
using namespace std;
class Student {
public://访问权限
	//公共权限 public    类内可 类外可
	//保护权限 protected 类内可 类外否  子类可访父类保护内容
	//私有权限 private   类内可 类外否  子类不可访父类私有内容
	string name;
	string stu_number;

	void showinfo()
	{
		cout << "姓名：" << name << endl;
		cout << "学号：" << stu_number << endl;
	}
};

class Cube {
public:
	//设置长
	void set_long(int l)
	{
		m_long = l;
	}
	//获取长
	int get_long()
	{
		return m_long;
	}
	//设置宽
	void set_wight(int w)
	{
		m_wight = w;
	}
	//获取宽
	int get_wight()
	{
		return m_wight;
	}
	//设置高
	void set_height(int h)
	{
		m_height = h;
	}
	//获取高
	int get_height()
	{
		return m_height;
	}
	//计算表面积
	int calc_S()
	{
		return 2 * m_long * m_wight + 2 * m_long * m_height + 2 * m_wight * m_height;
	}
	//计算体积
	int calc_V()
	{
		return m_long * m_wight * m_height;
	}
private:
	int m_long;
	int m_wight;
	int m_height;
};
//	构造函数分类
//  1、按照参数分为无参和有参
//  2、按照类型分为普通和拷贝
class Person0 {
public:
	//无参
	Person0() {
		cout << "调用无参构造" << endl;
	}
	//有参
	Person0(int a, int height) {
		age = a;
		m_height = new int(height);
		cout << "调用有参构造" << endl;
	}
	//构造
	Person0(const Person0 &p) {
		age = p.age;
		//m_height = p.m_height;//默认拷贝构造的浅拷贝
		m_height = new int(*p.m_height);//深拷贝开辟新堆区
		cout << "调用拷贝构造" << endl;
	}
	//析构函数
	~Person0() {
		if (m_height != NULL)
		{
			delete m_height;
			m_height = NULL;
		}
		cout << "调用析构函数" << endl;
	}
	int age;
	int* m_height;
};
//调用构造函数
void test01() {
	//显示法
	Person0 p1;
	Person0 p2(10,160);
	Person0 p3(p2);
	//括号法
	Person0 p4 = Person0(100, 160);
	Person0 p5 = Person0(p4);//浅拷贝带来的问题是堆区数据重复释放
	//隐式法
	//Person p6 = 1000,160;
	//Person p7 = p6;
	//注意不能使用拷贝构造函数初始化匿名对象，编译器认为是对象声明
}
int main4()
{

	Student lisi;
	lisi.name = "李四";
	lisi.stu_number = "2024015423";
	lisi.showinfo();

	Cube c1;
	c1.set_height(10);
	c1.set_long(10);
	c1.set_wight(10);
	cout << "体积：" << c1.calc_V() << endl;
	cout << "面积：" << c1.calc_S() << endl; 
	test01();
	system("pause");
	return 0;

}