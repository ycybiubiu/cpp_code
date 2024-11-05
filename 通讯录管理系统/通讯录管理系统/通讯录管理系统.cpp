#include <iostream>
using namespace std;
#include <string>
#define MAX 100
//菜单界面
void showMenu()
{
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、推出通讯录  *****" << endl;
}
//联系人结构体
struct Person {
	//姓名
	string name;
	//性别
	int sex;
	//年龄
	int age;
	//电话
	string phone_number;
	//住址
	string address;
};
//通讯录结构体
struct Addressbook {
	//联系人数组
	struct Person personArray[MAX];
	//联系人个数
	int member_size = 0;
};
//添加联系人
void addPerson(Addressbook* ads)
{
	if (ads->member_size == MAX)
	{
		cout << "通讯录已满，无法添加联系人！" << endl;
		return;
	}
	else
	{
		//添加联系人
		//姓名
		string person_name;
		cout << "请输入姓名：" << endl;
		cin >> person_name;
		ads->personArray[ads->member_size].name = person_name;
		//性别
		cout << "请输入性别：" << endl;
		cout << "1 ——— 男" << endl;
		cout << "2 ——— 女" << endl;
		int sex = 0;
		while (true)
		{
			//输入1或2退出循环，如果输入有误则重新输入
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				ads->personArray[ads->member_size].sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		ads->personArray[ads->member_size].age = age;
		//电话
		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		ads->personArray[ads->member_size].phone_number = phone;
		//地址
		cout << "请输入地址：" << endl;
		string address;
		cin >> address;
		ads->personArray[ads->member_size].address = address;
		//更新通讯录人数
		ads->member_size++;

		cout << "添加成功！" << endl;
		system("pause");
		system("cls");//清屏
	}
}
void showPerson(Addressbook* ads)
{
	//判断通讯录人数是否为0，如果为0提示为空，否则显示
	if (ads->member_size == 0)
	{
		cout << "当前记录为空！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		for (int i = 0; i < ads->member_size; i++)
		{
			cout << "姓名：" << ads->personArray[i].name << " \t";
			cout << "年龄：" << ads->personArray[i].age << " \t";
			cout << "性别：" << (ads->personArray[i].sex == 1 ? "男" : "女") << " \t";
			cout << "电话：" << ads->personArray[i].phone_number << " \t";
			cout << "地址：" << ads->personArray[i].address << endl;

		}
		system("pause");
		system("cls");
	}
}
//检测联系人是否存在，存在返回数组位置，否则返回-1
int detectPerson(Addressbook* ads, string name)
{
	for (int i = 0; i < ads->member_size; i++)
	{
		if (ads->personArray[i].name == name)
		{
			return i;
		}
	}
	return -1;
}
//删除联系人，先检测后删除
void delectPerson(Addressbook* ads)
{
	cout << "请输入您要删除的联系人" << endl;
	string name;
	cin >> name;
	int idx = detectPerson(ads, name);
	if (idx != -1)
	{
		for (int i = idx; i < ads->member_size; i++)
		{
			ads->personArray[i] = ads->personArray[i + 1];
			//cout << "迁移后数据：" << ads->personArray[i+1].name << endl;
		}
		ads->member_size -= 1;
		cout << "删除成功！" << endl;
	}
	else
	{
		cout << "查无此人！" << endl;
	}
	system("pause");
	system("cls");
}
//查找联系人，先检测后显示
void searchPerson(Addressbook* ads)
{
	cout << "请输入您要查找的联系人：" << endl;
	string search_name;
	cin >> search_name;
	int idx = detectPerson(ads, search_name);
	if (idx != -1)
	{
		cout << "姓名：" << ads->personArray[idx].name << " \t";
		cout << "年龄：" << ads->personArray[idx].age << " \t";
		cout << "性别：" << (ads->personArray[idx].sex == 1 ? "男" : "女") << " \t";
		cout << "电话：" << ads->personArray[idx].phone_number << " \t";
		cout << "地址：" << ads->personArray[idx].address << endl;
	}
	else
	{
		cout << "查无此人！" << endl;
	}
	system("pause");
	system("cls");
}
//修改指定联系人信息
void modifyPerson(Addressbook* ads)
{
	cout << "请输入您要修改的联系人：" << endl;
	string search_name;
	cin >> search_name;
	int idx = detectPerson(ads, search_name);
	if (idx != -1)
	{
		//姓名
		string modify_name;
		cout << "请输入姓名：" << endl;
		cin >> modify_name;
		ads->personArray[idx].name = modify_name;
		//性别
		cout << "请输入性别：" << endl;
		cout << "1 ——— 男" << endl;
		cout << "2 ——— 女" << endl;
		int sex = 0;
		while (true)
		{
			//输入1或2退出循环，如果输入有误则重新输入
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				ads->personArray[idx].sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		ads->personArray[idx].age = age;
		//电话
		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		ads->personArray[idx].phone_number = phone;
		//地址
		cout << "请输入地址：" << endl;
		string address;
		cin >> address;
		ads->personArray[idx].address = address;
		cout << "修改成功！" << endl;
	}
	else
	{
		cout << "查无此人！" << endl;
	}
	system("pause");
	system("cls");
}
void cleanPerson(Addressbook* ads)
{
	ads->member_size = 0;//将当期记录联系人数量置为0，做逻辑清空操作
	cout << "通讯录已经清空！" << endl;
	system("pause");
	system("cls");
}
int main()
{
	Addressbook ads;
	
	int select = 0;
	while (true)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1://添加联系人
			addPerson(&ads);//利用地址传递可以修改实参
			break;
		case 2://显示联系人
			showPerson(&ads);
			break;
		case 3://删除联系人
		{
			/*cout << "请输入删除联系人姓名：" << endl;
			string del_name;
			cin >> del_name;
			if (detectPerson(&ads, del_name) == -1)
			{
				cout << "查无此人" << endl;
			}*/
			delectPerson(&ads);
			break;
		}
		case 4://查找联系人
			searchPerson(&ads);
			break;
		case 5://修改联系人
			modifyPerson(&ads);
			break;
		case 6://清空联系人
			cleanPerson(&ads);
			break;
		case 0://退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	
	system("pause");
	return 0;
	
}