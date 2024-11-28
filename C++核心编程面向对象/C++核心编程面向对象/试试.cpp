#include <iostream>
using namespace std;

class Person {
public:
    Person(int age) {
        m_age = new int(age); // 在堆上分配内存
    }

    ~Person() {
        // 释放堆上的内存
        if (m_age != NULL) {
            delete m_age;
            m_age = NULL;
        }
    }

    int* m_age;
};

int main() {
    // 创建 Person 对象 p1，m_age 在堆上分配了内存
    Person p1(int(18));

    // 输出 p1 的 m_age 所指向的值
    cout << *p1.m_age << endl;

    system("pause");
    return 0;
}