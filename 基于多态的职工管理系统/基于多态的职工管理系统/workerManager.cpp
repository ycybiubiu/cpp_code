#include"workerManager.h"

WorkerManager::WorkerManager()
{
	//cout << this->m_FileIsEmpty << endl;
	//�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;
		//��ʼ������
		//��ʼ����¼����
		this->m_EmpNum = 0;
		//��ʼ������ָ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//�ļ����ڣ���û�м�¼
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ��" << endl;
		//��ʼ������
		//��ʼ����¼����
		this->m_EmpNum = 0;
		//��ʼ������ָ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//�ļ����ڣ����Ҽ�¼����
	int num = this->GetEmpNum();
	//cout << "����ְ������Ϊ��" << num << endl;
	this->m_EmpNum = num;
	//���ٿռ�
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//���ļ������ݴ浽������
	this->InitEmp();
	
	//���Դ���
	/*for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "ְ����ţ�" << this->m_EmpArray[i]->m_ID
		<< " ְ��������" << this->m_EmpArray[i]->m_Name
		<< " ְ����λ��ţ�" << this->m_EmpArray[i]->m_DeptID << endl;
	}*/
}
//չʾ�˵�
void WorkerManager::ShowMenu()
{
	cout << "**********************************************" << endl;
	cout << "************ ��ӭʹ��ְ������ϵͳ ************" << endl;
	cout << "*************** 0.�˳�������� ***************" << endl;
	cout << "*************** 1.����ְ����Ϣ ***************" << endl;
	cout << "*************** 2.��ʾְ����Ϣ ***************" << endl;
	cout << "*************** 3.ɾ����ְְ�� ***************" << endl;
	cout << "*************** 4.�޸�ְ����Ϣ ***************" << endl;
	cout << "*************** 5.����ְ����Ϣ ***************" << endl;
	cout << "*************** 6.���ձ������ ***************" << endl;
	cout << "*************** 7.��������ĵ� ***************" << endl;
	cout << "**********************************************" << endl;
	cout << endl;
}
//�˳�ϵͳ
void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);//�˳�����
}

//���ְ��
void WorkerManager::Add_Emp()
{
	cout << "���������ְ��������" << endl;
	int addNum = 0;//�����û���������
	cin >> addNum;
	if (addNum > 0)
	{
		//���
		//��������¿ռ��С
		int newSize = this->m_EmpNum + addNum;//�¿ռ��С=ԭ����¼����+��������

		//�����¿ռ�
		Worker** newSpace = new Worker* [newSize];

		//��ԭ���ռ������ݣ��������¿ռ�
		if(this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		
		//�������������
		for (int i = 0; i < addNum; i++)
		{
			int id;//ְ�����
			string name;//ְ������
			int dSelect;//����ѡ��
			cout << "�������" << i + 1 << "����ְ����ţ�" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ��������" << endl;
			cin >> name;
			cout << "��ѡ���ְ����λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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
			//��������ְ��ָ�룬���浽������
			newSpace[this->m_EmpNum + i] = worker;
		}
		//�ͷ�ԭ�пռ�
		delete[]this->m_EmpArray;

		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;

		//�����µ�ְ������
		this->m_EmpNum = newSize;

		//��ʾ��ӳɹ�
		cout << "�ɹ����" << addNum << "����ְ��" << endl;

		//�������ݵ��ļ���
		this->SaveEmpFile();

		//�����ļ��Ƿ�Ϊ�յı�־
		this->m_FileIsEmpty = false;
	}
	else
	{
		cout << "������������" << endl;
	}
	
	//��������������ص��ϼ�Ŀ¼
	system("pause");
	system("cls");
}

//�����ļ�
void WorkerManager::SaveEmpFile()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out); //������ķ�ʽ���ļ���д�ļ�
	//��ÿ���˵�����д���ļ�
	for (int i = 0; i<this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_ID << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptID << endl;
	}
	ofs.close();
}

//ͳ��ְ������
int WorkerManager::GetEmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ� 
	int id;
	string name;
	int dID;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dID)
	{
		//ͳ������
		num++;
	}
	ifs.close();
	return num;
}
//��ʼ��Ա��
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
		if (dID == 1)//��ְͨ��
		{
			worker = new Employee(id, name, dID);
		}
		else if (dID == 2)//����
		{
			worker = new Manager(id, name, dID);
		}
		else if (dID == 3)//�ϰ�
		{
			worker = new Boss(id, name, dID);
		}
		this->m_EmpArray[index++] = worker;
	}
	ifs.close();
}

//��ʾְ����Ϣ
void WorkerManager::ShowEmp()
{
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty || this->m_EmpNum == 0)
	{
		cout << "��׼����ʾְ����Ϣ�����ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//���ö�̬���ó���ӿ�
			this->m_EmpArray[i]->ShowInfo();
		}
	}
	//�����������
	system("pause");
	system("cls");
}

