#include <iostream>
using namespace std;

class Person {
public:
    Person(int age) {
        m_age = new int(age); // �ڶ��Ϸ����ڴ�
    }

    ~Person() {
        // �ͷŶ��ϵ��ڴ�
        if (m_age != NULL) {
            delete m_age;
            m_age = NULL;
        }
    }

    int* m_age;
};

int main() {
    // ���� Person ���� p1��m_age �ڶ��Ϸ������ڴ�
    Person p1(int(18));

    // ��� p1 �� m_age ��ָ���ֵ
    cout << *p1.m_age << endl;

    system("pause");
    return 0;
}