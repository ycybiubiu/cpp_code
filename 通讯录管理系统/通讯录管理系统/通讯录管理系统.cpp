#include <iostream>
using namespace std;
#include <string>
#define MAX 100
//�˵�����
void showMenu()
{
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���Ƴ�ͨѶ¼  *****" << endl;
}
//��ϵ�˽ṹ��
struct Person {
	//����
	string name;
	//�Ա�
	int sex;
	//����
	int age;
	//�绰
	string phone_number;
	//סַ
	string address;
};
//ͨѶ¼�ṹ��
struct Addressbook {
	//��ϵ������
	struct Person personArray[MAX];
	//��ϵ�˸���
	int member_size = 0;
};
//�����ϵ��
void addPerson(Addressbook* ads)
{
	if (ads->member_size == MAX)
	{
		cout << "ͨѶ¼�������޷������ϵ�ˣ�" << endl;
		return;
	}
	else
	{
		//�����ϵ��
		//����
		string person_name;
		cout << "������������" << endl;
		cin >> person_name;
		ads->personArray[ads->member_size].name = person_name;
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1 ������ ��" << endl;
		cout << "2 ������ Ů" << endl;
		int sex = 0;
		while (true)
		{
			//����1��2�˳�ѭ�������������������������
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				ads->personArray[ads->member_size].sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}
		//����
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		ads->personArray[ads->member_size].age = age;
		//�绰
		cout << "��������ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		ads->personArray[ads->member_size].phone_number = phone;
		//��ַ
		cout << "�������ַ��" << endl;
		string address;
		cin >> address;
		ads->personArray[ads->member_size].address = address;
		//����ͨѶ¼����
		ads->member_size++;

		cout << "��ӳɹ���" << endl;
		system("pause");
		system("cls");//����
	}
}
void showPerson(Addressbook* ads)
{
	//�ж�ͨѶ¼�����Ƿ�Ϊ0�����Ϊ0��ʾΪ�գ�������ʾ
	if (ads->member_size == 0)
	{
		cout << "��ǰ��¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		for (int i = 0; i < ads->member_size; i++)
		{
			cout << "������" << ads->personArray[i].name << " \t";
			cout << "���䣺" << ads->personArray[i].age << " \t";
			cout << "�Ա�" << (ads->personArray[i].sex == 1 ? "��" : "Ů") << " \t";
			cout << "�绰��" << ads->personArray[i].phone_number << " \t";
			cout << "��ַ��" << ads->personArray[i].address << endl;

		}
		system("pause");
		system("cls");
	}
}
//�����ϵ���Ƿ���ڣ����ڷ�������λ�ã����򷵻�-1
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
//ɾ����ϵ�ˣ��ȼ���ɾ��
void delectPerson(Addressbook* ads)
{
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	int idx = detectPerson(ads, name);
	if (idx != -1)
	{
		for (int i = idx; i < ads->member_size; i++)
		{
			ads->personArray[i] = ads->personArray[i + 1];
			//cout << "Ǩ�ƺ����ݣ�" << ads->personArray[i+1].name << endl;
		}
		ads->member_size -= 1;
		cout << "ɾ���ɹ���" << endl;
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}
	system("pause");
	system("cls");
}
//������ϵ�ˣ��ȼ�����ʾ
void searchPerson(Addressbook* ads)
{
	cout << "��������Ҫ���ҵ���ϵ�ˣ�" << endl;
	string search_name;
	cin >> search_name;
	int idx = detectPerson(ads, search_name);
	if (idx != -1)
	{
		cout << "������" << ads->personArray[idx].name << " \t";
		cout << "���䣺" << ads->personArray[idx].age << " \t";
		cout << "�Ա�" << (ads->personArray[idx].sex == 1 ? "��" : "Ů") << " \t";
		cout << "�绰��" << ads->personArray[idx].phone_number << " \t";
		cout << "��ַ��" << ads->personArray[idx].address << endl;
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}
	system("pause");
	system("cls");
}
//�޸�ָ����ϵ����Ϣ
void modifyPerson(Addressbook* ads)
{
	cout << "��������Ҫ�޸ĵ���ϵ�ˣ�" << endl;
	string search_name;
	cin >> search_name;
	int idx = detectPerson(ads, search_name);
	if (idx != -1)
	{
		//����
		string modify_name;
		cout << "������������" << endl;
		cin >> modify_name;
		ads->personArray[idx].name = modify_name;
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1 ������ ��" << endl;
		cout << "2 ������ Ů" << endl;
		int sex = 0;
		while (true)
		{
			//����1��2�˳�ѭ�������������������������
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				ads->personArray[idx].sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}
		//����
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		ads->personArray[idx].age = age;
		//�绰
		cout << "��������ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		ads->personArray[idx].phone_number = phone;
		//��ַ
		cout << "�������ַ��" << endl;
		string address;
		cin >> address;
		ads->personArray[idx].address = address;
		cout << "�޸ĳɹ���" << endl;
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}
	system("pause");
	system("cls");
}
void cleanPerson(Addressbook* ads)
{
	ads->member_size = 0;//�����ڼ�¼��ϵ��������Ϊ0�����߼���ղ���
	cout << "ͨѶ¼�Ѿ���գ�" << endl;
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
		case 1://�����ϵ��
			addPerson(&ads);//���õ�ַ���ݿ����޸�ʵ��
			break;
		case 2://��ʾ��ϵ��
			showPerson(&ads);
			break;
		case 3://ɾ����ϵ��
		{
			/*cout << "������ɾ����ϵ��������" << endl;
			string del_name;
			cin >> del_name;
			if (detectPerson(&ads, del_name) == -1)
			{
				cout << "���޴���" << endl;
			}*/
			delectPerson(&ads);
			break;
		}
		case 4://������ϵ��
			searchPerson(&ads);
			break;
		case 5://�޸���ϵ��
			modifyPerson(&ads);
			break;
		case 6://�����ϵ��
			cleanPerson(&ads);
			break;
		case 0://�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
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