//ɾ��ְ��
void WorkerManager::DelEmp()
{
	if(this->m_FileIsEmpty)
	{
		cout << "��׼��ɾ��ְ����Ϣ�����ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		//����ְ�����ɾ��
		cout << "����������ɾ����Ա����ţ�" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsEmpExist(id);
		if (index != -1)//ְ�����ڣ���Ҫɾ��
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				//����ǰ��
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;//���������¼������
			//����ͬ�����µ��ļ���
			this->SaveEmpFile();
			if (this->m_EmpNum == 0)
			{
				this->m_FileIsEmpty = true;
			}
			cout << "ɾ���ɹ���" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}
	}
	system("pause");
	system("cls");
}

//�ж�Ա���Ƿ����
int WorkerManager::IsEmpExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if(this->m_EmpArray[i]->m_ID == id)
		{
			//�ҵ�ְ��
			index = i;
			break;
		}
	}
	return index;
}

//�޸�ְ����Ϣ
void WorkerManager::ModifyEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "��׼���޸�ְ����Ϣ�����ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������Ҫ�޸ĵ�ְ����ţ�" << endl;
		int id;
		cin >> id;
		int ret = this->IsEmpExist(id);
		if (ret != -1)
		{
			//���ҵ��ñ�Ŷ�Ӧ��ְ��
			delete this->m_EmpArray[ret];

			int newID = 0;
			string newName = "";
			int dSelect = 0;

			cout << "�鵽��" << id << "��ְ�����������µ�ְ����ţ�" << endl;
			cin >> newID;

			cout << "�������µ�ְ��������" << endl;
			cin >> newName;

			cout << "�������µĸ�λ��ţ�" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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
			// �������ݵ�������
			this->m_EmpArray[ret] = worker;
			cout << "�޸ĳɹ���" << endl;
			//���浽�ļ���
			this->SaveEmpFile();
		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴��ˣ�" << endl;
		}
	}
	system("pause");
	system("cls");
}

//����ְ��
void WorkerManager::FindEmp()
{
	if (this->m_FileIsEmpty) 
	{
		cout << "��׼������ְ����Ϣ�����ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		cout << "��ѡ����ҵķ�ʽ��" << endl;
		cout << "1����ְ����Ų��� " << endl;
		cout << "2����ְ���������� " << endl;
		int select;
		cin >> select;
		if (select == 1)
		{
			//���ձ�Ų�
			int id;
			cout << "������Ҫ���ҵ�Ա����ţ�" << endl;
			cin >> id;

			int ret = this->IsEmpExist(id);
			if (ret != -1)
			{
				//���д���
				cout << "��Ҫ���ҵ�ְ����Ϣ���£�" << endl;
				this->m_EmpArray[ret]->ShowInfo();
			}
			else
			{
				cout << "���޴��ˣ�" << endl;
			}
		}
		else if (select == 2)
		{
			//����������
			string name;
			cout << "������Ҫ���ҵ�Ա��������" << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "��Ҫ���ҵ�ְ����Ϣ���£�" << endl;
					this->m_EmpArray[i]->ShowInfo();
					flag = true;
				}
			}
			if(flag==false)
			{
				cout << "���޴��ˣ�" << endl;
			}
		}
		else
		{
			cout << "�����ѡ������" << endl;
		}
	}
	system("pause");
	system("cls");
}

//����ְ��
void WorkerManager::SortEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "��׼������ְ����Ϣ�����ļ������ڻ��߼�¼Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ķ�ʽ��" << endl;
		cout << "1����ְ������������� " << endl;
		cout << "2����ְ����Ž������� " << endl;
		int select;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int MinOrMax = i;//������Сֵ�����ֵ�±�
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
			//�ж����ֵ�±��Ƿ�һ�£���һ���򽻻�����
			if(i != MinOrMax)
			{
				Worker* tmp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[MinOrMax];
				this->m_EmpArray[MinOrMax] = tmp;
			}
		}
		cout << "����ɹ��������Ľ��Ϊ��" << endl;
		this->SaveEmpFile();
		this->ShowEmp();
	}
}

//����ļ�
void WorkerManager::CleanFile()
{
	cout << "�Ƿ�ȷ������ļ���" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;
	int select;
	cin >> select;

	if (select == 1)
	{
		//����ļ�
		ofstream ofs(FILENAME,ios::trunc);//ɾ���ļ������´���
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				//ɾ��������ÿ��ְ������
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
					this->m_EmpArray[i] = NULL;
				}
			}
			//ɾ����������ָ��
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "����ļ��ɹ���" << endl;
	}
	system("pause");
	system("cls");
}

//��������
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
		//cout << "����WorkerManager��������" << endl;
	}
}
