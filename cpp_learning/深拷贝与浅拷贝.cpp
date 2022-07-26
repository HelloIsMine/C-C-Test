//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	int m_Age;
//	int* m_Height;
//	Person()
//	{
//		cout << "默认无参构造函数" << endl;
//	}
//	Person(int age, int height)
//	{
//		m_Age = age;
//		m_Height = new int(height);
//	}
//	Person(const Person& p)
//	{
//		m_Age = p.m_Age;
//		m_Height = new int(*p.m_Height);
//	}
//	~Person()
//	{
//		delete m_Height;
//		m_Height = NULL;
//		cout << "析构函数调用" << endl;
//	}
//
//};
//void test01()
//{
//	Person p1(10, 170);
//	cout << "p1的age: " << p1.m_Age << "p1的height：" << p1.m_Height << endl;
//	Person p2 = p1;
//	cout << "p2的age: " << p2.m_Age << "p2的height：" << p2.m_Height << endl;
//}
//int main()
//{
//	test01();
//	return 0;
//}