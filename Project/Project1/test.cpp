#include <iostream>
#include <string>
#include <ctime>
using namespace std;
#include "add.h"
void bubbleSort(int* arr, int len);
void printinfo(struct teacher tarr[], int len);
void allocateSpace(struct teacher tarr[], int len); 
void swap(int *p1, int *p2)
{
	cout <<"swap����ǰ��" << *p1 << " " << *p2 << endl;
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
	cout << "swap������" << *p1 << " " << *p2 << endl;
}
void swap01(int a, int b)
{
	cout << "swap01����ǰ��" << a << " " << b << endl;
	int temp = a;
	a = b;
	b = temp;
	cout << "swap01������" << a << " " << b << endl;
}
struct girl 
{
	int height;
	int weight;
	string cup;
};
struct student {
	string sname;
	int age;
	int score;
};
struct teacher {
	string tname;
	struct student stuarr[5];
};

int main()
{

	/*char b = 'a';
	char c[] = "abcd";
	string d = "abab";
	int a = 21;
	cout << "hello world, a=" << a << endl;
	cout << "bool������ռ�ռ䣺 " << sizeof(bool) << endl;
	cout << sizeof(a) << endl;
	cout << b << " " << sizeof(b) << endl;
	cout << c << " " << sizeof(c) << endl;
	cout << d << " " << sizeof(d) << endl;
	cout << a << endl;*/

	/*while (1)
	{
		
		cout << "������һ������";
		cin >> a;
		cout << (a > b ? a : b) << endl;
		if (a < 20)
		{
			cout << "��̫С��" << endl;
		}
		else if (a > 30)
		{
			if (a > 50)
			{
				cout << "�㳬����" << endl;
			}
			else
			{
				cout << "��̫����" << endl;
			}
		}
		else
		{
			cout << "�����С" << endl;
		}

	}*/

	/*cout << "�����Ӱ��֣�";
	cin >> a;
	switch (a)
	{
	case 10:
		cout << "����Ϊ���Ǿ����Ӱ" << endl;
		break;
	case 9:
		cout << "����Ϊ���Ǿ����Ӱ" << endl;
		break;
	case 8:
		cout << "����Ϊ���Ӱ�ǳ���" << endl;
		break;
	case 7:
		cout << "����Ϊ���Ӱ�ǳ���" << endl;
		break;
	case 6:
		cout << "����Ϊ���Ӱһ��" << endl;
		break;
	case 5:
		cout << "����Ϊ���Ӱһ��" << endl;
		break;
	default:
		cout << "����Ϊ������Ƭ" << endl;
	}*/

	/*srand((unsigned int)time(NULL));
	int answer = rand() % 100;
	int input = 0;
	while (input != answer)
	{
		cout << "��������µ����֣�";
		cin >> input;
		if (input < answer)
		{
			cout << "��С��" << endl;
		}
		else
		{
			cout << "�´���" << endl;
		}
	}
	cout << "��ϲ�㣬�¶���" << endl;*/

	/*cout << "���100-999��ˮ�ɻ�����" << endl;
	int num = 100;
	int h = 0;
	int t = 0;
	int g = 0;
	do
	{
		h = num / 100;
		t = num % 100 / 10;
		g = num % 10;
		if (h * h * h + t * t * t + g * g * g == num)
		{
			cout << num << endl;
		}
		num++;
	} 
	while (num <= 999);

	for (int i = 0; i < 100; i++)
	{
		if (i > 10)
		{
			continue;
		}
		cout << i << endl;
		if (i > 10)
		{
			break;
		}
	}*/
	//ð��
	/*int arr1[5];
	int arr2[5] = { 1,2,3,4,5 };
	int arr3[] = { 1,2,3,4,5,6,7,8,9 };
	cout << arr3[8] << endl;
	cout << sizeof(arr2) << endl;
	cout << arr1 << endl <<&arr1[0] << endl;

	int arr4[] = { 3,5,1,8,9,6,4,7,2 };
	for (int i = 0; i < sizeof(arr4) / sizeof(int); i++)
	{
		for (int j = 0; j < sizeof(arr4) / sizeof(int) - i - 1; j++)
		{
			int temp = arr4[j];
			if (arr4[j] > arr4[j + 1])
			{
				temp = arr4[j + 1];
				arr4[j + 1] = arr4[j];
				arr4[j] = temp;
			}
		}
	}
	for (int n = 0; n < sizeof(arr4) / sizeof(int); n++)
	{
		cout << arr4[n];
	}*/
	//int a = 0;
	//int b = 0;
	//cout << "a�ĵ�ַ��" << &a << endl;
	//cout << "b�ĵ�ַ��" << &b << endl;
	//int c = 0;
	//c = add(3, 4);
	//cout << c << endl;
	//cout << &(a > b ? a : b) << endl;
	//int arr[][3] = { 1,2,3,4,5,6 };
	//int* p;
	//p = &a;
	//*p = 1;
	//const int* d = &a;
	////*d = 1;
	//d = &b;
	//int* const e = &a;
	////e = &b;
	//*e = 2 ;
	//cout << a << " " << sizeof(p) << endl;

	/*int a = 1;
	int b = 2;
	int* p = &a;
	cout << &p << p << endl;

	cout << "swap01����ǰ��" << a << " " << b << endl;
	swap01(a, b);
	cout << "swap01������" << a << " " << b << endl;
	cout << "swap����ǰ��" << a << " " << b << endl;
	swap(&a, &b);
	cout << "swap������" << a << " " << b << endl;*/


	int arr[10] = { 6,1,5,4,7,3,9,2,8,10 };
	int len = sizeof(arr) / sizeof(int);
	bubbleSort(arr, len);
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << endl;
	}
	girl girlarr[3] =
	{
		{165,52,"Ccup"},
		{170,60,"Ecup"},
		{160,49,"Dcup"}
	};
	cout << girlarr<< girlarr[2].cup<< endl;
	girl lisa = { 168,55,"Dcup" };
	girl* p = &lisa;
	cout << p ->cup<< endl;

	srand((unsigned int)time(NULL));
	struct teacher tarr[3];
	int len1 = sizeof(tarr) / sizeof(tarr[0]);
	allocateSpace(tarr, len1);
	printinfo(tarr, len1);
	system("pause");
	return 0;
}
void allocateSpace(struct teacher tarr[], int len)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < len; i++)
	{
		tarr[i].tname = "teacher_";
		tarr[i].tname += nameSeed[i];
		for (int j = 0; j < 5; j++)
		{
			tarr[i].stuarr[j].sname = "student_";
			tarr[i].stuarr[j].sname += nameSeed[j];
			tarr[i].stuarr[j].score = rand() % 41 + 60;
		}
		
	}
}
void printinfo(struct teacher tarr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "��ʦ������" << tarr[i].tname << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << '\t'  << "ѧ��������" << tarr[i].stuarr[j].sname << "ѧ��������" << tarr[i].stuarr[j].score << endl;
		}
	}
}
void bubbleSort(int *arr, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			
		}
	}
}
