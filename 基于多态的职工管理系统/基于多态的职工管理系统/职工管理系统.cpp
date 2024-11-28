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
	worker = new Employee(1, "张三", 1);
	worker->ShowInfo();
	delete worker;
	worker = new Manager(2, "李四", 2);
	worker->ShowInfo();
	delete worker;
	worker = new Boss(3, "王五", 3);
	worker->ShowInfo();*/

	//实例化管理者对象
	WorkerManager wm;
	int choice = 0;
	while(true)
	{
		//显示菜单
		wm.ShowMenu();
		cout << "请输入您的选择：" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0://退出系统
			wm.ExitSystem();
			break;
		case 1://添加职工
			wm.Add_Emp();
			break;
		case 2://显示职工
			wm.ShowEmp();
			break;
		case 3://删除职工
		{
			wm.DelEmp();
			/*int ret = wm.IsEmpExist(20);
			if (ret != -1)
			{
				cout << "职工存在" << endl;
			}
			else
			{
				cout << "职工不存在" << endl;
			}*/
			break;
		}
		case 4://修改职工
			wm.ModifyEmp();
			break;
		case 5://查找职工
			wm.FindEmp();
			break;
		case 6://排序职工
			wm.SortEmp();
			break;
		case 7://清空文件
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