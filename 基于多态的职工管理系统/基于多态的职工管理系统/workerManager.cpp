#include"workerManager.h"

WorkerManager::WorkerManager()
{
	//cout << this->m_FileIsEmpty << endl;
	//文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;
		//初始化属性
		//初始化记录人数
		this->m_EmpNum = 0;
		//初始化数组指针
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件存在，但没有记录
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空" << endl;
		//初始化属性
		//初始化记录人数
		this->m_EmpNum = 0;
		//初始化数组指针
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件存在，并且记录数据
	int num = this->GetEmpNum();
	//cout << "现有职工人数为：" << num << endl;
	this->m_EmpNum = num;
	//开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//将文件的数据存到数组中
	this->InitEmp();
	
	//测试代码
	/*for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "职工编号：" << this->m_EmpArray[i]->m_ID
		<< " 职工姓名：" << this->m_EmpArray[i]->m_Name
		<< " 职工岗位编号：" << this->m_EmpArray[i]->m_DeptID << endl;
	}*/
}
//展示菜单
void WorkerManager::ShowMenu()
{
	cout << "**********************************************" << endl;
	cout << "************ 欢迎使用职工管理系统 ************" << endl;
	cout << "*************** 0.退出管理程序 ***************" << endl;
	cout << "*************** 1.增加职工信息 ***************" << endl;
	cout << "*************** 2.显示职工信息 ***************" << endl;
	cout << "*************** 3.删除离职职工 ***************" << endl;
	cout << "*************** 4.修改职工信息 ***************" << endl;
	cout << "*************** 5.查找职工信息 ***************" << endl;
	cout << "*************** 6.按照编号排序 ***************" << endl;
	cout << "*************** 7.清空所有文档 ***************" << endl;
	cout << "**********************************************" << endl;
	cout << endl;
}
//退出系统
void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);//退出程序
}

//添加职工
void WorkerManager::Add_Emp()
{
	cout << "请输入添加职工数量：" << endl;
	int addNum = 0;//保存用户输入数量
	cin >> addNum;
	if (addNum > 0)
	{
		//添加
		//计算添加新空间大小
		int newSize = this->m_EmpNum + addNum;//新空间大小=原来记录人数+新增人数

		//开辟新空间
		Worker** newSpace = new Worker* [newSize];

		//将原来空间下数据，拷贝到新空间
		if(this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		
		//批量添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;//职工编号
			string name;//职工姓名
			int dSelect;//部门选择
			cout << "请输入第" << i + 1 << "个新职工编号：" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工姓名：" << endl;
			cin >> name;
			cout << "请选择该职工岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch(dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//将创建的职工指针，保存到数组中
			newSpace[this->m_EmpNum + i] = worker;
		}
		//释放原有空间
		delete[]this->m_EmpArray;

		//更改新空间的指向
		this->m_EmpArray = newSpace;

		//更新新的职工人数
		this->m_EmpNum = newSize;

		//提示添加成功
		cout << "成功添加" << addNum << "名新职工" << endl;

		//保存数据到文件中
		this->SaveEmpFile();

		//更新文件是否为空的标志
		this->m_FileIsEmpty = false;
	}
	else
	{
		cout << "输入数据有误！" << endl;
	}
	
	//按任意键后清屏回到上级目录
	system("pause");
	system("cls");
}

//保存文件
void WorkerManager::SaveEmpFile()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out); //用输出的方式打开文件，写文件
	//将每个人的数据写入文件
	for (int i = 0; i<this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_ID << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptID << endl;
	}
	ofs.close();
}

//统计职工数量
int WorkerManager::GetEmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//打开文件 
	int id;
	string name;
	int dID;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dID)
	{
		//统计人数
		num++;
	}
	ifs.close();
	return num;
}
//初始化员工
void WorkerManager::InitEmp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dID;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dID)
	{
		Worker* worker = NULL;
		if (dID == 1)//普通职工
		{
			worker = new Employee(id, name, dID);
		}
		else if (dID == 2)//经理
		{
			worker = new Manager(id, name, dID);
		}
		else if (dID == 3)//老板
		{
			worker = new Boss(id, name, dID);
		}
		this->m_EmpArray[index++] = worker;
	}
	ifs.close();
}

//显示职工信息
void WorkerManager::ShowEmp()
{
	//判断文件是否为空
	if (this->m_FileIsEmpty || this->m_EmpNum == 0)
	{
		cout << "您准备显示职工信息，但文件不存在或者记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//利用多态调用程序接口
			this->m_EmpArray[i]->ShowInfo();
		}
	}
	//按任意键清屏
	system("pause");
	system("cls");
}

