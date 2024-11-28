#include<iostream>
using namespace std;

class Animal
{
public:
	int age;
	
};
//利益虚继承可以解决菱形继承的问题
//Animal则称为虚基类
class Sheep:virtual public Animal
{
public:

};
class Tuo :virtual public Animal
{
public:

};
class SheepTuo :public Sheep,public Tuo
{
public:

};

void test08()
{
	SheepTuo st;
	st.Sheep::age =18;
	st.Tuo::age = 28;
	//当菱形继承，两个父类拥有相同数据，需要加以作用域区分
	cout << "st.age = " << st.age << endl;
	cout << "st.Sheep::age = " << st.Sheep::age << endl;
	cout << "st.Tuo::age = " << st.Tuo::age << endl;
	//年龄只有一个，菱形继承导致数据有两份，资源浪费
}
int main()
{
	test08();
	system("pause");
	return 0;
}