#include<iostream>
#include "workerManager.h"
#include "worker.h"
//#include "employee.h"
//#include "manager.h"
//#include "boss.h"
using namespace std;



int main()
{
	/*Worker * worker = NULL;
	worker = new Employee(1, "����", 1);
	worker->ShowInfo();
	delete worker;
	worker = new Manager(2, "����", 2);
	worker->ShowInfo();
	delete worker;
	worker = new Boss(3, "����", 3);
	worker->ShowInfo();*/

	//ʵ���������߶���
	WorkerManager wm;
	int choice = 0;
	while(true)
	{
		//��ʾ�˵�
		wm.ShowMenu();
		cout << "����������ѡ��" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0://�˳�ϵͳ
			wm.ExitSystem();
			break;
		case 1://���ְ��
			wm.Add_Emp();
			break;
		case 2://��ʾְ��
			wm.ShowEmp();
			break;
		case 3://ɾ��ְ��
		{
			wm.DelEmp();
			/*int ret = wm.IsEmpExist(20);
			if (ret != -1)
			{
				cout << "ְ������" << endl;
			}
			else
			{
				cout << "ְ��������" << endl;
			}*/
			break;
		}
		case 4://�޸�ְ��
			wm.ModifyEmp();
			break;
		case 5://����ְ��
			wm.FindEmp();
			break;
		case 6://����ְ��
			wm.SortEmp();
			break;
		case 7://����ļ�
			wm.CleanFile();
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}