//删除职工
void WorkerManager::DelEmp()
{
	if(this->m_FileIsEmpty)
	{
		cout << "您准备删除职工信息，但文件不存在或者记录为空" << endl;
	}
	else
	{
		//按照职工编号删除
		cout << "请输入你想删除的员工编号：" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsEmpExist(id);
		if (index != -1)//职工存在，需要删除
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				//数据前移
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;//更新数组记录的人数
			//数据同步更新到文件中
			this->SaveEmpFile();
			if (this->m_EmpNum == 0)
			{
				this->m_FileIsEmpty = true;
			}
			cout << "删除成功！" << endl;
		}
		else
		{
			cout << "删除失败，未找到该职工" << endl;
		}
	}
	system("pause");
	system("cls");
}

//判断员工是否存在
int WorkerManager::IsEmpExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if(this->m_EmpArray[i]->m_ID == id)
		{
			//找到职工
			index = i;
			break;
		}
	}
	return index;
}

//修改职工信息
void WorkerManager::ModifyEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "您准备修改职工信息，但文件不存在或者记录为空" << endl;
	}
	else
	{
		cout << "请输入需要修改的职工编号：" << endl;
		int id;
		cin >> id;
		int ret = this->IsEmpExist(id);
		if (ret != -1)
		{
			//查找到该编号对应的职工
			delete this->m_EmpArray[ret];

			int newID = 0;
			string newName = "";
			int dSelect = 0;

			cout << "查到：" << id << "号职工，请输入新的职工编号：" << endl;
			cin >> newID;

			cout << "请输入新的职工姓名：" << endl;
			cin >> newName;

			cout << "请输入新的岗位编号：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newID, newName, 1);
				break;
			case 2:
				worker = new Manager(newID, newName, 2);
				break;
			case 3:
				worker = new Boss(newID, newName, 3);
				break;
			default:
				break;
			}
			// 更新数据到数组中
			this->m_EmpArray[ret] = worker;
			cout << "修改成功！" << endl;
			//保存到文件中
			this->SaveEmpFile();
		}
		else
		{
			cout << "修改失败，查无此人！" << endl;
		}
	}
	system("pause");
	system("cls");
}

//查找职工
void WorkerManager::FindEmp()
{
	if (this->m_FileIsEmpty) 
	{
		cout << "您准备查找职工信息，但文件不存在或者记录为空" << endl;
	}
	else
	{
		cout << "请选择查找的方式：" << endl;
		cout << "1、按职工编号查找 " << endl;
		cout << "2、按职工姓名查找 " << endl;
		int select;
		cin >> select;
		if (select == 1)
		{
			//按照编号查
			int id;
			cout << "请输入要查找的员工编号：" << endl;
			cin >> id;

			int ret = this->IsEmpExist(id);
			if (ret != -1)
			{
				//查有此人
				cout << "您要查找的职工信息如下：" << endl;
				this->m_EmpArray[ret]->ShowInfo();
			}
			else
			{
				cout << "查无此人！" << endl;
			}
		}
		else if (select == 2)
		{
			//按照姓名查
			string name;
			cout << "请输入要查找的员工姓名：" << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "您要查找的职工信息如下：" << endl;
					this->m_EmpArray[i]->ShowInfo();
					flag = true;
				}
			}
			if(flag==false)
			{
				cout << "查无此人！" << endl;
			}
		}
		else
		{
			cout << "输入的选项有误！" << endl;
		}
	}
	system("pause");
	system("cls");
}

//排序职工
void WorkerManager::SortEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "您准备排序职工信息，但文件不存在或者记录为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序的方式：" << endl;
		cout << "1、按职工编号升序排列 " << endl;
		cout << "2、按职工编号降序排列 " << endl;
		int select;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int MinOrMax = i;//声明最小值或最大值下标
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)
				{
					if (this->m_EmpArray[MinOrMax]->m_ID > this->m_EmpArray[j]->m_ID)
					{
						MinOrMax = j;
					}
				}
				else
				{
					if (this->m_EmpArray[MinOrMax]->m_ID < this->m_EmpArray[j]->m_ID)
					{
						MinOrMax = j;
					}
				}
			}
			//判断最大值下标是否一致，不一致则交换数据
			if(i != MinOrMax)
			{
				Worker* tmp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[MinOrMax];
				this->m_EmpArray[MinOrMax] = tmp;
			}
		}
		cout << "排序成功，排序后的结果为：" << endl;
		this->SaveEmpFile();
		this->ShowEmp();
	}
}

//清空文件
void WorkerManager::CleanFile()
{
	cout << "是否确定清空文件？" << endl;
	cout << "1、确定" << endl;
	cout << "2、返回" << endl;
	int select;
	cin >> select;

	if (select == 1)
	{
		//清空文件
		ofstream ofs(FILENAME,ios::trunc);//删除文件后重新创建
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				//删除堆区的每个职工对象
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
					this->m_EmpArray[i] = NULL;
				}
			}
			//删除堆区数据指针
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "清空文件成功！" << endl;
	}
	system("pause");
	system("cls");
}

//析构函数
WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
		//cout << "调用WorkerManager析构函数" << endl;
	}
}
